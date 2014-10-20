#include "QTRenderer.h"
#include "QTTexturePage.h"

QTRenderer::QTRenderer(QPainter* painter)
    :painter(painter)
{

}

void QTRenderer::SetClipRect(const Pointf& point, const Sizef& size)
{
   painter->setClipRect(point.X(),point.Y(),size.W(),size.H());
}

void QTRenderer::PushTransform() {
    transformStack.push(painter->transform());
}

void QTRenderer::PopTransform(bool combine) {
    painter->setTransform(transformStack.top(),combine);
    transformStack.pop();
}


void QTRenderer::ResetTransform()
{
    painter->resetTransform();
}


void QTRenderer::Translate(const Pointf& point)
{
   painter->translate(point.X(),point.Y());
}
void QTRenderer::Scale(float x, float y) {
    painter->scale(x,y);
}
void QTRenderer::Rotate(float angle) {
    painter->rotate(angle);

}

void QTRenderer::DrawFilledRectangle(const Pointf& point, const Sizef& size, const Color& fillColor)
{
    painter->fillRect(point.X(),point.Y(),size.W(),size.H(),QBrush(QColor(fillColor.R(),fillColor.G(),fillColor.B(),fillColor.A())));
}

void QTRenderer::DrawRectangle(const Pointf& point, const Sizef& size, const Color& outlineColor, float thickness) {
    QPen p(QColor(outlineColor.R(),outlineColor.G(),outlineColor.B(),outlineColor.A()));
         p.setWidth((int)thickness);
    painter->setPen(p);
    painter->drawRect(point.X(),point.Y(),size.W(),size.H());
}

void QTRenderer::DrawLine(const Pointf& p1, const Pointf& p2)
{
    painter->drawLine((int)p1.X(),(int)p1.Y(),(int)p2.X(),(int)p2.Y());
}

//Draw region of a texture
void QTRenderer::DrawTextureRegion(TexturePage* tex, int srcX, int srcY, int srcW, int srcH, int destX, int destY, int destW, int destH) {
    QTTexturePage *texture = (QTTexturePage*)tex;
    QPixmap* pixmap = texture->GetTextureData();
    painter->drawPixmap(destX,destY,destW,destH,*pixmap,srcX,srcY,srcW,srcH);
}
