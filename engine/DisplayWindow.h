#ifndef WINDOW_H
#define WINDOW_H

#include "ViewportSurface.h"
#include "InputEventDispatcher.h"
#include <vector>


/*
 * Display window renders to the display.
 * Author: Brad Triebwasser (04/2014)
 * */

class DisplayWindow : public ViewportSurface, public InputEventDispatcher
{
public:
    DisplayWindow() {}
    virtual ~DisplayWindow() {}
protected:

private:

};


#endif // WINDOW_H
