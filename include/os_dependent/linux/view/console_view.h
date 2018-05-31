#if !defined include_view_console_view_h
#define include_view_console_view_h
#include <string>
#include "../../../generic/model/board.h"
using std::string;

class ViewImpl
{
public:
    ViewImpl (Board const & board);
    void DrawBoard() const;
    string PromptForInput() const;
    void Update() const;
private:
    Board const & _board;
    string mutable _prev;
};

#endif
