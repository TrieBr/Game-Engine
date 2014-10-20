#include "QTKeyMap.h"

QTKeyMap::QTKeyMap()
{
}

//Initialize the map
void QTKeyMap::Initialize()
{

    keyMap[Qt::Key_A]=KeyCode::Key_A;
    keyMap[Qt::Key_B]=KeyCode::Key_B;
    keyMap[Qt::Key_C]=KeyCode::Key_C;
    keyMap[Qt::Key_D]=KeyCode::Key_D;
    keyMap[Qt::Key_E]=KeyCode::Key_E;
    keyMap[Qt::Key_F]=KeyCode::Key_F;
    keyMap[Qt::Key_G]=KeyCode::Key_G;
    keyMap[Qt::Key_H]=KeyCode::Key_H;
    keyMap[Qt::Key_I]=KeyCode::Key_I;
    keyMap[Qt::Key_J]=KeyCode::Key_J;
    keyMap[Qt::Key_K]=KeyCode::Key_K;
    keyMap[Qt::Key_L]=KeyCode::Key_L;
    keyMap[Qt::Key_M]=KeyCode::Key_M;
    keyMap[Qt::Key_N]=KeyCode::Key_N;
    keyMap[Qt::Key_O]=KeyCode::Key_O;
    keyMap[Qt::Key_P]=KeyCode::Key_P;
    keyMap[Qt::Key_Q]=KeyCode::Key_Q;
    keyMap[Qt::Key_R]=KeyCode::Key_R;
    keyMap[Qt::Key_S]=KeyCode::Key_S;
    keyMap[Qt::Key_T]=KeyCode::Key_T;
    keyMap[Qt::Key_U]=KeyCode::Key_U;
    keyMap[Qt::Key_V]=KeyCode::Key_V;
    keyMap[Qt::Key_W]=KeyCode::Key_W;
    keyMap[Qt::Key_X]=KeyCode::Key_X;
    keyMap[Qt::Key_Y]=KeyCode::Key_Y;
    keyMap[Qt::Key_Z]=KeyCode::Key_Z;

    keyMap[Qt::Key_0]=KeyCode::Key_0;
    keyMap[Qt::Key_1]=KeyCode::Key_1;
    keyMap[Qt::Key_2]=KeyCode::Key_2;
    keyMap[Qt::Key_3]=KeyCode::Key_3;
    keyMap[Qt::Key_4]=KeyCode::Key_4;
    keyMap[Qt::Key_5]=KeyCode::Key_5;
    keyMap[Qt::Key_6]=KeyCode::Key_6;
    keyMap[Qt::Key_7]=KeyCode::Key_7;
    keyMap[Qt::Key_8]=KeyCode::Key_8;
    keyMap[Qt::Key_9]=KeyCode::Key_9;


    keyMap[Qt::Key_F1]=KeyCode::Key_F1;
    keyMap[Qt::Key_F2]=KeyCode::Key_F2;
    keyMap[Qt::Key_F3]=KeyCode::Key_F3;
    keyMap[Qt::Key_F4]=KeyCode::Key_F4;
    keyMap[Qt::Key_F5]=KeyCode::Key_F5;
    keyMap[Qt::Key_F6]=KeyCode::Key_F6;
    keyMap[Qt::Key_F7]=KeyCode::Key_F7;
    keyMap[Qt::Key_F8]=KeyCode::Key_F8;
    keyMap[Qt::Key_F9]=KeyCode::Key_F9;
    keyMap[Qt::Key_F10]=KeyCode::Key_F10;
    keyMap[Qt::Key_F11]=KeyCode::Key_F11;
    keyMap[Qt::Key_F12]=KeyCode::Key_F12;

    keyMap[Qt::Key_Escape]=KeyCode::Key_Escape;
    keyMap[Qt::Key_AsciiTilde]=KeyCode::Key_Tilde;
    keyMap[Qt::Key_Minus]=KeyCode::Key_Minus;
    keyMap[Qt::Key_Equal]=KeyCode::Key_Equals;
    keyMap[Qt::Key_Backspace]=KeyCode::Key_Backspace;
    keyMap[Qt::Key_Tab]=KeyCode::Key_Tab;
    keyMap[Qt::Key_ParenLeft]=KeyCode::Key_Openbrace;
    keyMap[Qt::Key_ParenRight]=KeyCode::Key_Closebrace;
    keyMap[Qt::Key_Enter]=KeyCode::Key_Enter;
    keyMap[Qt::Key_Semicolon]=KeyCode::Key_Semicolon;
    keyMap[Qt::Key_QuoteDbl]=KeyCode::Key_Quote;
    keyMap[Qt::Key_Backslash]=KeyCode::Key_Backslash;
    keyMap[Qt::Key_Comma]=KeyCode::Key_Comma;
    keyMap[Qt::Key_Period]=KeyCode::Key_Fullstop;
    keyMap[Qt::Key_Slash]=KeyCode::Key_Slash;
    keyMap[Qt::Key_Space]=KeyCode::Key_Space;

    keyMap[Qt::Key_Insert]=KeyCode::Key_Insert;
    keyMap[Qt::Key_Delete]=KeyCode::Key_Delete;
    keyMap[Qt::Key_Home]=KeyCode::Key_Home;
    keyMap[Qt::Key_End]=KeyCode::Key_End;
    keyMap[Qt::Key_PageUp]=KeyCode::Key_Pgup;
    keyMap[Qt::Key_PageDown]=KeyCode::Key_Pgdn;
    keyMap[Qt::Key_Left]=KeyCode::Key_Left;
    keyMap[Qt::Key_Right]=KeyCode::Key_Right;
    keyMap[Qt::Key_Up]=KeyCode::Key_Up;
    keyMap[Qt::Key_Down]=KeyCode::Key_Down;

    keyMap[Qt::Key_Slash]=KeyCode::Key_Pad_Slash;
    keyMap[Qt::Key_Asterisk]=KeyCode::Key_Pad_Asterisk;
    keyMap[Qt::Key_Minus]=KeyCode::Key_Pad_Minus;
    keyMap[Qt::Key_Plus]=KeyCode::Key_Pad_Plus;
    keyMap[Qt::Key_Period]=KeyCode::Key_Pad_Delete;
   // keyMap[0x0100012]=KeyCode::Key_Pad_Enter;

    keyMap[Qt::Key_Print]=KeyCode::Key_Printscreen;
    keyMap[Qt::Key_Pause]=KeyCode::Key_Pause;

   // keyMap[0x01000123]=KeyCode::Key_Abnt_c1; //Uknown QT Equivilent
    keyMap[Qt::Key_yen]=KeyCode::Key_Yen;
    keyMap[Qt::Key_Kana_Lock]=KeyCode::Key_Kana;
   // keyMap[0x01000124]=KeyCode::Key_Convert; //Uknown QT Equivilent
   // keyMap[0x01000125]=KeyCode::Key_Noconvert; //Uknown QT Equivilent
   // keyMap[0x01000126]=KeyCode::Key_At; //Uknown QT Equivilent
   // keyMap[0x01000127]=KeyCode::Key_Circumflex; //Uknown QT Equivilent
  //  keyMap[0x01000128]=KeyCode::Key_Colon2; //Uknown QT Equivilent
    //keyMap[0x01000129]=KeyCode::Key_Kanji; //Uknown QT Equivilent

   // keyMap[ 0x0100012a]=KeyCode::Key_Pad_equals;/* macos x*/
   // keyMap[ 0x0100012b]=KeyCode::Key_Command;/* macos x*/
    keyMap[Qt::Key_unknown]=KeyCode::Key_Unknown;

}

//Convert a QT Key event to the internal format
InputKeyEvent QTKeyMap::ConvertToInternalKeyEvent(QKeyEvent* ev)
{
    KeyCode internalKeyCode = KeyCode::Key_Unknown;
    std::map<int,KeyCode>::iterator i;
    i = keyMap.find(ev->key()); //Convert to internal KeyCode
    if (i!=keyMap.end()) { //Internal keycode was matched
        internalKeyCode = i->second;
        if (internalKeyCode>=KeyCode::Key_0 && internalKeyCode<=KeyCode::Key_9)
        { //# was pressed, check if it was on keypad
            if (ev->modifiers().testFlag(Qt::KeypadModifier))
            {
                internalKeyCode=(KeyCode)((int)internalKeyCode+10);
            }
        }
    }
    unsigned int modifiers = 0;
    //TODO: Convert QT modifiers to internal Modifiers

    return InputKeyEvent(internalKeyCode,modifiers,ev->text().toStdString(),ev->isAutoRepeat());
}

