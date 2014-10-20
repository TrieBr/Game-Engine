#include "AudioStream.h"

AudioStream::AudioStream()
{
}


//Get the sample rate
unsigned int AudioStream::GetSampleRate() {
    return sampleRate;
}

//Get the number of channels
unsigned char AudioStream::GetChannelCount() {
    return channelCount;
}

//Get the size (in bits) of the samples
unsigned char AudioStream::GetSampleSize() {
    return sampleSize;
}

//Get the order of bytes
AudioStreamByteOrder AudioStream::GetByteOrder() {
    return byteOrder;
}

//Get the data format of the sample
AudioStreamSampleType AudioStream::GetSampleType() {
    return sampleType;
}

//Set the sample rate
void AudioStream::SetSampleRate(unsigned int rate) {
    sampleRate = rate;
}

//Set the channel count
void AudioStream::SetChannelCount(unsigned char num) {
    channelCount = num;
}

//Set the sample size
void AudioStream::SetSampleSize(unsigned char size) {
    sampleSize = size;
}

//Set the byte order
void AudioStream::SetByteOrder(AudioStreamByteOrder order) {
    byteOrder = order;
}

//Set the sample data format
void AudioStream::SetSampleType(AudioStreamSampleType type) {
    sampleType = type;
}
