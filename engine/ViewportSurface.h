#ifndef VIEWPORTSURFACE_H
#define VIEWPORTSURFACE_H

#include "ViewportProperties.h"
#include <cstdlib>
#include "Viewport.h"

/*
 * A viewport surface. Used to create Viewports that will render to this Surface.
 * Author: Brad Triebwasser (04/2014)
 * */

class ViewportSurface{
public:
    ViewportSurface() {}
    virtual ~ViewportSurface() {}
   virtual Viewport* CreateViewport(const ViewportProperties& properties) { return new Viewport(this,properties); }

};


#endif // VIEWPORTSURFACE_H
