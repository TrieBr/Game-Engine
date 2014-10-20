#ifndef QTASSETMANAGER_H
#define QTASSETMANAGER_H

#include "AssetManager.h"

/*
 * Asset Manager for the QT back-end.
 * Author: Brad Triebwasser (04/2014)
 * */

class QTAssetManager : public AssetManager
{
public:
    QTAssetManager();
    ~QTAssetManager();
    //Fetch virtual file for specified asset name
    virtual VirtualFile* FetchVirtualFile(const std::string& assetName) override;
};

#endif // QTASSETMANAGER_H
