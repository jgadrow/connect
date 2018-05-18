#include <functional>
#include <string>
#include "board_controller.h"
using std::bind;

BoardController::BoardController (Board & board, ConsoleView & view)
    : _board (board), _view (view)
{
    _board.RegisterObserver ("ALL", bind(&ConsoleView::Update, & _view));
}

void BoardController::TakeTurn ()
{
    _board.Claim(atoi(_view.PromptForInput ().c_str ()) - 1);
}
