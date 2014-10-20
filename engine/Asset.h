#ifndef ASSET_H
#define ASSET_H

/*
 * Abstract class used to represent an individual asset (image, audio or other data).
 * Author: Brad Triebwasser (04/2014)
 * */

class VirtualFile;
class Asset {
public:
    Asset() : isValid(false) {}
    virtual ~Asset() {}
    //Load the asset from a virtual file
    virtual bool Load(VirtualFile* file) = 0;
    //Returns if the asset is valid (ready to use)
    bool IsValid() { return isValid; }
protected:
    bool isValid;       //Is the asset valid (ready to use)
};


#endif // ASSET_H
