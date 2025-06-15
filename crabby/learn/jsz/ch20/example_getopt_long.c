#include <stdio.h>
#include <getopt.h>
#include <stdbool.h>

static struct option long_options[] = {
    {"title", required_argument, NULL, 't'},
    {"author", required_argument, NULL, 'a'},
    {NULL, 0, NULL, 0}
};
typedef struct _book {
    char* title;
    char* author;
} Book;

int main(int argc, char* argv[])
{
    char ch;
    Book b;
    while (true) {
        ch = getopt_long(argc, argv, "t:a:", long_options, NULL);
        if (ch == -1) break;
        switch (ch) {
            case 't': b.title = optarg; break;
            case 'a': b.author = optarg; break;
            default:
                printf("Usage: %s -title 'title' -author 'name'\n", argv[0]);
                break;
        }
    }
    if (b.title) printf("Title is [%s]\n", b.title);
    if (b.author) printf("Author is [%s]\n", b.author);
    if (optind < argc) {
        printf("non-option ARGV-elements: ");
        while (optind < argc) {
            printf("%s ", argv[optind++]);
        }
        printf("\n");
    }
}

