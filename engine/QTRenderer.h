#ifndef QTRENDERER_H
#define QTRENDERER_H

#include "Renderer.h"
#include <QPainter>
#include <stack>

/*
 * Renderer for the QT back-end.
 * Author: Brad Triebwasser (04/2014)
 * */

class TexturePage;
class QTRenderer : public Renderer
{
public:
    QTRenderer(QPainter* painter);
    //Set clipping rectangle
    virtual void SetClipRect(const Pointf& point, const Sizef& size) override;
    //Push current transformation onto stack
    virtual void PushTransform() override;
    //Pop (and apply) transformation from stack
    virtual void PopTransform(bool combine = false) override;
    //Reset transformation
    virtual void ResetTransform() override;
    //Translation transformation
    virtual void Translate(const Pointf& point) override;
    //Scale transformation
    virtual void Scale(float x, float y) override;
    //Rotation transformation
    virtual void Rotate(float angle) override;

    //Draw a filled rectangle
    virtual void DrawFilledRectangle(const Pointf& point, const Sizef& size, const Color& fillColor) override;
    //Draw a rectangle outline
    virtual void DrawRectangle(const Pointf& point, const Sizef& size, const Color& outlineColor, float thickness = 1) override;
    //Draw a line
    virtual void DrawLine(const Pointf& p1, const Pointf& p2) override;
    //Draw region of a texture
    virtual void DrawTextureRegion(TexturePage* tex, int srcX, int srcY, int srcW, int srcH, int destX, int destY, int destW, int destH) override;

private:
    QPainter*               painter;        //QT Painter
    std::stack<QTransform>  transformStack; //Stack for pushing/popping transformations
};

#endif // QTRENDERER_H
