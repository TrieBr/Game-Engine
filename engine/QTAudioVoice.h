#ifndef QTAUDIOVOICE_H
#define QTAUDIOVOICE_H

#include "AudioVoice.h"
#include <QAudioOutput>


/*
 * QT Back-end for Audio Voice
 * Author: Brad Triebwasser (04/2014)
 * */

class QTAudioVoice : public AudioVoice
{
public:
    QTAudioVoice();
protected:
    //Start the Voice
    virtual void Start() override;
private:
    QAudioOutput*   output;     //Audio output handler
};

#endif // QTAUDIOVOICE_H
