#include "../../include/view/view.h"

#if !defined _PROJECT_SUPPORT_WINDOWS_
#include "../../include/view/console_view.h"
#else
#include "../../include/view/windows_view.h"
#endif

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
