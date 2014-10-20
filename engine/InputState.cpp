#include "InputState.h"

InputState::InputState()
{
}

//Returns if the specified key is currently held down
bool InputState::KeyIsDown(KeyCode keyCode)
{
    std::map<KeyCode,bool>::iterator i;
    i = keysDown.find(keyCode);
    if (i==keysDown.end()) return false;
    return i->second;
}


//Fired when key is pressed
void InputState::OnKeyPressEvent(InputKeyEvent *e)
{
    keysDown[(KeyCode)e->Key()] = true;
}

//Fired when key is released
void InputState::OnKeyReleaseEvent(InputKeyEvent *e)
{
    keysDown[(KeyCode)e->Key()] = false;
}


