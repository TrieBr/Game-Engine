#include "Sprite_Subimage.h"
#include "TexturePage.h"
#include "Renderer.h"
#include <cstdlib>

Sprite_Subimage::Sprite_Subimage()
    :texturePage(NULL)
{
}
//Set the texture page (and region) this subimage is on
void Sprite_Subimage::SetTexturePage(std::shared_ptr<TexturePage> page, int tex_w, int tex_h,int tex_x, int tex_y, int w, int h, int x, int y)
{
    texturePage = page;
    tex_width = tex_w;
    tex_height = tex_h;
    this->tex_x = tex_x;
    this->tex_y = tex_y;
    width = w;
    height = h;
    this->x = x;
    this->y = y;
}
//Set the texture page this subimage is on (uses whole page)
void Sprite_Subimage::SetTexturePage(std::shared_ptr<TexturePage> page)
{
    SetTexturePage(page, page->GetWidth(), page->GetHeight(),0,0,page->GetWidth(), page->GetHeight(),0,0);
}

//Draw to renderer
void Sprite_Subimage::Draw(Renderer* renderer,const Pointf& point)
{
    renderer->DrawTextureRegion(texturePage.get(),tex_x,tex_y,tex_width,tex_height,(int)point.X(),(int)point.Y(),width,height);
}

