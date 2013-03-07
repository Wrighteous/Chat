#include "readthread.h"

ReadThread::ReadThread()
{
}
void ReadThread::run()
{
    char buffer[BUFLEN];
    while(1)
    {
        read(*mySocket_, buffer, BUFLEN);
        QString data(buffer);
        emit ReadThread::messageRecieved(data);
        buffer[0] = '\0';
    }
}
void ReadThread::setSocket(int *socket)
{
    mySocket_ = socket;
}
