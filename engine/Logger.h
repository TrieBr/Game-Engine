#ifndef LOGGER_H
#define LOGGER_H

#include <QDebug>

#include <stdarg.h>
#include <string>
#include <cstdio>
#include <cstdio>

//Use sprintf_s under MSVC, sprintf under anything else
#ifndef _MSC_VER
    #define __sprintf(x,y,z) sprintf(x,z)
    #define __vsprintf(a,x,y,z) vsprintf(a,y,z)
#else
    #define __sprintf(x,y,z) sprintf_s(x,y,z)
    #define __vsprintf(a,x,y,z) vsprintf_s(a,x,y,z)
#endif

/*
 * Class for logging Warning, Trace and Error messages to an output stream.
 * Author: Brad Triebwasser (04/2014)
 * */

class Logger
{
public:
    Logger();
    //Print a warning message
    static void Warn(const char *fmt, ...) {
        char buffer[256];
        int pos = 0;
        pos += __sprintf(buffer,256,"[WARN]");
        va_list args;
        va_start(args, fmt);
        pos += __vsprintf(buffer+pos,256-pos,fmt, args);
        pos+=__sprintf(buffer+pos,256-pos,"\n");
        qDebug() << buffer;
    }
    //Print a trace message
    static void Trace(const char *fmt, ...) {
        char buffer[256];
        int pos = 0;
        pos += __sprintf(buffer,256,"[TRACE]");
        va_list args;
        va_start(args, fmt);
        pos += __vsprintf(buffer+pos,256,fmt, args);
        pos+=__sprintf(buffer+pos,256,"\n");
        qDebug() << buffer;
    }
    //Print an error message
    static void Error(const char *fmt, ...) {
        char buffer[256];
        int pos = 0;
        pos += __sprintf(buffer,256,"[ERROR]");
        va_list args;
        va_start(args, fmt);
        pos += __vsprintf(buffer+pos,256,fmt, args);
        pos+=__sprintf(buffer+pos,256,"\n");
        qDebug() << buffer;
    }
};

#endif // LOGGER_H
