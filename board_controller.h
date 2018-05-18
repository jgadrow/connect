#if !defined board_controller_h
#define board_controller_h
#include "board.h"
#include "console_view.h"

class BoardController
{
public:
    BoardController (Board & board, ConsoleView & view);
    void TakeTurn ();
private:
    Board & _board;
    ConsoleView & _view;
};

#endif
