#ifndef INPUTEVENTDISPATCHER_H
#define INPUTEVENTDISPATCHER_H

#include <vector>

class InputEventHandler;
class InputKeyEvent;
class InputMouseEvent;
class InputTouchEvent;
class InputEventDispatcher {
public:
    //Destructor
    ~InputEventDispatcher();
    //Register an event handler to receive events
    void RegisterInputEventHandler(InputEventHandler *handlerPtr);
    //Unregister event handler
    void UnregisterInputEventHandler(InputEventHandler *handlerPtr);
    //Dispatches a key pressed event
    void DispatchKeyPressEvent(InputKeyEvent *e);
    //Dispatches a key released event
    void DispatchKeyReleaseEvent(InputKeyEvent *e);
    //Dispatches a mouse press event
    void DispatchMousePressEvent(InputMouseEvent *e);
    //Dispatches a mouse release event
    void DispatchMouseReleaseEvent(InputMouseEvent *e);
    //Dispatches a mouse mose event
    void DispatchMouseMoveEvent(InputMouseEvent *e);
    //Dispatches a mouse touch event
    void DispatchTouchEvent(InputTouchEvent *e);

private:
    std::vector<InputEventHandler*> eventListeners; //List of event listeners registered with this dispatcher


};

#endif // INPUTEVENTDISPATCHER_H
