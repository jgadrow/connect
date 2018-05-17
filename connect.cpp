#include "board.h"
#include "board_controller.h"
#include "console_view.h"

int main ()
{
    // Initialize the View, Board, and Controller.
    Board theBoard;
    ConsoleView view (theBoard);
    BoardController boardController (theBoard, view);
    view.DrawBoard ();

    // While game is not over.
    while (!theBoard.IsGameOver ())
    {
        boardController.TakeTurn ();
    }
}
