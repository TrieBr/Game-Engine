#ifndef SPRITE_SUBIMAGE_H
#define SPRITE_SUBIMAGE_H

#include "Point.h"
#include <memory>

/*
 * Represents a sub image for a sprite.
 * The subimage bitmap is a region of a TexturePage.
 * Author: Brad Triebwasser (04/2014)
 * */

class Renderer;
class TexturePage;
class Sprite_Subimage
{
public:
    Sprite_Subimage();
    //Set the texture page (and region) this subimage is on
    void SetTexturePage(std::shared_ptr<TexturePage>, int tex_w, int tex_h,int tex_x, int tex_y, int w, int h, int x, int y);
    //Set the texture page this subimage is on (uses whole page)
    void SetTexturePage(std::shared_ptr<TexturePage>);
    //Draw to renderer
    virtual void Draw(Renderer* renderer,const Pointf& point);
private:
    std::shared_ptr<TexturePage>    texturePage;       //Texture page this image is on
    int tex_width;                      //Width on the texture page
    int tex_height;                     //Height on the texture page
    int tex_x;                          //x coordinate on the texture page
    int tex_y;                          //y coordinate on the texture page
    int width;                          //Width of the submimage
    int height;                         //height of the subimage
    int x;                              //x position on the subimage of the texture region
    int y;                              //y position on the subimage of the texture region
};

#endif // SPRITE_SUBIMAGE_H
