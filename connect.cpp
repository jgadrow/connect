#include <iostream>
#include <cstdlib>
#include "board.h"
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::atoi;

int main ()
{
    // Draw board.
    Board theBoard;
    theBoard.Draw();

    // Set first player.
    bool firstPlayer = true;

    // While game is not over.
    while (!theBoard.IsGameOver ())
    {
        // Ask player for move.
        cout << endl;
        cout << "Select a slot (numbered left-to-right, 1-" << Board::width << "): ";

        string selected;
        getline(cin, selected);
        cout << "\b\r";

        cout << "Select a slot (numbered left-to-right, 1-" << Board::width << "): ";

        for (int i = 0; i < selected.length () + 1; ++i)
        {
            cout << " ";
        }

        theBoard.Claim(atoi(selected.c_str ()) - 1, firstPlayer);

        cout << "\r\b\r";

        for (int i = 0; i < Board::height*2-1; ++i)
        {
            cout << "\b\r";
        }

        // Redraw board.
        theBoard.Draw();

        // Switch player.
        firstPlayer = !firstPlayer;
    }

    cout << endl;
}
