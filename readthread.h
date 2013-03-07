#ifndef READTHREAD_H
#define READTHREAD_H
#include "QThread"
#include <unistd.h>


#define BUFLEN 126

class ReadThread : public QThread
{
    Q_OBJECT

public:
    ReadThread();
    void run();
    void setSocket(int *socket);

signals:
    void messageRecieved(QString data);

private:
    int *mySocket_;
};

#endif // READTHREAD_H
