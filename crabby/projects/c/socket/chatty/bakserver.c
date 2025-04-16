#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int client_sockets[MAX_CLIENTS];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


int makeSocket(uint16_t port)
{
    int sock;
    struct sockaddr_in name;

    /* Create the socket. */
    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    /* Name the socket. */
    name.sin_family = AF_INET;
    name.sin_port = htons(port);
    name.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(sock, (struct sockaddr *)&name, sizeof(name)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }
    return sock;
}




/* WEIRD TUTORIAL CODE THROWING LOTS OF ERRORS/WARNINGS -- TRYING SOMETHING DIFFERENT
struct sockaddr_in serv;        // Main socket variable
int fd;                         // Socket file descriptor that will be used to identify the socket
int conn;                       // Connection file descriptor to distinguish client connections
char message[100];              // Array to store messages sent by the server

int main()
{
    serv.sin_family = AF_INET;
    serv.sin_port = htons(8096);    // Port at which the server will listen for connections
    serv.sin_addr.s_addr = INADDR_ANY;

    // Create a new socket and also return the identifier of the socket into fd 
    fd = socket(AF_INET, SOCK_STREAM, 0);

    // handle errors: add an if condition to check if fd is greater than 0. If it isn't, prompt an error TODO

    // Assign the address specified by serv to the socket 
    bind(fd, (struct sockaddr *)&serv, sizeof(serv));

    // Listen for client connection, maximum 5 connections will be permitted  
    listen(fd,5);

    while (conn = accept(fd, (struct sockaddr *)NULL, NULL)) {
        int pid;
        if ((pid = fork()) == 0) {
            while (recv(conn, message, 100, 0) > 0) {
                printf("Message Received: %s\n", message);
                // an extra breaking condition can be added here to terminate the child process
                message = "";
            }
            exit(0);
        }
    }
}
*/
