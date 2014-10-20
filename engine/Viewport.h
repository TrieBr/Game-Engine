#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <vector>
#include "SceneEntity.h"
#include "ViewportProperties.h"

/*
 * Viewport represents a portion of the ViewPortSurface (usually a display window) that will render a region of a Scene.
 * Author: Brad Triebwasser (04/2014)
 * */

class Drawable;
class ViewportSurface;
class Scene;
class Viewport
{
public:
    Viewport(ViewportSurface* targetSurface, const ViewportProperties& properties);
    //Render specified entitiesin this viewport
    void Render(Renderer* renderer, const std::vector<SceneEntity*> &entities);
    //Render scene in this viewport
    void Render(Renderer* renderer, Scene* scene);

private:
    //Set the transformations on the renderer for this viewport
    void TransformRenderer(Renderer* renderer);
private:
    ViewportSurface*    targetSurface;      //Target viewport surface
    ViewportProperties  properties;         //Viewport Properties

};

#endif // VIEWPORT_H
