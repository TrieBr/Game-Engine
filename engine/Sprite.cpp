#include "Sprite.h"
#include "VirtualFile.h"
#include "TexturePageManager.h"
#include "Renderer.h"
#include "Logger.h"
#include <cstdlib>
#include <cmath>

Sprite::Sprite()
    :Asset(), texturePageManager(NULL), origin(16,16),dimensions(0,0)
{
}

Sprite::~Sprite()
{

}
//Load the sprite from virtual file
bool Sprite::Load(VirtualFile* file)
{
    if (!texturePageManager) {
        Logger::Warn("Sprite::Load : Cannot load sprite; No texture page manager assigned.");
        return false;

    }
    //Attempt to load .sprbin file
    if (LoadSpriteBinary(file)) return true;
    /*
     * Here we read the entire file (into a buffer) and create a new texture page for the individual sprite
     * And set it as the first subimage.
     * */
    unsigned int len = file->Size();
    char* buffer = new char[len];
    file->Read(buffer,len);
    std::shared_ptr<TexturePage> newPage = texturePageManager->CreateTexturePage(buffer,len);
    delete[] buffer;
    Sprite_Subimage subimg;
    subimg.SetTexturePage(newPage);
    subimages.push_back(subimg);
    return true;
}

//Load a spritebin file (.sprbin file)
bool Sprite::LoadSpriteBinary(VirtualFile* file) {
    int magicnum = file->Read<int>();
    if (magicnum!=0x2CF1FC7) {
        file->Seek(VSEEK_SET,0);
        return false;
    }
    int width = file->Read<int>();
    int height = file->Read<int>();
    dimensions = Size(width,height);
    unsigned int subimageCount = file->Read<unsigned int>();
    for (unsigned int i=0; i<subimageCount; i++) {
        Sprite_Subimage subimg;
        int texSheetNum = file->Read<int>();    //Texture sheet number
        int tex_x = file->Read<int>();          //Texture x position
        int tex_y = file->Read<int>();          //Texture y position
        int tex_w = file->Read<int>();          //Texture width
        int tex_h = file->Read<int>();          //Texture height
        int xOffset = file->Read<int>();        //Texture x offset
        int yOffset = file->Read<int>();        //Texture y offset
        subimg.SetTexturePage(texturePageManager->GetTexturePage(texSheetNum),
                              tex_w,tex_h,tex_x,tex_y, tex_w, tex_h,xOffset, yOffset);
        subimages.push_back(subimg);
    }
    return true;

}

//Set texture page manager (for loading)
void Sprite::SetTexturePageManager(TexturePageManager* mgr)
{
    texturePageManager = mgr;
}

//Override Drawable::Draw
void Sprite::Draw(Renderer* renderer,const Pointf& point)
{
    if (!subimages.empty())
        subimages.at(0).Draw(renderer,point); //Draw the first subimage
}

//Draw subimg
void Sprite::Draw(Renderer* renderer,const Pointf& point, int subimg)
{
    if ((unsigned int)subimg>=subimages.size()) subimg = subimg % subimages.size();
    subimages.at(subimg).Draw(renderer,point);
}

//Draw at an angle
void Sprite::Draw(Renderer* renderer,const Pointf& point, int subimg, float angle)
{
    if ((unsigned int)subimg>=subimages.size()) subimg = subimg % subimages.size();
    if (angle>360) angle = (angle/360.0f) + fmod(angle,360.0f);
    renderer->PushTransform();
    renderer->Translate(Pointf(point.X()+origin.X(),point.Y()+origin.Y()));
    renderer->Rotate(angle);
    subimages.at(subimg).Draw(renderer,Pointf(-origin.X(),-origin.Y()));
    renderer->PopTransform();
}

//Draw scaled
void Sprite::Draw(Renderer* renderer,const Pointf& point, int subimg, float xScale, float yScale)
{
    if ((unsigned int)subimg>=subimages.size()) subimg = subimg % subimages.size();
    renderer->PushTransform();
    renderer->Translate(Pointf(point.X()+origin.X(),point.Y()+origin.Y()));
    renderer->Scale(xScale,yScale);
    subimages.at(subimg).Draw(renderer,Pointf(-origin.X(),-origin.Y()));
    renderer->PopTransform();
}

//Draw scaled and angled
void Sprite::Draw(Renderer* renderer,const Pointf& point, int subimg,  float angle, float xScale, float yScale) {
    if ((unsigned int)subimg>=subimages.size()) subimg = subimg % subimages.size();
    if (angle>360) angle = (angle/360.0f) + fmod(angle,360.0f);
    renderer->PushTransform();
    renderer->Translate(Pointf(point.X()+origin.X(),point.Y()+origin.Y()));
    renderer->Rotate(angle);
    renderer->Scale(xScale,yScale);
    subimages.at(subimg).Draw(renderer,Pointf(-origin.X(),-origin.Y()));
    renderer->PopTransform();
}
