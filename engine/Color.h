#ifndef COLOR_H
#define COLOR_H


/*
 * Represents an RGBA color
 * Author: Brad Triebwasser (04/2014)
 * */

class Color
{
public:
    //Color based on AARRGGBB quadruplet
    Color(const unsigned int &val);
    //Constructor for unsigned chars
    Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a=255);
    //Constructor for floating points
    Color(float r, float g, float b, float a=1.0f);
    //Getters
    unsigned char R() const {return _r;}
    unsigned char G() const {return _g;}
    unsigned char B() const {return _b;}
    unsigned char A() const {return _a;}

private:
    unsigned char _r;
    unsigned char _g;
    unsigned char _b;
    unsigned char _a;
};

#endif // COLOR_H
