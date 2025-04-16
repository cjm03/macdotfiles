#include <stdio.h>

int main()
{
    double nc;
    // for loop has an empty body, but grammatical rules of C require a body
    // the isolated semicolon, called a null statement, is there to satisfy that rule
    for (nc = 0; getchar() != EOF; nc++)
        ;
    printf("%.0f\n", nc);
}
