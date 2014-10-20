#include "AudioVoice.h"

AudioVoice::AudioVoice()
{
}

//Attach an audio stream to play on this Voice
bool AudioVoice::AttachAudioStream(AudioStream* stream) {
    inputStream = stream;
    Start();
    return true;
}

//Get the input stream for this Voice
AudioStream* AudioVoice::GetInputStream() {
    return inputStream;
}
