#ifndef INPUTSTATE_H
#define INPUTSTATE_H

#include "KeyCodes.h"
#include "InputEventHandler.h"
#include <map>

class InputState : public InputEventHandler
{
public:
    InputState();
    //Returns if the specified key is currently held down
    bool KeyIsDown(KeyCode keyCode);

    //Fired when key is pressed
    virtual void OnKeyPressEvent(InputKeyEvent *e);
    //Fired when key is released
    virtual void OnKeyReleaseEvent(InputKeyEvent *e);


private:
    std::map<KeyCode,bool> keysDown;    //Map of keys that are currently held down
};

#endif // INPUTSTATE_H
