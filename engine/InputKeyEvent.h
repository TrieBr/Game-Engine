#ifndef INPUTKEYEVENT_H
#define INPUTKEYEVENT_H

#include <string>
#include "InputEvent.h"
#include "KeyCodes.h"


class InputKeyEvent : public InputEvent
{
public:
    //Constructor
    InputKeyEvent();
    //Constructor
    InputKeyEvent(int key, unsigned int modifiers, const std::string &text, bool isAutoRepeat);
    //Returns true if this event was fired from an auto repeat, false for an initial key press
    bool IsAutoRepeat();
    //Returns the code for the key that was pressed or released
    int Key();
    //Returns the text that this key generated.
    std::string Text();
    //Returns true if the specified modifier flag is set to true
    bool IsModifierSet(int modifier);
    //Return the modifiers flags
    unsigned int GetModifiers();
private:
    int key;            //Keycode for the key event
    std::string text;   //Text/Character for the key that was pressed/released
    bool isAutoRepeat;  //True if the event was fired from an auto repeat (held down key)
    unsigned int modifierFlags; //Modifier Flags
};

#endif // INPUTKEYEVENT_H
