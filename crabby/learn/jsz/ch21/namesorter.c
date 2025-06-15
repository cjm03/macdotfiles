/* namesorter.c */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

const int listMax = 100;
const int stringMax = 80;

typedef char string [stringMax];

void addName(string* names, string newOne, int* listSize);
void printNames(string* names, int listSize);

void removeNewline(string s)
{
    int len = strlen(s);
    s[len - 1] = '\0';
}

int main(void)
{
    string newName;
    string nameList[listMax];
    int numNames = 0;
    while (printf("Name: %d: ", numNames + 1),
           fgets(newName, stringMax, stdin),
           removeNewline(newName),
           strlen(newName) > 0)
        addName(nameList, newName, &numNames);
    printNames(nameList, numNames);
}

void addName(string* names, string newName, int* pNumEntries)
{
    if (*pNumEntries >= listMax) {
        puts("List is full!");
        return;
    } else {
        int k = 0;
        bool found = false;
        while (!found && k < *pNumEntries)
            found = (strcmp(newName, names[k++]) < 0);

        if (found) {
            k--;
            for (int j = *pNumEntries; j > k; j--) {
                strcpy(names[j], names[j - 1]);
            }
        }
        strcpy(names[k], newName);
        (*pNumEntries)++;
    }
    return;
}

void printNames(string* names, int numEntries)
{
    printf("\nNumber of Entries: %d\n\n", numEntries);
    for (int i = 0; i < numEntries; i++) {
        fputs(names[i], stdout);
        fputc('\n', stdout);
    }
}


