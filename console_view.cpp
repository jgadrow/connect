#include <iostream>
#include "console_view.h"
using std::cin;
using std::cout;
using std::endl;

ConsoleView::ConsoleView (Board const & board)
    : _board (board)
{
    _prev = "";
}

void ConsoleView::DrawBoard () const
{
    for (int i = 0; i < Board::height; ++i)
    {
        if (0 != i)
        {
            cout << "-";
            for (int j = 0; j < Board::width-1; ++j)
            {
                cout << "+-";
            }
            cout << endl;
        }

        for (int j = 0; j < Board::width; ++j)
        {
            if (0 != j)
            {
                cout << '|';
            }

            cout << _board.GetToken (i, j);
        }

        cout << endl;
    }
}

string ConsoleView::PromptForInput() const
{
    // Ask player for move.
    cout << endl;
    cout << "Select a slot (numbered left-to-right, 1-" << Board::width << "): ";

    // Erase previous input if any.
    if (0 != _prev.length ())
    {
        for (int i = 0; i < _prev.length () + 1; ++i)
        {
            cout << " ";
        }

        for (int i = 0; i < _prev.length () + 1; ++i)
        {
            cout << "\b";
        }
    }

    string selected;
    getline(cin, selected);
    _prev = selected;
    return selected;
}

void ConsoleView::Update () const
{
    // Reset cursor to start of prompt.
    cout << "\r\b\r";

    // Reset cursor to start of board.
    for (int i = 0; i < Board::height*2; i++)
    {
        cout << "\b\r";
    }

    DrawBoard();

    if (_board.IsGameOver ()) {
        cout << endl << endl;
    }
}
