#ifndef VIEWPORTPROPERTIES_H
#define VIEWPORTPROPERTIES_H

#include "Point.h"
#include "Size.h"

/*
 * Properties of a Viewport
 * Author: Brad Triebwasser (04/2014)
 * */


class ViewportProperties
{
public:
    ViewportProperties(const Point& portPosition, const Size& portSize,
                       const Point& viewPosition, const Size& viewSize);

    Point& GetPortPosition();
    Size&  GetPortSize();
    Point& GetViewPosition();
    Size& GetViewSize();
private:
    Point portPosition;     //Port position (position on window)
    Size  portSize;         //Port size (size on window)
    Point viewPosition;     //View position (position in scene)
    Size viewSize;          //View size (size in scene)
};

#endif // VIEWPORTPROPERTIES_H
