#if !defined include_view_view_h
#define include_view_view_h
#include <memory>
#include <string>
#include "../model/board.h"
using std::string;
using std::unique_ptr;

class ViewImpl;

class View
{
public:
    View (Board const & board);
    ~View ();
    void DrawBoard() const;
    string PromptForInput() const;
    void Update() const;
private:
    unique_ptr<ViewImpl> _impl;
};

#endif
