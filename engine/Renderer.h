#ifndef RENDERER_H
#define RENDERER_H

#include "Point.h"
#include "Size.h"
#include "Color.h"
#include <stack>

/*
 * Renderer can have primative shapes drawn on it, or textures. Can also apply transformations to the renderer.
 * Author: Brad Triebwasser (04/2014)
 * */

class TexturePage;
class Renderer {
public:
    //Set clipping rectangle
    virtual void SetClipRect(const Pointf& point, const Sizef& size) = 0;
    //Push current transformation onto stack
    virtual void PushTransform() = 0;
    //Pop (and apply) transformation from the stack
    virtual void PopTransform(bool combine = false) = 0;
    //Reset the transformation
    virtual void ResetTransform() = 0;
    //Translation transformation
    virtual void Translate(const Pointf& point) = 0;
    //Scale transformation
    virtual void Scale(float x, float y) = 0;
    //Rotation transformation
    virtual void Rotate(float angle) = 0;

    //Draw a filled rectangle
    virtual void DrawFilledRectangle(const Pointf& point, const Sizef& size, const Color& fillColor) = 0;
    //Draw a rectangle outline
    virtual void DrawRectangle(const Pointf& point, const Sizef& size, const Color& outlineColor, float thickness = 1) = 0;
    //Draw a line
    virtual void DrawLine(const Pointf& p1, const Pointf& p2) = 0;
    //Draw region of a texture
    virtual void DrawTextureRegion(TexturePage* tex, int srcX, int srcY, int srcW, int srcH, int destX, int destY, int destW, int destH) = 0;
};



#endif // RENDERER_H
