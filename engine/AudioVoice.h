#ifndef AUDIOVOICE_H
#define AUDIOVOICE_H


/*
 * AudioVoice plays audio through a device (speakers)
 * Author: Brad Triebwasser (04/2014)
 * */

class AudioStream;
class AudioVoice
{
public:
    AudioVoice();
    //Attach an audio stream to play on this Voice
    bool AttachAudioStream(AudioStream* stream);
protected:
    //Start the Voice
    virtual void Start() = 0;
    //Get the input stream for this Voice
    AudioStream* GetInputStream();
private:
    AudioStream*        inputStream;    //Stream feeding data to this voice.
};

#endif // AUDIOVOICE_H
