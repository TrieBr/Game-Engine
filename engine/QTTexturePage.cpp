#include "QTTexturePage.h"
#include "QTRenderer.h"

//Load Texture page from data
QTTexturePage::QTTexturePage(char* data, unsigned int len)
    :TexturePage(data,len), textureData(NULL)
{
    textureData = new QPixmap();
    textureData->loadFromData((uchar*)data,len);
}

QTTexturePage::~QTTexturePage()
{
    if (textureData) delete textureData;
}

int QTTexturePage::GetWidth() {
    if (textureData)
        return textureData->width();
    return 0;
}
int QTTexturePage::GetHeight() {
    if (textureData)
        return textureData->height();
    return 0;
}


//Return raw texture pointer
QPixmap* QTTexturePage::GetTextureData() {
    return textureData;
}
