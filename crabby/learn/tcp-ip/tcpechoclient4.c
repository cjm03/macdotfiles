/*  Implementation of a TCP echo client for IPv4.
 *
 *  1. Create a TCP socket using socket().
 *  2. Establish a connection to the server using connect().
 *  3. Communicate using send() and recv().
 *  4. Close the connection with close().
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "helpers.h"


int main(int argc, char* argv[])
{
    if (argc < 3 || argc > 4) {
        DieWithUserMessage("Parameter(s)", "<Server Address> <Echo Word> [<Server Port>]");
    }
    char* servIP = argv[1];     // server ip address (dotted quad)
    char* echoString = argv[2]; // string to echo
    in_port_t servPort = (argc == 4) ? atoi(argv[3]) : 7; // optional,, server port (numeric), 7 well-known echo port
    
    // Create a reliable, stream socket using TCP
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock < 0) DieWithSystemMessage("socket() failed");

    // Construct server address structure
    struct sockaddr_in servAddr;
    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    // Convert address
    int rtnVal = inet_pton(AF_INET, servIP, &servAddr.sin_addr.s_addr);
    if (rtnVal == 0) {
        DieWithUserMessage("inet_pton() failed", "invalid address string");
    } else if (rtnVal < 0) {
        DieWithSystemMessage("inet_pton() failed");
    }
    servAddr.sin_port = htons(servPort);

    // Establish connection to the echo server
    if (connect(sock, (struct sockaddr*)&servAddr, sizeof(servAddr)) < 0) DieWithSystemMessage("connect() failed");

    size_t echoStringLen = strlen(echoString);

    // Send string to server
    ssize_t numBytes = send(sock, echoString, echoStringLen, 0);
    if (numBytes < 0) {
        DieWithSystemMessage("send() failed");
    } else if (numBytes != echoStringLen) {
        DieWithUserMessage("send()", "sent unexpected number of bytes");
    }
    // Receive same string back from server
    unsigned int totalBytesRcvd = 0;
    fputs("Received: ", stdout);
    while (totalBytesRcvd < echoStringLen) {
        char buffer[BUFSIZE];
        // receive up to buffer size - 1 (\0) bytes from the sender
        numBytes = recv(sock, buffer, BUFSIZE - 1, 0);
        if (numBytes < 0) {
            DieWithSystemMessage("recv() failed");
        } else if (numBytes == 0) {
            DieWithUserMessage("recv()", "connection closed prematurely");
        }
        totalBytesRcvd += numBytes;
        buffer[numBytes] = '\0';
        fputs(buffer, stdout);
    }
    fputc('\n', stdout);
    close(sock);
    exit(0);
}
