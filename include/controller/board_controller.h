#if !defined include_controller_board_controller_h
#define include_controller_board_controller_h
#include "../model/board.h"
#include "../view/view.h"

class BoardController
{
public:
    BoardController (Board & board, View & view);
    void TakeTurn ();
private:
    Board & _board;
    View & _view;
};

#endif
