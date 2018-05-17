#if !defined console_view_h
#define console_view_h
#include <iostream>
#include "board.h"
#include "view.h"
using std::string;

class ConsoleView : public View
{
public:
    ConsoleView (Board & board);
    void DrawBoard() const;
    string PromptForInput() const;
    void Update() override;
private:
    Board & _board;
    string mutable _prev;
};

#endif
