#ifndef QTTEXTUREPAGEMANAGER_H
#define QTTEXTUREPAGEMANAGER_H

#include "TexturePageManager.h"

/*
 * TexturePage Manager for the QT back-end.
 * Author: Brad Triebwasser (04/2014)
 * */


class AssetManager;
class QTTexturePageManager : public TexturePageManager
{
public:
    QTTexturePageManager();
    //Create a new texture page
    virtual std::shared_ptr<TexturePage> CreateTexturePage(char* data, int len) override;
protected:
    //Load texture pages
     virtual void LoadTexturePages(AssetManager* assetManager) override;
};

#endif // QTTEXTUREPAGEMANAGER_H
