/*
 *  socket() - Get the File Descriptor!
 *  int socket(int domain, int type, int protocol);
 *      domain: should be set to "AF_INET", just like in struct sockaddr_in
 *      type: tells the kernel what kind of socket this is: SOCK_STREAM or SOCK_DGRAM
 *      protocol: 0
 *  socket() returns a socket descriptor that can be later used in system calls, or -1 on error
 *--------------------------------------------------------------------------------------------------------------------
 *  bind() - What Port am I On?
 *  int bind(int sockfd, struct sockaddr* my_addr, int addrlen);
 *      sockfd: file descriptor returned by socket()
 *      my_addr: pointer to a struct sockaddr containing address info, namely, port and IP address
 *      addrlen: can be set to sizeof(struct sockaddr)
 *  Example: */
#include <string.h>                 // Some of the process of getting your own IP address and/or port
#include <sys/types.h>              // can be automated:
#include <sys/socket.h>             //      my_addr.sin_port = 0; // choose any unused port at random
#include <netinet/in.h>             //      my_addr.sin_addr.s_addr = INADDR_ANY; // use my IP address
#include <arpa/inet.h>              //
                                    // bind() returns -1 on error.
#define MYPORT 8080                 // Sometimes you might notice, you try to rerun a server and bind()
                                    // fails, claiming "Address already in use.". This means that a bit
int main(void)                      // of a socket that was connected is still hanging around in the kernel,
{                                   // and is hogging the port. Either wait for it to clear, or add code to
    int sockfd;                     // allow the program to reuse the port:
                                    //  int yes = 1;
    struct sockaddr_in my_addr;     //  setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    my_addr.sin_family = AF_INET;           // host byte order
    my_addr.sin_port = htons(MYPORT);       // short, network byte order
    my_addr.sin_addr.s_addr = inet_addr("10.12.110.57");
    memset(&(my_addr.sin_zero), '\0', 8);   // zero rest of the struct 
}
/*
 *--------------------------------------------------------------------------------------------------------------------
 *  connect() - Hey, You!
 *  int connect(int sockfd, struct sockaddr* serv_addr, int addrlen);
 *--------------------------------------------------------------------------------------------------------------------
 *  listen() - Will Somebody Please Call Me?
 *  int listen(int sockfd, int backlog);
 *      sockfd: usual file descriptor from the socket() system call
 *      backlog: number of connections allowed on the incoming queue. this means incoming connections are
 *               going to wait in this queue until you accept() them and this is the limit on how many 
 *               you can queue. Most systems limit this number to about 20, silently.
 *--------------------------------------------------------------------------------------------------------------------
 *  Simple flow of a socket program's system calls:
 *      socket();
 *      bind();
 *      listen();
*/      /* accept() goes here */
/*--------------------------------------------------------------------------------------------------------------------
 *
 *
 *
*/
