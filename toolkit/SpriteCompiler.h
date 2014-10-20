#ifndef SPRITECOMPILER_H
#define SPRITECOMPILER_H

#include "SpriteDefinition.h"
#include <string>
#include <vector>

class SpriteCompiler
{
public:
    SpriteCompiler();
    //Compile the sprites into binaries in the specified directories
    void Compile(const std::string& xmlFile, const std::string& outputDir);
private:
    //Parse the xml file into sprite data
    std::vector<SpriteDefinition*> ParseXml(const std::string& xmlFile);
    //Write the sprite binary files
    void WriteSpriteBinaries(std::vector<SpriteDefinition*>& sprites, const std::string& outputDir);
};

#endif // SPRITECOMPILER_H
