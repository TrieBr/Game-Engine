#ifndef SPRITE_H
#define SPRITE_H

#include "Asset.h"
#include "Drawable.h"
#include "Sprite_Subimage.h"
#include "Size.h"
#include <vector>

/*
 * Represents a series of subimages (bitmaps) and other properties that make up a Sprite.
 * Author: Brad Triebwasser (04/2014)
 * */

class TexturePageManager;
class Sprite : public Asset, public Drawable
{
public:
    Sprite();
    ~Sprite();
    //Load the sprite from virtual file
    virtual bool Load(VirtualFile* file);
    //Load a spritebin file
    bool LoadSpriteBinary(VirtualFile* file);
    //Set texture page manager (for loading)
    void SetTexturePageManager(TexturePageManager* mgr);
    //Override Drawable::Draw
    virtual void Draw(Renderer* renderer,const Pointf& point) override;
    //Draw subimg
    virtual void Draw(Renderer* renderer,const Pointf& point, int subimg);
    //Draw subimage at an angle
    virtual void Draw(Renderer* renderer,const Pointf& point,int subimg, float angle);
    //Draw subimage scaled
    virtual void Draw(Renderer* renderer,const Pointf& point,int subimg,  float xScale, float yScale);
    //Draw subimage scaled and angled
    virtual void Draw(Renderer* renderer,const Pointf& point, int subimg, float angle, float xScale, float yScale);
private:
    std::vector<Sprite_Subimage>    subimages;          //Subimages for the sprite
    TexturePageManager*             texturePageManager; //Texture Page manager
    Pointf                          origin;             //Sprite origin
    Size                            dimensions;          //Sprite dimensions
};

#endif // SPRITE_H
