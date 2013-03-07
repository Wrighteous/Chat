#include "client.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <cstring>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <cstdio>
#include <cstdlib>
#include <netdb.h>
#include "network.h"
#include "utils.h"
Client::Client()
{
    w = new MainWindow(0, this);
    w->show();
    connected = false;

}
int* Client::get_sock()
{
    return &sock;
}
void Client::set_hostname(QString s)
{
    strcpy(hostname, convert_to_cstring((s)));
}
void Client::set_username(QString s)
{
    strcpy(username, convert_to_cstring((s)));
}
void Client::set_port(QString s)
{
    port = s.toInt();
}
bool Client::is_connected()
{
    return connected;
}
void Client::set_connect()
{
    connected = true;
}
void Client::send_data()
{
    if(send(sock, message, BUFLEN, 0) == -1)
    {
        // error
    }
}
void Client::set_message(const char *s)
{
    strcpy(message, s);
}
int Client::connect_to_server()
{

    struct sockaddr_in server;
    socklen_t serverlen = sizeof(server);
    struct hostent *hp;

    if((sock = new_tcp_socket()) == -1)
    {
        // socket not created.
    }

    bzero((char *)&server, sizeof(struct sockaddr_in));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    if((hp = gethostbyname(hostname)) == NULL)
    {
       // fatal("Unknown server address"); // maybe not have fatal? Can have client re enter the IP address.
    }
    bcopy(hp->h_addr, (char *)&server.sin_addr, hp->h_length);

    return connect(sock, (struct sockaddr*) &server, serverlen);
}
