// Central header file for the Reconnect library
#ifndef RECONNECT_H
#define RECONNECT_H

// Function to initialize the sockaddr_in strucure to be used with AF_INET for TCP/IP communication
struct sockaddr_in init_sock_address(const char ip_addr[], int port);
// Create new socket 
int new_socket();
// Bind TCP socket to the port for servers
int bind_socket(int, char const*, int);
// Listen for incoming TCP connections with up to 10 awaiting connections
int socket_listen(int);
// Accept incoming TCP connections for servers
int accept_connections(int);
// Send messages to sockets that have established connection
int send(int, const char*);
// Recieve messages from sockets that have established connection
int recieve(int, char*, int);
// Connect to remote hosts via TCP sockets
int connect(int, char const*, int);









#endif // RECONNECT_H
