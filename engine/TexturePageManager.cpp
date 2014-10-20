#include "TexturePageManager.h"
#include "Logger.h"

TexturePageManager::TexturePageManager()
{
}
TexturePageManager::~TexturePageManager()
{

}


//Get a Texture page by index
std::shared_ptr<TexturePage> TexturePageManager::GetTexturePage(int index)
{
    if ((unsigned int)index>=texturePages.size()) {
        Logger::Error("Trying to access invalid texture page index.");
        throw std::exception();
    }
    return texturePages.at(0);
}
