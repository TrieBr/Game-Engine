#ifndef QTTEXTUREPAGE_H
#define QTTEXTUREPAGE_H

#include "TexturePage.h"
#include <QPixmap>

/*
 * TexturePage for the QT back-end.
 * Author: Brad Triebwasser (04/2014)
 * */

class QTTexturePage : public TexturePage
{
public:
    //Create texture page from data
    QTTexturePage(char* data, unsigned int len);    //Load Texture page from data
    ~QTTexturePage();
    //Get width of texture page
    virtual int GetWidth() override;
    //Get height of texture page
    virtual int GetHeight() override;
    //Return raw texture pointer (QPixmap)
    QPixmap* GetTextureData();
private:
    QPixmap*            textureData;    //Texture data
};

#endif // QTTEXTUREPAGE_H
