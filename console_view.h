#if !defined console_view_h
#define console_view_h
#include <string>
#include "board.h"
using std::string;

class ConsoleView
{
public:
    ConsoleView (Board const & board);
    void DrawBoard() const;
    string PromptForInput() const;
    void Update() const;
private:
    Board const & _board;
    string mutable _prev;
};

#endif
