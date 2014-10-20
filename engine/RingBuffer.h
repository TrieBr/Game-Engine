#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include <cstring>

#include <iostream>

/*
 * Ring/Circular buffer. Can continually write data, but will begin to overwrite previously written data when it wraps around the buffer size.
 * 
 * */

template <class T>
class RingBuffer
{
public:
    //Constructor with size of buffer
    RingBuffer(unsigned int size) {
        bufferArray = new T[size];
        writePos = 0;
        readPos = 0;
        elementCount = size;
        for (unsigned int i=0; i<elementCount; i++) {
            bufferArray[i] = 0;
        }
    }
    //Destructor
    ~RingBuffer() {
        if (bufferArray)
            delete [] bufferArray;
    }
    //Write a number of elements to the buffer
    unsigned int Write(T *buf, unsigned int num) {
        unsigned int readLen = num;
        if (num>elementCount) readLen = elementCount;
        unsigned int leftOver = 0;
        if (writePos+readLen>elementCount) {
            leftOver = (writePos+readLen)-elementCount;
            readLen = elementCount-writePos;
        }
        memcpy(bufferArray+writePos,buf,readLen*(sizeof(T)));
        writePos+=readLen;
        if (leftOver!=0) {
            memcpy(bufferArray,buf+readLen,leftOver*(sizeof(T)));
            writePos = leftOver;
        }

        return readLen+leftOver;

    }

    //Read a number of elements from the buffer
    unsigned int Read(T  *buf, unsigned int num) {
        unsigned int readLen = num;
        if (num>elementCount) readLen = elementCount;
        unsigned int leftOver = 0;
        if (readPos+readLen>elementCount) {
            leftOver = (readPos+readLen)-elementCount;
            readLen = elementCount-readPos;
        }
        memcpy(buf,bufferArray+readPos,readLen*(sizeof(T)));
        readPos+=readLen;
        if (leftOver!=0) {
            memcpy(buf+readLen,bufferArray,leftOver*(sizeof(T)));
            readPos = leftOver;
        }

        return readLen+leftOver;
    }

    unsigned int SpaceRemaining() {
        if (writePos>readPos) {
            return (elementCount-writePos)+readPos;
        }else if (writePos<readPos){
            return readPos-writePos;
        }
        return elementCount;
    }

    void Print(){
        for (int i=0; i<elementCount; i++) {
            if (bufferArray[i]==0) {
                std::cout << '-';
            }else{
                std::cout << bufferArray[i];
            }
        }
        std::cout << std::endl;
    }

private:
    T*              bufferArray;    //Array for the buffer
    unsigned int    elementCount;   //Number of elements in the buffer
    unsigned int    writePos;       //Write pointer
    unsigned int    readPos;        //Read pointer
};

#endif // RINGBUFFER_H
