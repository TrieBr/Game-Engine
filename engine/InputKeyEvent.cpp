#include "InputKeyEvent.h"

//Constructor
InputKeyEvent::InputKeyEvent()
{

}

//Constructor
InputKeyEvent::InputKeyEvent(int key, unsigned int modifiers, const std::string &text, bool isAutoRepeat)
    : key(key), modifierFlags(modifiers), text(text), isAutoRepeat(isAutoRepeat)
{

}

//Returns true if this event was fired from an auto repeat, false for an initial key press
bool InputKeyEvent::IsAutoRepeat()
{
    return isAutoRepeat;
}

//Returns the code for the key that was pressed or released
int InputKeyEvent::Key()
{
    return key;
}

//Returns the text that this key generated.
std::string InputKeyEvent::Text()
{
    return text;
}


//Returns true if the specified modifier flag is set to true
bool InputKeyEvent::IsModifierSet(int modifier)
{
    return ((modifierFlags&modifier)==modifier);
}

//Return the modifiers flags
unsigned int InputKeyEvent::GetModifiers()
{
    return modifierFlags;
}
