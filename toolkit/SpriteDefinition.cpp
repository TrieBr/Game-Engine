#include "SpriteDefinition.h"
#include <QImage>

SpriteSubimageDefinition::SpriteSubimageDefinition(const std::string& filename)
    :filename(filename)
{
    QImage p;
    if (p.load(filename.c_str())) {
        imageSize = Rectangle(0,0,p.width(),p.height());
    }
}

 void SpriteSubimageDefinition::SetTexInfo(int tex_sheet_index,int tex_x, int tex_y, int tex_w, int tex_h, int x, int y)
 {
     this->tex_sheetNum = tex_sheet_index;
     this->tex_x = tex_x;
     this->tex_y = tex_y;
     this->tex_w = tex_w;
     this->tex_h = tex_h;
     this->x = x;
     this->y = y;
 }

 int SpriteSubimageDefinition::GetTextureSheetNum()
 {
     return tex_sheetNum;
 }

 int SpriteSubimageDefinition::GetTexX()
 {
     return tex_x;
 }

 int SpriteSubimageDefinition::GetTexY()
 {
     return tex_y;
 }

 int SpriteSubimageDefinition::GetTexW()
 {
     return tex_w;
 }

 int SpriteSubimageDefinition::GetTexH()
 {
     return tex_h;
 }

 int SpriteSubimageDefinition::GetX()
 {
     return x;
 }

 int SpriteSubimageDefinition::GetY()
 {
     return y;
 }




 SpriteDefinition::SpriteDefinition(const std::string& name)
     :name(name),originX(0),originY(0),width(0),height(0)
 {

 }

 SpriteDefinition::~SpriteDefinition()
 {

}

void SpriteDefinition::AddSubimage(SpriteSubimageDefinition* subimage)
{
    subimages.push_back(subimage);
}

//Get subimage count
unsigned int SpriteDefinition:: GetSubimageCount()
{
    return subimages.size();
}

//Get specified subimage
SpriteSubimageDefinition* SpriteDefinition::GetSubimage(int index)
{
    if ((unsigned int)index>=subimages.size()) return NULL;
    return subimages.at(index);
}

std::string SpriteDefinition::GetName()
{
    return name;
}
//Get width
int SpriteDefinition::GetWidth()
{
    return width;
}

//Get height
int SpriteDefinition::GetHeight()
{
    return height;
}

void SpriteDefinition::SetOrigin(int x, int y)
{
       originX = x;
       originY = y;
}

void SpriteDefinition::SetSize(int w, int h)
{
    width = w;
    height = h;
}
