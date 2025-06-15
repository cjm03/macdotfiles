#include <stdio.h>

void printHeading(const char* aHeading);

int main(void)
{
    printHeading("Title Page");
    printHeading("Chapter 1");
    printHeading("      ");
    printHeading("      ");
    printHeading("Chapter 2");
    printHeading("      ");
    printHeading("Conclusion");
}

void printHeading(const char* aHeading)
{
    int pageNo = 1;
    printf("%s\t\t\t Page %d\n", aHeading, pageNo);
    pageNo++;
}
