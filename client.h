#ifndef CLIENT_H
#define CLIENT_H
#include "mainwindow.h"
#define BUFLEN 126

class MainWindow;
class Client
{

public:
    Client();
    void set_port(QString s);
    void set_hostname(QString s);
    void set_username(QString s);
    int connect_to_server();
    int* get_sock();
    bool is_connected();
    void set_connect();
    void send_data();
    void set_message(const char *s);



private:
    MainWindow *w;
    int sock;
    int port;
    char hostname[BUFLEN];
    char username[BUFLEN];
    char message[BUFLEN];
    bool connected;
};

#endif // CLIENT_H
