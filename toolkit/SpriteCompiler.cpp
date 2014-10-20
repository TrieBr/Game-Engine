#include "SpriteCompiler.h"
#include "SpritePackager.h"
#include "SpriteDefinition.h"
#include "FileDataStream.h"
#include <QDomDocument>
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QDir>


SpriteCompiler::SpriteCompiler()
{
}

//Compile the sprites into the specified folder
void SpriteCompiler::Compile(const std::string& xmlFile, const std::string& outputDir)
{
    std::vector<SpriteDefinition*> sprites = ParseXml(xmlFile);
    SpritePackager packer;
    for (std::vector<SpriteDefinition*>::iterator i = sprites.begin(); i!=sprites.end(); i++) {
                packer.AddSprite(*i);
    }
    packer.Pack(QString(outputDir.c_str()).append("/").append("sheet%1.png").toStdString());

    WriteSpriteBinaries(sprites,outputDir);
}

 //Parse the xml file into sprite data
 std::vector<SpriteDefinition*> SpriteCompiler::ParseXml(const std::string& xmlFile) {
     QDomDocument doc("spritedoc");
     QFile file(xmlFile.c_str());
     if (!file.open(QIODevice::ReadOnly))
         return  std::vector<SpriteDefinition*>();
     if (!doc.setContent(&file)) {
         file.close();
         return  std::vector<SpriteDefinition*>();
     }
     file.close();

     std::vector<SpriteDefinition*> sprites;

     QDomElement rootElem = doc.documentElement();
     for (QDomElement spriteElem = rootElem.firstChildElement("sprite"); !spriteElem.isNull(); spriteElem=spriteElem.nextSiblingElement())
     { //For each sprite
         QString spriteName = spriteElem.attribute("name");
         int spriteW =   spriteElem.firstChildElement("width").text().toInt();
         int spriteH =   spriteElem.firstChildElement("height").text().toInt();

         SpriteDefinition* newSprite = new SpriteDefinition(spriteName.toStdString());
         newSprite->SetSize(spriteW,spriteH);

         for (QDomElement imgElem = spriteElem.firstChildElement("image"); !imgElem.isNull(); imgElem=imgElem.nextSiblingElement())
         { //For each subimage
             QString imagePath = imgElem.attribute("src");
             imagePath.prepend(QFileInfo(xmlFile.c_str()).dir().absolutePath().append("/"));
             qDebug() << imagePath;
             SpriteSubimageDefinition* subimage = new SpriteSubimageDefinition(imagePath.toStdString());
             newSprite->AddSubimage(subimage);
         }
         sprites.push_back(newSprite);
     }
     return sprites;
 }

 //Write the sprite binary files
 void SpriteCompiler::WriteSpriteBinaries(std::vector<SpriteDefinition*>& sprites,const std::string& outputDir)
 {
     for (std::vector<SpriteDefinition*>::iterator i = sprites.begin(); i!=sprites.end(); i++) {    //For each sprite
         SpriteDefinition* spr = *i;
         FileDataStream file(QString(outputDir.c_str()).append("/").append(spr->GetName().c_str()).append(".sprbin"));
         if (!file.open(QIODevice::WriteOnly)) {
             qDebug() << "Failed to open sprite file!";
             throw std::exception();
         }
         int magicnum = 0x2CF1FC7;
         file.Write<int>(magicnum);                         //Write magic number (int)
         file.Write<int>(spr->GetWidth());                  //Width of sprite (int)
         file.Write<int>(spr->GetHeight());                 //Height of sprite (int)
         file.Write<unsigned int>(spr->GetSubimageCount()); //Number of subimages (uint32)
         for (unsigned int i=0; i<spr->GetSubimageCount(); i++) {//For each subimage
             SpriteSubimageDefinition *subimg = spr->GetSubimage(i);
             file.Write<int>(subimg->GetTextureSheetNum()); //Texture sheet number (int)
             file.Write<int>(subimg->GetTexX());            //Texture x pos (int)
             file.Write<int>(subimg->GetTexY());            //Texture y pos (int)
             file.Write<int>(subimg->GetTexW());            //Texture width (int)
             file.Write<int>(subimg->GetTexH());            //Texture height (int)
             file.Write<int>(subimg->GetX());               //X offset (int)
             file.Write<int>(subimg->GetY());               //Y offset (int)
         }
         file.close();
     }

 }
