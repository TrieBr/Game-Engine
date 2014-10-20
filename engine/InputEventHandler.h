#ifndef INPUTEVENTHANDLER_H
#define INPUTEVENTHANDLER_H

#include "InputKeyEvent.h"
#include "InputMouseEvent.h"
#include "InputTouchEvent.h"
#include "unused.h"

/*
 * Base class for handling input events (keyboard, touch, mouse, etc.)
 *
 * */


class InputEventHandler
{
public:
    InputEventHandler();

    //Fired when key is pressed
    virtual void OnKeyPressEvent(InputKeyEvent *e) { UNUSED(e)}
    //Fired when key is released
    virtual void OnKeyReleaseEvent(InputKeyEvent *e){ UNUSED(e)}
    //Fired when mouse button is pressed
    virtual void OnMousePressEvent(InputMouseEvent *e){UNUSED(e)}
    //Fired when mouse button is released
    virtual void OnMouseReleaseEvent(InputMouseEvent *e){UNUSED(e)}
    //Fired when mouse button is moved
    virtual void OnMouseMoveEvent(InputMouseEvent *e){UNUSED(e)}
    //Fired when a touch event (touch begin, touch end, etc.)
    virtual void OnTouchEvent(InputTouchEvent *e){UNUSED(e)}


private:


};

#endif // INPUTEVENTHANDLER_H
