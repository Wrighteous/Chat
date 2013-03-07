#include <sys/types.h>
#include <sys/socket.h>
#include <cstring>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <cstdio>
#include <cstdlib>
#include <netdb.h>
#define BUFLEN 126

static void fatal(const char* message)
{
    perror(message);
    exit(EXIT_FAILURE);
}
// returns a TCP socket.
int new_tcp_socket()
{
    return socket(AF_INET, SOCK_STREAM, 0);
}
// sets the resuse on the socket
int set_reuse(int *socket)
{
    socklen_t optlen = 1;
    return setsockopt(*socket, SOL_SOCKET, SO_REUSEADDR, &optlen, sizeof(optlen));
}
// binds an address to the socket
int bind_address(int *port, int *socket)
{
    struct sockaddr_in address;
    bzero((char *)&address, sizeof(struct sockaddr_in));
    address.sin_family          = AF_INET;
    address.sin_port            = htons(*port);
    address.sin_addr.s_addr     = htonl(INADDR_ANY);

    return bind(*socket, (struct sockaddr *) &address, sizeof(address));
}
// accepts a connection and returns new socket also get the clients ip address.
int accept_connection(int *listenSocket, char *ip)
{
    int sock = 0;
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);

    sock = accept(*listenSocket, (struct sockaddr *) &address, &addrlen);
    strcpy(ip, inet_ntoa(address.sin_addr));

    return sock;

}

