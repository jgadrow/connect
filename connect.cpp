#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;

class Board
{
public:
    Board ()
    {
        gameOver = false;

        for (int i = 0; i < 6; ++i)
        {
            for (int j = 0; j < 7; ++j)
            {
                spaces[i][j] = ' ';
            }
        }
    }

    void Claim(int column, bool firstPlayer)
    {
        int row = 0;

        for (int i = 5; i > 0; --i)
        {
            if (' ' == spaces[i][column])
            {
                row = i;
                break;
            }
        }

        spaces[row][column] = firstPlayer? 'x' : 'o';

        CheckBoardFull ();
        CheckGameWon ();
    }

    void Draw () const
    {
        for (int i = 0; i < 6; ++i)
        {
            if (0 != i)
            {
                cout << "-+-+-+-+-+-+-" << endl;
            }

            for (int j = 0; j < 7; ++j)
            {
                if (0 != j)
                {
                    cout << '|';
                }

                cout << spaces[i][j];
            }

            cout << endl;
        }
    }

    bool IsGameOver () const
    {
        return gameOver;
    }
private:
    void CheckBoardFull ()
    {
        for (int i = 0; i < 6; ++i)
        {
            for (int j = 0; j < 7; ++j)
            {
                if (' ' == spaces[i][j])
                {
                    return;
                }
            }
        }

        gameOver = true;
    }

    void CheckGameWon ()
    {
        int p1spots [21];
        int p2spots [21];
        int p1i = 0;
        int p2i = 0;

        for (int i = 0; i < 6; ++i)
        {
            for (int j = 0; j < 7; ++j)
            {
                char val = spaces[i][j];

                if (' ' == val)
                {
                    continue;
                }

                if ('x' == val)
                {
                    p1spots[p1i++] = j+(i*7);
                }
                else
                {
                    p2spots[p2i++] = j+(i*7);
                }
            }
        }

        if (4 > p1i && 4 > p2i)
        {
            return;
        }

        int wins [69][4] = {
            {0,1,2,3},
            {0,8,16,24},
            {0,7,14,21},
            {1,2,3,4},
            {1,9,17,25},
            {1,8,15,22},
            {2,3,4,5},
            {2,10,18,26},
            {2,9,16,23},
            {3,4,5,6},
            {3,9,15,21},
            {3,11,29,27},
            {3,10,17,24},
            {4,10,16,22},
            {4,11,18,25},
            {5,11,17,23},
            {5,12,19,26},
            {6,12,18,24},
            {6,13,20,27},
            {7,8,9,10},
            {7,15,23,31},
            {7,14,21,28},
            {8,9,10,11},
            {8,15,22,29},
            {8,16,24,32},
            {9,10,11,12},
            {9,16,23,30},
            {9,17,25,33},
            {10,11,12,13},
            {10,16,22,28},
            {10,17,24,31},
            {10,18,26,34},
            {11,17,23,29},
            {11,18,25,32},
            {12,18,24,30},
            {12,19,26,33},
            {13,19,25,31},
            {13,20,27,34},
            {14,15,16,17},
            {14,21,28,35},
            {14,22,30,38},
            {15,16,17,18},
            {15,22,29,36},
            {15,23,31,39},
            {16,17,18,19},
            {16,23,30,37},
            {16,24,32,40},
            {17,18,29,20},
            {17,23,29,35},
            {17,24,31,38},
            {17,25,33,41},
            {18,24,30,36},
            {18,25,32,39},
            {19,25,32,37},
            {19,26,33,40},
            {20,26,32,38},
            {20,27,34,41},
            {21,22,23,24},
            {22,23,24,25},
            {23,24,25,26},
            {24,25,26,27},
            {28,29,30,31},
            {29,30,31,32},
            {30,31,32,33},
            {31,32,33,34},
            {35,36,37,38},
            {36,37,38,39},
            {37,38,39,40},
            {38,39,40,41}
        };

        if (3 < p1i)
        {
            for (int i = 0; i < 69; ++i)
            {
                int matched = 0;

                for (int j = 0; j < 4; ++j)
                {
                    for (int k = 0; k < p1i; ++k)
                    {
                        if (p1spots[k] == wins[i][j])
                        {
                            ++matched;
                        }
                    }
                }

                if (4 == matched)
                {
                    gameOver = true;
                    return;
                }
            }
        }

        if (3 < p2i)
        {
            for (int i = 0; i < 69; ++i)
            {
                int matched = 0;

                for (int j = 0; j < 4; ++j)
                {
                    for (int k = 0; k < p2i; ++k)
                    {
                        if (p2spots[k] == wins[i][j])
                        {
                            ++matched;
                        }
                    }
                }

                if (4 == matched)
                {
                    gameOver = true;
                    return;
                }
            }
        }
    }

    bool gameOver;
    char spaces [6][7];
};

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
        // Ask player for move (1-9).
        cout << endl;
        cout << "Select a slot (numbered left-to-right, 1-7): ";

        string selected;
        getline(cin, selected);
        cout << "\b\r";

        cout << "Select a slot (numbered left-to-right, 1-7): ";

        for (int i = 0; i < selected.length () + 1; ++i)
        {
            cout << " ";
        }

        int selectedSpace;

        if ("1" == selected)
        {
            selectedSpace = 0;
        }
        else if ("2" == selected)
        {
            selectedSpace = 1;
        }
        else if ("3" == selected)
        {
            selectedSpace = 2;
        }
        else if ("4" == selected)
        {
            selectedSpace = 3;
        }
        else if ("5" == selected)
        {
            selectedSpace = 4;
        }
        else if ("6" == selected)
        {
            selectedSpace = 5;
        }
        else if ("7" == selected)
        {
            selectedSpace = 6;
        }

        theBoard.Claim(selectedSpace, firstPlayer);

        cout << "\r\b\r\b\r\b\r\b\r\b\r\b\r\b\r";
        cout << "\b\r\b\r\b\r\b\r\b\r";

        // Redraw board.
        theBoard.Draw();

        // Switch player.
        firstPlayer = !firstPlayer;
    }

    cout << endl;
}
