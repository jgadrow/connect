#include <functional>
#include "controller.h"
using std::bind;

Controller::Controller (Model & model, View & view)
    : _model (model), _view(view)
{
    _model.RegisterObserver ("ALL", std::bind(&View::Update, & _view));
}
