#ifndef FILEDATASTREAM_H
#define FILEDATASTREAM_H

#include <QFile>

class FileDataStream : public QFile
{
public:
    FileDataStream(const QString &filename) : QFile(filename) {}

    template <class T>
    unsigned int Write(T val) {
        T buf = val;
        return this->write((char*)&buf,sizeof(T));
    }
};

#endif // FILEDATASTREAM_H
