#ifndef TEXTUREPAGE_H
#define TEXTUREPAGE_H

#include "unused.h"

/*
 * Represents a texture page (bitmap with usually multiple images on it).
 * Author: Brad Triebwasser (04/2014)
 * */

class Renderer;
class TexturePage {
public:
    //Create texture page from data
    TexturePage(char* data, unsigned int len) { UNUSED(data); UNUSED(len);}
    virtual ~TexturePage() {}
    //Get width of texture page
    virtual int GetWidth() = 0;
    //Get height of texture page
    virtual int GetHeight() = 0;
};


#endif // TEXTUREPAGE_H
