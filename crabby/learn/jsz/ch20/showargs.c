#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc == 1) {
        printf("No arguments given.\n\n");
        printf("usage: %s <arg1> <arg2> ... <argN>\n", argv[0]);
        return 0;
    }
    printf("arg count = [%d]\n", argc);
    for (int i = 0; i < argc; i++) {
        if (i == 0) {
            printf("executable = [%s]\n", argv[i]);
        } else {
            printf("argument %d = [%s]\n", i, argv[i]);
        }
    }
}
