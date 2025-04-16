/*
    Header file for fileretrv.c 
    Programmer: Kurt Seiffert

*/

#ifndef FILE_RETRV_HEADER_FILE
#define FILE_RETRV_HEADER_FILE


#include <stdio.h>
/*
    fretrvs - loads buffer from specified filepath rooted
    to env variable $HOME (default) or $WWW_DATA if set.
*/
char * fretrvs(char * buffer, size_t bSize, char * filePath);

// Environmental variable names referenced
#define HOME "HOME"
#define WWW_DATA "WWW_DATA"

// max length of filePath supported
#define MAX_PATH_LEN 1024

// Spported Errno
#define ERR_NO_FILE 2
#endif  // FILE_RETRV_HEADER_FILE