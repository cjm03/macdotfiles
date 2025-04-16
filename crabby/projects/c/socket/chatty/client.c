#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void * doReceiving(void * sockID)
{
    int clientSocket = *((int *) sockID);

    while (1) {
        char data[1024];
        int read = recv(clientSocket, data, 1024, 0);
        data[read] = '\0';
        printf("%s\n", data);
    }
}

int main()
{
    int clientSocket = socket(PF_INET, SOCK_STREAM, 0);

    struct sockaddr_in serverAddr;

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if(connect(clientSocket, (struct sockaddr*) &serverAddr, sizeof(serverAddr)) == -1) return 0;

    printf("Connection established.......\n");

    pthread_t thread;
    pthread_create(&thread, NULL, doReceiving, (void *) &clientSocket );

    while (1) {
        char input[1024];
        scanf("%s", input);

        if (strcmp(input, "LIST") == 0) {
            send(clientSocket, input, 1024, 0);
        }
        if (strcmp(input, "SEND") == 0) {
            send(clientSocket, input, 1024, 0);

            scanf("%s", input);
            send(clientSocket, input, 1024, 0);

            scanf("%[^\n]s", input);
            send(clientSocket, input, 1024, 0);
        }
    }
}



/*
#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int client_sockets[MAX_CLIENTS];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int server_socket = socket(AF_INET, SOCK_STREAM, 0);
if (server_socket == -1) {
    perror("Socket creation failed\n");
    exit(EXIT_FAILURE);
}
*/

