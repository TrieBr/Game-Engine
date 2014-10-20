#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include "Sprite.h"
#include <string>
#include <memory>

/*
 * Abstract class used to fetch assets and virtual files based on name.
 * Author: Brad Triebwasser (04/2014)
 * */

class TexturePageManager;
class VirtualFile ;
class AssetManager {
public:
    AssetManager();
    virtual ~AssetManager();
    //Fetch a virtual file for the specified asset name
    virtual VirtualFile* FetchVirtualFile(const std::string& assetName) = 0;

    /*Asset Loaders*/
    virtual std::shared_ptr<Sprite> LoadSprite(const std::string& assetName);
protected:
    //Load all the texture pages
    void LoadTexturePages();
protected:
    TexturePageManager*     texturePageManager;     //Pointer to a texture page manager
private:


};


#endif // ASSETMANAGER_H
