/*
 *  How to Deal With IP Addresses
 *----------------------------------------------------------------------------------------------
 *  Consider a `struct sockaddr_in ina`, and you have an IP address "10.12.110.57" that you want
 *  to store into it. You want to use inet_addr(), which converts an IP address in numbers-and-dots
 *  notation into an unsigned long:
 *      ina.sin_addr.s_addr = inet_addr("10.12.110.57");
 *  inet_addr() will return the address in Network Byte Order already, so no need to call htonl().
 *  The above example isn't very robust because it lacks error checking. inet_addr() will return 
 *  -1 on error, and (unsigned)-1 happens to correspond to IP address 255.255.255.255...
 *
 *  Actually, theres a cleaner interface that may be used instead of inet_addr(). It is called
 *  inet_aton(), meaning ascii to network: */
        #include <sys/socket.h>
        #include <netinet/in.h>
        #include <arpa/inet.h>
        int inet_aton(const char* cp, struct in_addr* inp);
//  Here's a sample usage:
        struct sockaddr_in my_addr;
        my_addr.sin_family = AF_INET;       // host byte order
        my_addr.sin_port = htons(MYPORT);   // short, network byte order
        inet_aton("10.12.110.57", &(my_addr.sin_addr));
        memset(&(my_addr.sin_zero), '\0', 8); // zero the rest of the struct
/*  Unlike most other socket-related functions, inet_aton() returns non-zero on success, zero on failure,
 *  and the address is passed back in `inp`.
 *  Now, to do the reverse and convert binary IP representations back into a string, use inet_ntoa(). */
        printf("%s", inet_ntoa(ina.sin_addr));
/*  If you need to save the address, it is best to strcpy() it to your own character array.
*/
