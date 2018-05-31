#if !defined include_model_board_h
#define include_model_board_h
#include <string>
#include "../subject.h"
using std::string;

class Board : public Subject<string>
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
