#ifndef QTIODEVICEAUDIOSTREAMADAPTER_H
#define QTIODEVICEAUDIOSTREAMADAPTER_H

#include <QIODevice>
#include "AudioStream.h"
#include "unused.h"
/*
 * Adapter class so an AudioStream can be used as a QIODevice required by a QTAudioVoice
 * Author: Brad Triebwasser (04/2014)
 * */

class QTIODeviceAudioStreamAdapter : public QIODevice
{
    Q_OBJECT
public:
    explicit QTIODeviceAudioStreamAdapter(AudioStream* stream);
    virtual qint64 readData(char *data, qint64 maxlen) {
        return audioStream->Read(data,maxlen);
    }
    virtual qint64 writeData(const char *data, qint64 len) {
        UNUSED(data);
        UNUSED(len);
        return 0;
    }

signals:

public slots:

private:
    AudioStream*    audioStream;    //Source of the audio

};

#endif // QTIODEVICEAUDIOSTREAMADAPTER_H
