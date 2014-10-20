#include "QTVirtualFile.h"
#include "Logger.h"

QTVirtualFile::QTVirtualFile()
    :qtFile(NULL)
{

}

QTVirtualFile::~QTVirtualFile()
{

}

void QTVirtualFile::SetQTFile(QFile* file)
{
    if (qtFile) {
       Logger::Warn("QTVirtualFile: Setting QFile, deleting existing one.");
       delete qtFile;
    }
    qtFile = file;
}


void QTVirtualFile::Seek(SeekOrigin origin, int offset)
{
    if (!qtFile) return;
    switch (origin){
        case VSEEK_SET: qtFile->seek(offset); break;
        case VSEEK_CUR: qtFile->seek(qtFile->pos()+offset); break;
        case VSEEK_END: qtFile->seek(qtFile->size()-offset); break;
    }
}

unsigned int QTVirtualFile::Size() {
    if (!qtFile) return 0;
    return qtFile->size();
}

unsigned int QTVirtualFile::Tell()
{
    if (!qtFile) return 0;
    return (unsigned int)qtFile->pos();
}

unsigned int QTVirtualFile::Read(char* ptr, unsigned int len)
{
    if (!qtFile) return 0;
    return (unsigned int)qtFile->read(ptr,len);
}

unsigned int QTVirtualFile::Write(char* ptr, unsigned int len)
{
    if (!qtFile) return 0;
    return (unsigned int)qtFile->write(ptr,len);
}
