#include "QTTexturePageManager.h"
#include "QTTexturePage.h"
#include "QTVirtualFile.h"
#include "AssetManager.h"

QTTexturePageManager::QTTexturePageManager()
    :TexturePageManager()
{

}


//Create a new texture page
std::shared_ptr<TexturePage> QTTexturePageManager::CreateTexturePage(char* data, int len) {
    return std::make_shared<QTTexturePage>(data,len);
}

void QTTexturePageManager::LoadTexturePages(AssetManager* assetManager) {
    VirtualFile* file = assetManager->FetchVirtualFile("://sheet0.png");
    char* buff = new char[file->Size()];
    file->Read(buff,file->Size());
    std::shared_ptr<TexturePage> newPage = CreateTexturePage(buff,file->Size());
    delete[] buff;
    texturePages.push_back(newPage);
}
