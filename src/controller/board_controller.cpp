#include <functional>
#include <string>
#include "../../include/controller/board_controller.h"
using std::bind;

BoardController::BoardController (Board & board, View & view)
    : _board (board), _view (view)
{
    _board.RegisterObserver ("ALL", bind(&View::Update, & _view));
}

void BoardController::TakeTurn ()
{
    _board.Claim(atoi(_view.PromptForInput ().c_str ()) - 1);
}
