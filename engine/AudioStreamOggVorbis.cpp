#include "AudioStreamOggVorbis.h"
#include <cstring>
#include "unused.h"

#define MIN(x, y) (((x) < (y)) ? (x) : (y))

static size_t vorbis_read(void *ptr, size_t size, size_t nmemb, void *datasource) {
    VirtualFile* t = (VirtualFile*)datasource;
    return t->Read((char*)ptr,size*nmemb);
}
static int  vorbis_seek(void *datasource, ogg_int64_t offset, int whence) {
    VirtualFile* t = (VirtualFile*)datasource;
    if (whence==SEEK_SET) {
        t->Seek(VSEEK_SET,(long)offset);
    }
    if (whence==SEEK_CUR) {
        t->Seek(VSEEK_CUR,(long)offset);
    }
    if (whence==SEEK_END) {
        t->Seek(VSEEK_END,(long)offset);
    }
    return -1;
}
static int vorbis_close(void *datasource) {
    UNUSED(datasource);
    // VirtualFile* t = (VirtualFile*)datasource;
     return 1;
}
static long  vorbis_tell(void *datasource) {
    VirtualFile* t = (VirtualFile*)datasource;
    return t->Tell();
}



AudioStreamOggVorbis::AudioStreamOggVorbis()
    :buffer(NULL)
{
}

AudioStreamOggVorbis::~AudioStreamOggVorbis() {
    if (buffer)
        delete buffer;
}

//Open the source for streaming
bool AudioStreamOggVorbis::Open(VirtualFile* streamSource) {
    ov_callbacks s;
    s.read_func = vorbis_read;
    s.seek_func = vorbis_seek;
    s.close_func = vorbis_close;
    s.tell_func = vorbis_tell;
    eof = false; //Set EOF flag to false
    if(ov_open_callbacks(streamSource, &vf, NULL, 0,s) < 0) { //Open the vorbis stream
        return false;
    }
    vorbis_info *vi=ov_info(&vf,-1);
    SetChannelCount(vi->channels);
    SetSampleRate(vi->rate);
    SetSampleSize(16);
    SetByteOrder(LittleEndian);
    SetSampleType(SignedInt);
    buffer = new RingBuffer<char>(65536);
        DecodeChunk(4096*5);
    return true;
}

//Read audio data from the stream
unsigned int AudioStreamOggVorbis::Read(char* buf, unsigned int len) {
    if (eof) return 0;
    long l  = buffer->Read(buf,len);
    DecodeChunk(4096*3);
    return l;
}

//Close the stream
void AudioStreamOggVorbis::Close() {
    ov_clear(&vf);
}

unsigned int AudioStreamOggVorbis::DecodeChunk(unsigned int chunkSize) {
    unsigned int remaining = chunkSize;
    char pcmBuffer[4096];
    while (remaining>0) {
        unsigned int bufferLength = remaining;
        if (remaining>4096) {
            bufferLength = 4096;
        }
        if (buffer->SpaceRemaining()<bufferLength) break;
        long ret = ov_read(&vf,pcmBuffer,bufferLength,&current_section);
        if (ret==0) {
            eof = true;
            break;
        }else{

            buffer->Write(pcmBuffer,ret);
            remaining -= ret;
        }
    }
    return chunkSize-remaining;
}

