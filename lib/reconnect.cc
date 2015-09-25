// Reconnect library implementation file

#include "reconnect.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

// Initialize the sockaddr_in structure to be used as argument to many network system calls
struct sockaddr_in init_sock_address(char const ip_addr[], int port) {
        struct sockaddr_in Reconnect_lib_addr;                    // Create our sockaddr_in structure and fill it with our parameters
        Reconnect_lib_addr.sin_family = AF_INET;                  // In host byte order
        Reconnect_lib_addr.sin_port = htons(port);                // In network byte order (Big-endian)
        Reconnect_lib_addr.sin_addr.s_addr = inet_addr(ip_addr);  // Convert IP notation to binary
        memset(&(Reconnect_lib_addr.sin_zero), '\0', 8);          // Null the reset of the struct for compatability with sockaddr
        return Reconnect_lib_addr;
}

// Create a TCP socket from the AF_INET family. Return an int file descriptor 
int new_socket() {
        int sock_fd; 
        if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) { return -1; }
        return sock_fd;
}

// Bind a TCP socket to a port for servers to be able to accept connections
int bind_socket(int sock_fd, char const sock_ip[], int sock_port) {
        // Reset socket binding
        int yes =1;
        if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) { return -1; }
        struct sockaddr_in addrinfo = init_sock_address(sock_ip, sock_port);
        if (bind(sock_fd, (struct sockaddr *) &addrinfo, sizeof(addrinfo)) == -1 ) { return -1; }
        return 0;
}

// Listen to connections for servers with 10 awaiting connections
int socket_listen(int sock_fd) {
        if (listen(sock_fd, 10) == -1) { return -1; }
        return 0;
}

// Accept TCP connections for servers. Returns the new client socket file descriptor
int accept_connections(int sock_fd) {
        struct sockaddr_in client_addr;
        unsigned sock_size = sizeof(struct sockaddr_in);
        int client_sock;
        if ((client_sock = accept(sock_fd, (struct sockaddr *) &client_addr, &sock_size)) == -1) { return -1; }
        return client_sock;
}

// Communicate between TCP sockets
int send(char const message[], int client_sock) {
        int bytes_sent;
        if ((bytes_sent = send(client_sock, message, strlen(message), 0)) == -1) { return -1; }
        while ((unsigned) bytes_sent < strlen(message)) {
                if ((bytes_sent = send(client_sock, message, sizeof(message), 0)) == -1) { return -1; }
        }
        return bytes_sent;
}

// Recieve communication from external sources through TCP sockets
int recieve(char buffer[], int client_sock) {
        int bytes_recieved;
        if ((bytes_recieved = recv(client_sock, buffer, sizeof(buffer), 0)) == -1) { return -1; }
       // TODO: Keep recieiving until null terminator reached. 
       // while (buffer[strlen(buffer) + 1] != '\0') {
       //          if ((recv(client_sock, buffer, sizeof(buffer), 0)) == -1) { return -1; }
       // }
       return bytes_recieved;
}
