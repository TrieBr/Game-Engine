#ifndef AUDIOSTREAMOGGVORBIS_H
#define AUDIOSTREAMOGGVORBIS_H

#include "AudioStream.h"
#include "tremor/ivorbiscodec.h"
#include "tremor/ivorbisfile.h"
#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
#endif
#include "RingBuffer.h"

/*
 * Audio Stream from an OGG Vorbis file.
 * Author: Brad Triebwasser (04/2014)
 * */

class AudioStreamOggVorbis : public AudioStream
{
public:
    AudioStreamOggVorbis();
    ~AudioStreamOggVorbis();
    //Open the source for streaming
    virtual bool Open(VirtualFile* streamSource) override;
    //Read audio data from the stream
    virtual unsigned int Read(char* buf, unsigned int len) override;
    //Close the stream
    virtual void Close() override;
protected:
    //Buffer (decode) more data
    unsigned int DecodeChunk(unsigned int chunkSize);
private:
    RingBuffer<char>*   buffer;             //Circular buffer for audio buffering
    OggVorbis_File      vf;                 //Vorbis File handle
    bool                eof;                //EOF flag
    int                 current_section;    //Current section in file
};

#endif // AUDIOSTREAMOGGVORBIS_H
