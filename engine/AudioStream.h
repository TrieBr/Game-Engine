#ifndef AUDIOSTREAM_H
#define AUDIOSTREAM_H

#include "VirtualFile.h"


/*
 * Abstract class that streams audio at a specified format (sample rate, channel count, etc)
 * Author: Brad Triebwasser (04/2014)
 * */

enum AudioStreamByteOrder {
    LittleEndian,
    BigEndian
};
enum AudioStreamSampleType {
    SignedInt,
    UnsignedInt,
    Float
};

class AudioStream
{
public:
    AudioStream();
    //Open the source for streaming
    virtual bool Open(VirtualFile* streamSource) = 0;
    //Read audio data from the stream
    virtual unsigned int Read(char* buf, unsigned int len) = 0;
    //Close the stream
    virtual void Close() = 0;

    //Get the sample rate
    unsigned int GetSampleRate();
    //Get the number of channels
    unsigned char GetChannelCount();
    //Get the size (in bits) of the samples
    unsigned char GetSampleSize();
    //Get the order of bytes
    AudioStreamByteOrder GetByteOrder();
    //Get the data format of the sample
    AudioStreamSampleType GetSampleType();
protected:
    //Set the sample rate
    void SetSampleRate(unsigned int rate);
    //Set the channel count
    void SetChannelCount(unsigned char num);
    //Set the sample size
    void SetSampleSize(unsigned char size);
    //Set the byte order
    void SetByteOrder(AudioStreamByteOrder order);
    //Set the sample data format
    void SetSampleType(AudioStreamSampleType type);
private:
    VirtualFile*            stream;         //VirtalFile to stream data from
    unsigned int            sampleRate;     //Sample rate of the audio
    unsigned char           channelCount;   //Number of channels
    unsigned char           sampleSize;     //Size (in bits) of the samples
    AudioStreamByteOrder    byteOrder;      //Byte order
    AudioStreamSampleType   sampleType;     //Type of data
};

#endif // AUDIOSTREAM_H
