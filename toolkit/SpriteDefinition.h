#ifndef SPRITEDEFINITION_H
#define SPRITEDEFINITION_H

#include <vector>
#include <string>
#include "Rectangle.h"

class SpriteSubimageDefinition {
public:
    SpriteSubimageDefinition(const std::string& filename);
    //Get the image rectanle
    Rectangle GetImageRect() { return imageSize; }
    //Get the filename
    std::string GetFilename() { return filename; }
    //Set the texture information for this subimage
    void SetTexInfo(int tex_sheet_index, int tex_x, int tex_y, int tex_w, int tex_h, int x, int y);
    int GetTextureSheetNum();
    int GetTexX();
    int GetTexY();
    int GetTexW();
    int GetTexH();
    int GetX();
    int GetY();
private:
    std::string filename;   //Name of the file for the subimage
    Rectangle   imageSize;  //Size of the subimage
    int tex_sheetNum;       //Index of the texture sheet
    int tex_x;              //X position on texture sheet
    int tex_y;              //Y position on texture sheet
    int tex_w;              //Width on texture sheet
    int tex_h;              //Height on texture sheet
    int x;                  //x offset  on sprite
    int y;                  //y offset on sprite
};

class SpriteDefinition
{
public:
    SpriteDefinition(const std::string& name);
    virtual ~SpriteDefinition();
    //Add a subimage to the sprite
    void AddSubimage(SpriteSubimageDefinition* subimage);
    //Get subimage count
    unsigned int GetSubimageCount();
    //Get specified subimage
    SpriteSubimageDefinition* GetSubimage(int index);
    //Get name
    std::string GetName();
    //Get width
    int GetWidth();
    //Get height
    int GetHeight();
    //Set origin of the sprite
    void SetOrigin(int x, int y);
    //Set size of the sprite
    void SetSize(int w, int h);
private:
    std::string     name;           //Name of sprite
    std::vector<SpriteSubimageDefinition*> subimages;   //Subimages in the sprite
    int originX;                    //X origin of sprite
    int originY;                    //Y origin of sprite
    int width;                      //width of sprite
    int height;                     //height of sprite

};

#endif // SPRITEDEFINITION_H
