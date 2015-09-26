// Begin Reconnect TCP Client

#include "reconnect.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
        printf("Reconnect TCP Client -- Ver 1.00\n");
        char buffer[256] = "";
        int sock_fd = new_socket();
        printf("TCP socket successfully created\n");
        printf("Connecting to server...\n");
        connect(sock_fd, "127.0.0.1", 5000);
        recieve(sock_fd, buffer, 256);
        printf("Message recieved from server: %s\n", buffer);


        return 0;
}
