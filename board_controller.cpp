#include "board_controller.h"
#include <string>

BoardController::BoardController (Board & board, ConsoleView & view)
    : Controller(board, view), _board (board), _view (view)
{
}

void BoardController::TakeTurn ()
{
    _board.Claim(atoi(_view.PromptForInput ().c_str ()) - 1);
}
