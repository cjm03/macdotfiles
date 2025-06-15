#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct {
    char name[MAX_NAME];
    int age;
    //...a
} person;

person* hashTable[TABLE_SIZE];

unsigned int hash(char* name) {
    int length = strnlen(name, MAX_NAME);
    unsigned int hashval = 0;
    for (int i = 0; i < length; i++) {
        hashval += name[i];
        hashval = (hashval * name[i]) % TABLE_SIZE;
    }
    return hashval;
}

void initHashTable(void) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

void printTable(void) {
    printf("Start\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] == NULL) {
            printf("\t%i\t---\n", i);
        } else {
            printf("\t%i\t%s\n", i, hashTable[i]->name);
        }
    }
    printf("End\n");

}

bool htInsert(person* p) {
    if (p == NULL) return false;
    int index = hash(p->name);
    for (int i = 0; i < TABLE_SIZE; i++) {
        int try = (i + index) % TABLE_SIZE;
        if (hashTable[try] == NULL) {
            hashTable[try] = p;
            return true;
        }
    }
    return false;
}

person* htLookup(char* name) {
    int index = hash(name);
    if (hashTable[index] != NULL && strncmp(hashTable[index]->name, name, TABLE_SIZE) == 0) {
        return hashTable[index];
    } else {
        return NULL;
    }
}

person* htDel(char* name) {
    int index = hash(name);
    if (hashTable[index] != NULL && strncmp(hashTable[index]->name, name, TABLE_SIZE) == 0) {
        person* tmp = hashTable[index];
        hashTable[index] = NULL;
        return hashTable[index];
    } else {
        return NULL;
    }
}

int main(void)
{
    initHashTable();
    printTable();
    printf("\n\n");
    person jacob = {.name="Jacob", .age=256};
    person steve = {.name="Steve", .age=27};
    person donny = {.name="Donny", .age=14};
    person jackson = {.name="Jackson", .age=44};
    person chris = {.name="Chris", .age=62};
    person matt = {.name="Matt", .age=11};
    person reindeer = {.name="Reindeer", .age=19};
    person patrick = {.name="Patrick", .age=22};
    person jeff = {.name="Jeff", .age=88};

    htInsert(&jacob);
    htInsert(&steve);
    htInsert(&donny);
    htInsert(&jackson);
    htInsert(&chris);
    htInsert(&matt);
    htInsert(&reindeer);
    htInsert(&patrick);
    htInsert(&jeff);
    printTable();

    person* tmp = htLookup("Jacob");
    if (tmp == NULL) {
        printf("NOTFOUND\n");
    } else {
        printf("FOUND %s\n", tmp->name);
    }
    htDel("Jacob");
    tmp = htLookup("Jacob");
    if (tmp == NULL) {
        printf("NOTFOUND\n");
    } else {
        printf("FOUND %s\n", tmp->name);
    }

    tmp = htLookup("Felix");
    if (tmp == NULL) {
        printf("NOTFOUND\n");
    } else {
        printf("FOUND %s\n", tmp->name);
    }

    /*printf("Jacob => %u\n", hash("Jacob"));
    printf("Steve => %u\n", hash("Steve"));
    printf("Mark => %u\n", hash("Mark"));
    printf("Donna => %u\n", hash("Donna"));
    printf("Katie => %u\n", hash("Katie"));
    printf("Zack => %u\n", hash("Zack"));
    printf("Aidan => %u\n", hash("Aidan"));
    printf("Donny => %u\n", hash("Donny"));
    printf("Ashton => %u\n", hash("Ashton"));*/

    return 0;
}