#if !defined board_h
#define board_h
#include "model.h"

class Board : public Model
{
public:
    Board ();
    void Claim(int column);
    char GetToken (int row, int col) const;
    bool IsGameOver () const { return gameOver; }

    static int const height = 6;
    static int const width = 7;
private:
    void CheckBoardFull ();
    void CheckGameWon (int row, int col);

    static int const winLength = 4;
    bool firstPlayer;
    bool gameOver;
    char spaces [Board::height][Board::width];
};

#endif
