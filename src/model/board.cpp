#include "../../include/model/board.h"

Board::Board ()
{
    firstPlayer = true;
    gameOver = false;

    for (int i = 0; i < Board::height; ++i)
    {
        for (int j = 0; j < Board::width; ++j)
        {
            spaces[i][j] = ' ';
        }
    }
}

void Board::CheckBoardFull ()
{
    for (int i = 0; i < Board::height; ++i)
    {
        for (int j = 0; j < Board::width; ++j)
        {
            if (' ' == spaces[i][j])
            {
                return;
            }
        }
    }

    gameOver = true;
}

void Board::CheckGameWon (int row, int col)
{
    int deltas [4][2] = {
        {0,1},
        {1,0},
        {1,1},
        {-1,1}
    };

    for (int i = 0; i < 4; ++i)
    {
        int rowDelta = deltas[i][0];
        int colDelta = deltas[i][1];

        {
            int j = 1;
            int curRow = row;
            int curCol = col;
            bool isInverted = false;

            for ( ; j < Board::winLength; ++j)
            {
                curRow += isInverted ? -rowDelta : rowDelta;
                curCol += isInverted ? -colDelta : colDelta;
                bool matched = curRow >= 0
                    && curRow < Board::height
                    && curCol >= 0
                    && curCol < Board::width
                    && spaces[curRow][curCol] == spaces[row][col];

                // If this is the last match, the game is over.
                if (matched && Board::winLength == j+1)
                {
                    gameOver = true;
                    return;
                }
                else if (matched)
                {
                    continue;
                }

                curRow = row;
                curCol = col;
                --j;

                // Is row non-zero and not inverted? Invert it.
                if (!isInverted)
                {
                    isInverted = true;
                    continue;
                }
                else
                {
                    break;
                }
            }
        }
    }
}

void Board::Claim(int column)
{
    int row = 0;

    for (int i = Board::height-1; i > 0; --i)
    {
        if (' ' == spaces[i][column])
        {
            row = i;
            break;
        }
    }

    spaces[row][column] = firstPlayer? 'x' : 'o';
    firstPlayer = !firstPlayer;
    CheckGameWon (row, column);

    if (!gameOver) {
        CheckBoardFull ();
    }

    Notify("ALL");
}

char Board::GetToken (int row, int col) const
{
    return spaces[row][col];
}
