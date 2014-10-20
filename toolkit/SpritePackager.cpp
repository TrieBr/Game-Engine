#include "SpritePackager.h"
#include "Packer.h"
#include <QImage>
#include <QPainter>
#include <exception>

SpritePackager::SpritePackager()
{
}


//Add a sprite to be packed
void SpritePackager::AddSprite(SpriteDefinition* sprite)
{
    sprites.push_back(sprite);
}

//Perform the packing (texture sheet generation)
void SpritePackager::Pack(const std::string &filename)
{

    for (std::vector<SpriteDefinition*>::iterator i = sprites.begin(); i!=sprites.end(); i++) { //For each sprite
        SpriteDefinition* spr = (*i);
        for (unsigned img = 0; img<spr->GetSubimageCount(); img++) {    //For each submage
            SpriteSubimageDefinition* subimg = spr->GetSubimage(img);
            TextureSheet* sheet = NULL;
            Packer* fit = NULL;
            for (std::vector<TextureSheet*>::iterator t = textureSheets.begin(); t!=textureSheets.end(); t++) {
                    Packer* tFit = (*t)->BSPTree->Insert(subimg->GetImageRect());
                    if (tFit) {
                        fit = tFit;
                        sheet = *t;
                        break;
                    }
            }
            if (!fit) {
                sheet = CreateNewSheet(1024,1024);
                fit = sheet->BSPTree->Insert(subimg->GetImageRect());
            }
            if (fit) {
                subimg->SetTexInfo(GetSheetIndex(sheet),fit->GetRect().Left(),fit->GetRect().Top(),fit->GetRect().Width(),fit->GetRect().Height(),0,0);
                QImage subimage;
                subimage.load(subimg->GetFilename().c_str());
                QPainter painter(sheet->img);
                painter.drawImage(fit->GetRect().Left(),fit->GetRect().Top(),subimage);
            }else{
                throw std::exception();
            }
        }//End for each subimage
    }

    int c = 0;
    for (std::vector<TextureSheet*>::iterator t = textureSheets.begin(); t!=textureSheets.end(); t++) {
        (*t)->img->save(QString(filename.c_str()).arg(c));
        c++;
    }

}

TextureSheet* SpritePackager::CreateNewSheet(int w, int h)
{
    TextureSheet* sheet = new TextureSheet();
    sheet->img = new QImage(QSize(w,h),QImage::Format_ARGB32);
    sheet->img->fill(QColor(0,0,0,0));
    sheet->BSPTree = new Packer(w,h);
    textureSheets.push_back(sheet);
    return sheet;
}

//Get the index of specified sheet
int SpritePackager::GetSheetIndex(TextureSheet* sheet) {
    int c = 0;
    for (std::vector<TextureSheet*>::iterator i = textureSheets.begin(); i!=textureSheets.end(); i++) {
        if ((*i)=sheet) {
            return c;
        }
        c++;
    }
    return 0;
}
