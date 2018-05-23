#if !defined include_view_windows_view_h
#define include_view_windows_view_h
#include <string>
#include <windows.h>
#include "../model/board.h"
using std::string;

class ViewImpl
{
public:
    ViewImpl (Board const & board);
    void DrawBoard() const;
    string PromptForInput() const;
    void Update() const;
private:
    void Click(int x, int y);

    static LRESULT CALLBACK WndProc(
        HWND hwnd,
        UINT msg,
        WPARAM wParam,
        LPARAM lParam
    );

    Board const & _board;
    HWND _hwnd;
    string _prev;
    bool mutable _input;
};

#endif
