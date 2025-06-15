#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "helpers.h"

void HandleTCPClient(int clntSocket)
{
    char buffer[BUFSIZE];

    ssize_t numBytesRcvd = recv(clntSocket, buffer, BUFSIZE, 0);
    if (numBytesRcvd < 0) DieWithSystemMessage("recv() failed");

    while (numBytesRcvd > 0) {
        ssize_t numBytesSent = send(clntSocket, buffer, numBytesRcvd, 0);
        if (numBytesSent < 0) {
            DieWithSystemMessage("send() failed");
        } else if (numBytesSent != numBytesRcvd) {
            DieWithUserMessage("send()", "sent unexpected number of bytes");
        }

        numBytesRcvd = recv(clntSocket, buffer, BUFSIZE, 0);
        if (numBytesRcvd < 0) DieWithSystemMessage("recv() failed");
    }
    close(clntSocket);
}
