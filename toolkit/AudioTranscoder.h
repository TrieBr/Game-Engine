#ifndef AUDIOCONVERTER_H
#define AUDIOCONVERTER_H

#include <string>

class AudioTranscoder
{
public:
    AudioTranscoder(const std::string &inFile, const std::string &outFile);
    //Begin the transcoding process
    bool Transcode();

private:
private:
    std::string inFile;     //Filename of the input file
    std::string outFile;    //Filename of the output file
};

#endif // AUDIOCONVERTER_H
