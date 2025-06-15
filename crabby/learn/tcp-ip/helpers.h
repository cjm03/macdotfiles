#ifndef HELPERS_H
#define HELPERS_H

#define BUFSIZE 4096

/* DieWithMessage.c */
void DieWithUserMessage(const char* msg, const char* detail);
void DieWithSystemMessage(const char* msg);

/* HandleTCPClient.c */
void HandleTCPClient(int clntSocket);

#endif
