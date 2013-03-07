#ifndef NETWORK_H
#define NETWORK_H


int accept_connection(int *listenSocket, char *ip);
int new_tcp_socket();
int bind_address(int *port, int *socket);
int set_reuse(int *socket);
void fatal(const char *c);
int client_connect(int *sock, int port, char* hostname);

#endif // NETWORK_H
