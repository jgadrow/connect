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

    void Claim(int space, bool firstPlayer)
    {
        int col = space%7;
        int row = space/7;

        spaces[row][col] = firstPlayer? 'x' : 'o';

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

        // Ask player for move (1-9).
        cout << endl;
        cout << "Select a space (numbered left-to-right, top-to-bottom 1-42):  \b";
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
        int p1i;
        int p2i;

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
            {38,39,40,41},
        };

        if (2 < p1i)
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

        if (2 < p2i)
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
        string selected;
        getline(cin, selected);
        cout << "\b\r";

        cout << "Select a space (numbered left-to-right, top-to-bottom 1-42): ";

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
		else if ("8" == selected)
		{
			selectedSpace = 7;
		}
		else if ("9" == selected)
		{
			selectedSpace = 8;
		}
		else if ("10" == selected)
		{
			selectedSpace = 9;
		}
        else if ("11" == selected)
        {
		    selectedSpace = 10;
		}
		else if ("12" == selected)
		{
			selectedSpace = 11;
		}
		else if ("13" == selected)
		{
			selectedSpace = 12;
		}
		else if ("14" == selected)
		{
			selectedSpace = 13;
		}
		else if ("15" == selected)
		{
			selectedSpace = 14;
		}
		else if ("16" == selected)
		{
			selectedSpace = 15;
		}
		else if ("17" == selected)
		{
			selectedSpace = 16;
		}
		else if ("18" == selected)
		{
			selectedSpace = 17;
		}
		else if ("19" == selected)
		{
			selectedSpace = 18;
		}
		else if ("20" == selected)
		{
			selectedSpace = 19;
		}
        else if ("21" == selected)
        {
		    selectedSpace = 20;
		}
		else if ("22" == selected)
		{
			selectedSpace = 21;
		}
		else if ("23" == selected)
		{
			selectedSpace = 22;
		}
		else if ("24" == selected)
		{
			selectedSpace = 23;
		}
		else if ("25" == selected)
		{
			selectedSpace = 24;
		}
		else if ("26" == selected)
		{
			selectedSpace = 25;
		}
		else if ("27" == selected)
		{
			selectedSpace = 26;
		}
		else if ("28" == selected)
		{
			selectedSpace = 27;
		}
		else if ("29" == selected)
		{
			selectedSpace = 28;
		}
		else if ("30" == selected)
		{
			selectedSpace = 29;
		}
        else if ("31" == selected)
        {
		    selectedSpace = 30;
		}
		else if ("32" == selected)
		{
			selectedSpace = 31;
		}
		else if ("33" == selected)
		{
			selectedSpace = 32;
		}
		else if ("34" == selected)
		{
			selectedSpace = 33;
		}
		else if ("35" == selected)
		{
			selectedSpace = 34;
		}
		else if ("36" == selected)
		{
			selectedSpace = 35;
		}
		else if ("37" == selected)
		{
			selectedSpace = 36;
		}
		else if ("38" == selected)
		{
			selectedSpace = 37;
		}
		else if ("39" == selected)
		{
			selectedSpace = 38;
		}
		else if ("40" == selected)
		{
			selectedSpace = 39;
		}
        else if ("41" == selected)
        {
		    selectedSpace = 40;
		}
		else if ("42" == selected)
		{
			selectedSpace = 41;
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

