#ifndef QTVIRTUALFILE_H
#define QTVIRTUALFILE_H

#include "VirtualFile.h"
#include <QFile>

/*
 * Virtual File for the QT back-end.
 * Author: Brad Triebwasser (04/2014)
 * */

class QTVirtualFile : public VirtualFile
{
public:
    QTVirtualFile();
    ~QTVirtualFile();
    //Set the underlying QFile
    void SetQTFile(QFile* file);
    //Seek to position in file
    virtual void Seek(SeekOrigin origin, int offset) override;
    //Return size of file
    virtual unsigned int Size() override;
    //Get read/write pointer position
    virtual unsigned int Tell() override;
    //Read data
    virtual unsigned int Read(char* ptr, unsigned int len) override;
    //Write data
    virtual unsigned int Write(char* ptr, unsigned int len) override;
private:
    QFile*      qtFile;         //Handle to the QT File.
};

#endif // QTVIRTUALFILE_H
