// Begin TCP Server

#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sockaddr_in init_sockaddr_in(const char[], int);

int main(int argc, char *argv[]) {
        printf("TCP Server -- Reconnect Library -- Ver 1.00\n");
        int socket_fd = socket(AF_INET, SOCK_STREAM, 0);        
        printf("Successfully created server socket\n");
        struct sockaddr_in addrinfo = init_sockaddr_in("127.0.0.1", 5000);        
        printf("Successfully Filled in local address information.\n");
        if (bind(socket_fd, (struct sockaddr *) &addrinfo, sizeof(struct sockaddr)) == -1) { 
                perror("Failed to bind socket.\n"); return -1; }
        printf("Successfully bound server socket to port\n");
        if (listen(socket_fd, 5) == -1) { 
                perror("listening\n"); return -1; } 
        printf("Successfully started listening on port\n");
        printf("Server is now operational and is accepting connections\n");
        struct sockaddr_in client_addr;
        unsigned sock_size = sizeof(struct sockaddr_in);
        int client_sock;
        // Begin accept while loop. The server will fork to deal with any clients and the parent will close clients.
        while(1) {
                if ((client_sock = accept(socket_fd, (struct sockaddr *) &client_addr, &sock_size)) == -1) { 
                        perror("Client failed to connect\n"); return -1; }
                if (fork()) {
                        // Parent Process
                        wait(0);
                        int peername = getpeername(client_sock, (struct sockaddr *) &client_addr, &sock_size);

                        printf("Done with client from %d, closing socket...\n", inet_ntoa(peername));
                        close(client_sock);
                }
                else {
                        // Child Process
                        char packet[] = "Hello from ZYZZ BRUH...\n";
                        if ((send(client_sock, packet, sizeof(packet), 0)) == -1) { 
                                perror("Failed to sent to client"); return -1; } 
                        return 0;        
                }
        }
        return 0;
}

struct sockaddr_in init_sockaddr_in(char const ip_addr[], int port) {
        struct sockaddr_in Reconnect_lib_addr;                    // Create our sockaddr_in structure and fill it with our parameters
        Reconnect_lib_addr.sin_family = AF_INET;                  // In host byte order
        Reconnect_lib_addr.sin_port = htons(port);                // In network byte order (Big-endian)
        Reconnect_lib_addr.sin_addr.s_addr = inet_addr(ip_addr);  // Convert IP notation to binary
        memset(&(Reconnect_lib_addr.sin_zero), '\0', 8);          // Null the reset of the struct for compatability with sockaddr
        return Reconnect_lib_addr;
}



