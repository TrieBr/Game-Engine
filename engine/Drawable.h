#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "Point.h"
#include "unused.h"


/*
 * Represents an object that can be drawn to a Renderer.
 * Author: Brad Triebwasser (04/2014)
 * */

class Renderer;
class Drawable {
public:
    //Draw this drawable object at x,y
    virtual void Draw(Renderer* renderer,const Pointf& point) = 0;
    //Draw at an angle
    virtual void Draw(Renderer* renderer,const Pointf& point, float angle) { UNUSED(renderer); UNUSED(point); UNUSED(angle); }
    //Draw scaled
    virtual void Draw(Renderer* renderer,const Pointf& point, float xScale, float yScale) { UNUSED(renderer); UNUSED(point); UNUSED(xScale); UNUSED(yScale);}
    //Draw scaled and angled
    virtual void Draw(Renderer* renderer,const Pointf& point, float angle, float xScale, float yScale) {UNUSED(renderer); UNUSED(point); UNUSED(angle); UNUSED(xScale); UNUSED(yScale);}
};



#endif // DRAWABLE_H
