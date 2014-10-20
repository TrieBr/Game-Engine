#include "QTAssetManager.h"
#include "QTVirtualFile.h"
#include "QTTexturePageManager.h"
#include "Logger.h"

QTAssetManager::QTAssetManager()
    :AssetManager()
{
    texturePageManager = new QTTexturePageManager();
    this->LoadTexturePages();
}

QTAssetManager::~QTAssetManager()
{

}

VirtualFile* QTAssetManager::FetchVirtualFile(const std::string& assetName) {

    QTVirtualFile *newfile = new QTVirtualFile();
    QFile* qFile = new QFile(assetName.c_str());
    if (!qFile->open(QIODevice::ReadOnly)) {
        Logger::Warn("QFile::open failed on asset: \"%s\"", assetName.c_str());
        delete qFile;
        delete newfile;
        return NULL;
    }
    newfile->SetQTFile(qFile);
    return newfile;
}
