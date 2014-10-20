#include "Color.h"


Color::Color(const unsigned int &val)
{
    _a = val>>24;
    if (val<=0xFFFFFF)
    {   //Make Alpha opaque if only RGB was passed
        _a = 255;
    }
    _r = ((val&0xFF0000)>>16);
    _g = ((val&0xFF00)>>8);
    _b = ((val&0xFF));
}

Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
    :_r(r),_g(g),_b(b), _a(a)
{

}

Color::Color(float r, float g, float b, float a)
{
    _r = (unsigned char)((float)255*r);
    _g = (unsigned char)((float)255*g);
    _b = (unsigned char)((float)255*b);
    _a = (unsigned char)((float)255*a);
}
