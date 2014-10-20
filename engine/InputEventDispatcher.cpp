#include "InputEventDispatcher.h"
#include "Logger.h"
#include "InputEventHandler.h"

//Destructor
InputEventDispatcher::~InputEventDispatcher()
{
    if (!eventListeners.empty())
    {
        Logger::Warn("Input Event dispatcher destroyed, with existing listeners.");
    }
}

//Register an event handler to receive events
void InputEventDispatcher::RegisterInputEventHandler(InputEventHandler *handlerPtr)
{
  //  Logger::Trace("Input event listener registered to input event dispatcher.");
    eventListeners.push_back(handlerPtr);

}

//Unregister event handler
void InputEventDispatcher::UnregisterInputEventHandler(InputEventHandler *handlerPtr)
{
    for (unsigned int i=0; i<eventListeners.size(); i++) {
        if (eventListeners[i]==handlerPtr){
            eventListeners.erase(eventListeners.begin()+i);
            break;
        }
    }
}

//Dispatches a key pressed event
void InputEventDispatcher::DispatchKeyPressEvent(InputKeyEvent *e)
{
    for (std::vector<InputEventHandler*>::iterator i = eventListeners.begin(); i!=eventListeners.end(); i++)
        (*i)->OnKeyPressEvent(e);
}

//Dispatches a key released event
void InputEventDispatcher::DispatchKeyReleaseEvent(InputKeyEvent *e)
{
    for (std::vector<InputEventHandler*>::iterator i = eventListeners.begin(); i!=eventListeners.end(); i++)
        (*i)->OnKeyReleaseEvent(e);
}

//Dispatches a mouse press event
void InputEventDispatcher::DispatchMousePressEvent(InputMouseEvent *e)
{
    for (std::vector<InputEventHandler*>::iterator i = eventListeners.begin(); i!=eventListeners.end(); i++)
        (*i)->OnMousePressEvent(e);
}

//Dispatches a mouse release event
void InputEventDispatcher::DispatchMouseReleaseEvent(InputMouseEvent *e)
{
    for (std::vector<InputEventHandler*>::iterator i = eventListeners.begin(); i!=eventListeners.end(); i++)
        (*i)->OnMouseReleaseEvent(e);
}

//Dispatches a mouse mose event
void InputEventDispatcher::DispatchMouseMoveEvent(InputMouseEvent *e)
{
    for (std::vector<InputEventHandler*>::iterator i = eventListeners.begin(); i!=eventListeners.end(); i++)
        (*i)->OnMouseMoveEvent(e);
}

//Dispatches a mouse touch event
void InputEventDispatcher::DispatchTouchEvent(InputTouchEvent *e)
{
    for (std::vector<InputEventHandler*>::iterator i = eventListeners.begin(); i!=eventListeners.end(); i++)
        (*i)->OnTouchEvent(e);
}
