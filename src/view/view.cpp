#include "../../include/view/view.h"
#include "../../include/view/console_view.h"

View::View (Board const & board)
    : _impl (new ViewImpl (board))
{
}

View::~View () = default;

void View::DrawBoard () const
{
    _impl->DrawBoard ();
}

string View::PromptForInput() const
{
    return _impl->PromptForInput ();
}

void View::Update () const
{
    _impl->Update ();
}
