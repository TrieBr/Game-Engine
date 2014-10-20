#ifndef SPRITEPACKAGER_H
#define SPRITEPACKAGER_H

#include <string>
#include <vector>
#include <map>
#include "SpriteDefinition.h"
#include "Rectangle.h"
#include <QImage>
#include "Packer.h"


struct TextureSheet {
    QImage* img;
    Packer* BSPTree;
};


class PackedSprite;
class SpritePackager
{
public:
    SpritePackager();
    //Add a sprite to be packed
    void AddSprite(SpriteDefinition* sprite);
    //Perform the packing (texture sheet generation)
    void Pack(const std::string &filename);
private:
    //Create a new texture sheet
    TextureSheet* CreateNewSheet(int w, int h);
    //Get the index of specified sheet
    int GetSheetIndex(TextureSheet* sheet);
private:
    std::vector<SpriteDefinition*>      sprites;        //Sprites to be packed
    std::vector<TextureSheet*>          textureSheets;  //List of texture sheets


};

#endif // SPRITEPACKAGER_H
