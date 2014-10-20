#include "QTAudioVoice.h"
#include "QTIODeviceAudioStreamAdapter.h"
#include <QDebug>

QTAudioVoice::QTAudioVoice() : AudioVoice()
{
    QAudioFormat format;
    // Set up the format, eg.
    format.setSampleRate(44100);
    format.setChannelCount(2);
    format.setSampleSize(16);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::SignedInt);
    output = new QAudioOutput(format,NULL);



}

//Start the Voice
void QTAudioVoice::Start() {
    AudioStream* input = GetInputStream();
    if (input) {
        QTIODeviceAudioStreamAdapter *adapter = new QTIODeviceAudioStreamAdapter(input);
        output->start(adapter);
        qDebug() << "period: " << output->periodSize();
    }
}
