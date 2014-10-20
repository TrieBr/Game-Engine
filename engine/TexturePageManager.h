#ifndef TEXTUREPAGEMANAGER_H
#define TEXTUREPAGEMANAGER_H

#include <memory>
#include <vector>

/*
 * Texture Page Manager handles the management and creation of Texture pages.
 * Author: Brad Triebwasser (04/2014)
 * */

class AssetManager;
class TexturePage;
class TexturePageManager
{
public:
    TexturePageManager();
    virtual ~TexturePageManager();
    //Get a Texture page by index
    std::shared_ptr<TexturePage> GetTexturePage(int index);
    //Create a new texture page
    virtual std::shared_ptr<TexturePage> CreateTexturePage(char* data, int len)= 0;
    //Load the texture pages from the asset file
    virtual void LoadTexturePages(AssetManager* assetManager) = 0;
protected:
    std::vector<std::shared_ptr<TexturePage> >  texturePages;   //Loaded texture pages
};

#endif // TEXTUREPAGEMANAGER_H
