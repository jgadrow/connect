#include <string>
#include <tchar.h>
#include <windowsx.h>
#include "../../../../include/os_dependent/windows/view/windows_view.h"
using std::to_string;

ViewImpl::ViewImpl (Board const & board)
    : _board (board)
{
    _input = false;
    _prev = "";

    HINSTANCE hInst = GetModuleHandle(NULL);
    TCHAR szWindowClass[] = _T("connect");
    WNDCLASSEX wcex;
    int nCmdShow = 1;

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = ViewImpl::WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInst;
    wcex.hIcon = LoadIcon(hInst, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

    if (!RegisterClassEx(&wcex))
    {
        MessageBox(NULL,
            _T("Call to RegisterClassEx failed!"),
            _T("Windows Desktop Guided Tour"),
            NULL
        );
    }

    // The parameters to CreateWindow explained:
    // szWindowClass: the name of the application
    // szTitle: the text that appears in the title bar
    // WS_OVERLAPPEDWINDOW: the type of window to create
    // CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)
    // 500, 100: initial size (width, length)
    // NULL: the parent of this window
    // NULL: this application dows not have a menu bar
    // hInstance: the first parameter from WinMain
    // NULL: not used in this application
    _hwnd = CreateWindow(
        szWindowClass,
        _T("Connect 4"),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        375,
        250,
        NULL,
        NULL,
        hInst,
        this
    );

    if (!_hwnd)
    {
        MessageBox(NULL,
            _T("Call to CreateWindow failed!"),
            _T("Windows Desktop Guided Tour"),
            NULL);
    }

    // The parameters to ShowWindow explained:
    // hWnd: the value returned from CreateWindow
    // nCmdShow: the fourth parameter from WinMain
    ShowWindow(_hwnd, nCmdShow);
    UpdateWindow(_hwnd);
}

void ViewImpl::Click(int x, int y)
{
    // Do nothing if cursor is out of bounds.
    if (y > 40 || y < 20 || x > 179 || x < 5)
    {
        return;
    }

    _prev.assign(to_string((x - 5) / 25 + 1));
    InvalidateRect(_hwnd, NULL, true);
}

void ViewImpl::DrawBoard () const
{
    PAINTSTRUCT ps;
    HDC hdc;
    TCHAR prompt[] = _T("Click on the column heading to choose where to play.");

    hdc = BeginPaint(_hwnd, &ps);
    TextOut(hdc, 5, 5, prompt, _tcslen(prompt));

    for (int i = 0; i < Board::height - 1; ++i)
    {
        MoveToEx(hdc, 5, 75 + (i * 25), NULL);
        LineTo(hdc, 5 + (25 * Board::width), 75 + (i * 25));
    }

    for (int i = 0; i < Board::width - 1; ++i)
    {
        MoveToEx(hdc, 30 + (i * 25), 50, NULL);
        LineTo(hdc, 30 + (i * 25), 50 + (25 * Board::height));
    }

    for (int i = 0; i < Board::height; ++i)
    {
        for (int j = 0; j < Board::width; ++j)
        {
            string str = to_string(j + 1);
            TextOut(hdc, 14 + (j * 25), 25, str.c_str(), str.length());

            char t = _board.GetToken(i, j);

            if (' ' == t)
            {
                continue;
            }

            char token[] = { t, '\0' };
            TextOut(hdc, 14 + (j * 25), 55 + (i * 25), token, 1);
        }
    }

    EndPaint(_hwnd, &ps);
}

string ViewImpl::PromptForInput() const
{
    MSG msg;
    _input = false;

    while (!_input && GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return _prev;
}

void ViewImpl::Update () const
{
    DrawBoard();
}

LRESULT CALLBACK ViewImpl::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    ViewImpl * pThis;

    if (msg == WM_NCCREATE)
    {
        pThis = static_cast<ViewImpl *>(reinterpret_cast<CREATESTRUCT*>(lParam)->lpCreateParams);

        SetLastError(0);
        if (!SetWindowLongPtr(hwnd, GWL_USERDATA, reinterpret_cast<LONG_PTR>(pThis)))
        {
            if (GetLastError() != 0)
                return FALSE;
        }
    }
    else
    {
        pThis = reinterpret_cast<ViewImpl *>(GetWindowLongPtr(hwnd, GWL_USERDATA));
    }

    if (pThis)
    {
        pThis->_prev = "";

        switch (msg)
        {
            case WM_PAINT:
                pThis->DrawBoard ();
                return 0;
            case WM_LBUTTONUP:
                pThis->Click(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));

                if ("" == pThis->_prev) {
                    break;
                }

                pThis->_input = true;
                return 0;
            case WM_DESTROY:
                PostQuitMessage(0);
                return 0;
            default:
                break;
        }
    }

    return DefWindowProc(hwnd, msg, wParam, lParam);
}
