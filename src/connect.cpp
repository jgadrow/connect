#include "../include/model/board.h"
#include "../include/controller/board_controller.h"
#include "../include/view/view.h"

int main ()
{
    // Initialize the View, Board, and Controller.
    Board theBoard;
    View view (theBoard);
    BoardController boardController (theBoard, view);
    view.DrawBoard ();

    // While game is not over.
    while (!theBoard.IsGameOver ())
    {
        boardController.TakeTurn ();
    }
}
