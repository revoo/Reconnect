// Begin TCP Server
//
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "reconnect.h"


int main(int argc, char *argv[]) {
        printf("TCP Server -- Reconnect Library -- Ver 1.00\n");
        int socket_fd = new_socket();
        printf("Successfully created server socket\n");
        //int sock_addr[] = init_sock_address("127.0.0.1", 5000);
        printf("Successfully Filled in local address information.\n");
        bind_socket(socket_fd, "127.0.0.1", 5000);
        printf("Successfully bound server socket to port\n");
        socket_listen(socket_fd);
        printf("Successfully started listening on port\n");
        printf("Server is now operational and is accepting connections\n");
        int client_sock = accept_connections(socket_fd);
        int bytes_rev = send(client_sock, "zyzz bruh here agen m9\n");
        printf("bytes sent: %d\n", bytes_rev);
        
        // Begin accept while loop. The server will fork to deal with any clients and the parent will close clients.
   //     while(1) {
     //           if ((client_sock = accept(socket_fd, (struct sockaddr *) &client_addr, &sock_size)) == -1) { 
     //                   perror("Client failed to connect\n"); return -1; }
     //           if (fork()) {
                        // Parent Process
      //                  wait(0);
       //                 int peername = getpeername(client_sock, (struct sockaddr *) &client_addr, &sock_size);

         //               printf("Done with client from <unknown> closing socket...\n");
          //              close(client_sock);
           //     }
            //    else {
                        // Child Process
             //           char packet[] = "Hello from ZYZZ BRUH...\n";
              //          if ((send(client_sock, packet, sizeof(packet), 0)) == -1) { 
               //                 perror("Failed to sent to client"); return -1; } 
                 //       return 0;        
        //        }
       // }
        return 0;
}




