#ifndef KEYCODES_H
#define KEYCODES_H


/*
 * List of Keycodes
 * */


enum KeyCode {
   Key_A = 1,
   Key_B =2,
   Key_C =3,
   Key_D =4,
   Key_E =5,
   Key_F =6,
   Key_G =7,
   Key_H =8,
   Key_I =9,
   Key_J =10,
   Key_K =11,
   Key_L =12,
   Key_M =13,
   Key_N =14,
   Key_O =15,
   Key_P =16,
   Key_Q =17,
   Key_R =18,
   Key_S =19,
   Key_T =20,
   Key_U =21,
   Key_V =22,
   Key_W =23,
   Key_X =24,
   Key_Y =25,
   Key_Z =26,

   Key_0 =27,
   Key_1 =28,
   Key_2 =29,
   Key_3 =30,
   Key_4 =31,
   Key_5 =32,
   Key_6 =33,
   Key_7 =34,
   Key_8 =35,
   Key_9 =36,

   Key_Pad_0 =37,
   Key_Pad_1 =38,
   Key_Pad_2 =39,
   Key_Pad_3 =40,
   Key_Pad_4 =41,
   Key_Pad_5 =42,
   Key_Pad_6 =43,
   Key_Pad_7 =44,
   Key_Pad_8 =45,
   Key_Pad_9 =46,

   Key_F1 =47,
   Key_F2 =48,
   Key_F3 =49,
   Key_F4 =50,
   Key_F5 =51,
   Key_F6 =52,
   Key_F7 =53,
   Key_F8 =54,
   Key_F9 =55,
   Key_F10 =56,
   Key_F11 =57,
   Key_F12 =58,

   Key_Escape =59,
   Key_Tilde=60,
   Key_Minus=61,
   Key_Equals=62,
   Key_Backspace=63,
   Key_Tab=64,
   Key_Openbrace=65,
   Key_Closebrace =66,
   Key_Enter =67,
   Key_Semicolon =68,
   Key_Quote =69,
   Key_Backslash =70,
   Key_Backslash2 = 71, /* directinput calls this dik_oem_102: "< > | on uk/germany keyboards"*/
   Key_Comma =72,
   Key_Fullstop =73,
   Key_Slash =74,
   Key_Space =75,

   Key_Insert =76,
   Key_Delete =77,
   Key_Home =78,
   Key_End =79,
   Key_Pgup =80,
   Key_Pgdn =81,
   Key_Left =82,
   Key_Right =83,
   Key_Up =84,
   Key_Down =85,

   Key_Pad_Slash =86,
   Key_Pad_Asterisk =87,
   Key_Pad_Minus =88,
   Key_Pad_Plus =89,
   Key_Pad_Delete =90,
   Key_Pad_Enter =91,

   Key_Printscreen =92,
   Key_Pause =93,

   Key_Abnt_c1 =94,
   Key_Yen =95,
   Key_Kana =96,
   Key_Convert =97,
   Key_Noconvert =98,
   Key_At =99,
   Key_Circumflex =100,
   Key_Colon2 =101,
   Key_Kanji =102,

   Key_Pad_equals = 103,/* macos x*/
   Key_Backquote = 104,/* macos x*/
   Key_Semicolon2 = 105,/* macos x -- todo: ask lillo what this should be*/
   Key_Command = 106,/* macos x*/
   Key_Unknown      =107,

};


enum KeyModifier {
    KeyMod_Shift = 0x00001,
    KeyMod_Ctrl = 0x00002,
    KeyMod_Alt = 0x00004,
    KeyMod_Win= 0x00008,
    KeyMod_Menu = 0x00020,
    KeyMod_AltGr = 0x00040,
    KeyMod_Command = 0x00080,
    KeyMod_ScrollLock = 0x00100,
    KeyMod_NumLock = 0x00200,
    KeyMod_Accent1 = 0x00800,
    KeyMod_Accent2 = 0x01000,
    KeyMod_Accent3 = 0x02000,
    KeyMod_Accent4 = 0x04000,
    KeyMod_Accent5 = 0x08000,

};

#endif

