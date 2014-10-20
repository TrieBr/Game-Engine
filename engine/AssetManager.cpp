#include "AssetManager.h"
#include "TexturePageManager.h"
#include "Logger.h"

AssetManager::AssetManager()
    :texturePageManager(NULL)
{

}

AssetManager::~AssetManager()
{
    if (texturePageManager) delete texturePageManager;
}

std::shared_ptr<Sprite> AssetManager::LoadSprite(const std::string& assetName)
{
    if (!texturePageManager) {
        Logger::Warn("AssetManager has no TexturePageManager (NULL), cannot load sprite: \"%s\"",assetName.c_str());
        return nullptr;
    }
    VirtualFile* file = FetchVirtualFile(assetName);
    std::shared_ptr<Sprite> newSprite = std::make_shared<Sprite>();
    newSprite->SetTexturePageManager(texturePageManager);
    if (!newSprite->Load(file)) {
        Logger::Warn("AssetManager failed to load sprite (Sprite::Load returned false)");
        return nullptr;
    }
    return newSprite;

}

void AssetManager::LoadTexturePages()
{
    if (texturePageManager)
        texturePageManager->LoadTexturePages(this);
}
