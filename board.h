#if !defined board_h
#define board_h

class Board
{
public:
    Board ();
    void Claim(int column, bool firstPlayer);
    void Draw () const;
    bool IsGameOver () const { return gameOver; }

    static int const height = 6;
    static int const width = 7;
private:
    void CheckBoardFull ();
    void CheckGameWon (int row, int col);

    static int const winLength = 4;
    bool gameOver;
    char spaces [Board::height][Board::width];
};

#endif
