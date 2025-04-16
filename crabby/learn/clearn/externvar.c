// demonstration of external variable usage (basic)
#include <stdio.h>

#define MAXLINE 1000        // maximum input line length

int max;                // maximum length seen so far   /*
char line[MAXLINE];     // current input line               state external variable type
char longest[MAXLINE];  // longest line stored here     */

int getlineLocal(void);
void copy(void);

/* print the longest input line */ 
int main()
{
    int len;
    extern int max;         // since these variables are stored outside of the function, extern must be declared
    extern char longest[];  // in this example, declaring 'extern' is redundant because: If the definition
                            // of the external variable occurs in the source file before its use in a 
                            // particular function, then there is no need for an 'extern' declaration.
    max = 0;
    while ((len = getlineLocal()) > 0) {
        if (len > max) {
            max = len;
            copy();
        }
    }
    if (max > 0) {
        printf("%s", longest);
    }
    return 0;
}

/* getline: specialized version */ 
int getlineLocal(void)
{
    int c, i;
    extern char line[];

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i;
}

/* copy: specialized version */ 
void copy(void)
{
    int i;
    extern char line[], longest[];

    i = 0;
    while ((longest[i] = line[i]) != '\0') {
        i++;
    }
}

