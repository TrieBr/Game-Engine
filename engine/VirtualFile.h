#ifndef VIRTUALFILE_H
#define VIRTUALFILE_H

enum SeekOrigin {
    VSEEK_SET,
    VSEEK_CUR,
    VSEEK_END
};

/*
 * Abstract class that represents a virtual file which can be a file in Memory, streamed file, etc.
 * Author: Brad Triebwasser (04/2014)
 * */

class VirtualFile {
public:
    VirtualFile() {}
    virtual ~VirtualFile() {}
    //Seek to position in file
    virtual void Seek(SeekOrigin origin, int offset) = 0;
    //Get size of file
    virtual unsigned int Size() = 0;
    //Return position of read/write pointer
    virtual unsigned int Tell() = 0;
    //Read data
    virtual unsigned int Read(char* ptr, unsigned int len) = 0;
    //Write data
    virtual unsigned int Write(char* ptr, unsigned int len) = 0;
    //Write data type
    template <class T>
    unsigned int Write(T val) {
        T buf = val;
        return this->Write((char*)&buf,sizeof(T));
    }
    //Read data type
    template <class T>
    T Read() {
        T buf;
        this->Read((char*)&buf,sizeof(T));
        return buf;
    }
};



#endif // VIRTUALFILE_H
