#include "QTIODeviceAudioStreamAdapter.h"

QTIODeviceAudioStreamAdapter::QTIODeviceAudioStreamAdapter(AudioStream *stream) :
    QIODevice(0)
{
    audioStream = stream;
    setOpenMode(QIODevice::ReadOnly);
}
