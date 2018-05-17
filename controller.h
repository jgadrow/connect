#if !defined controller_h
#define controller_h
#include "model.h"
#include "view.h"

class Controller
{
public:
    Controller(Model & model, View & view);
protected:
    Model & _model;
    View & _view;
};

#endif
