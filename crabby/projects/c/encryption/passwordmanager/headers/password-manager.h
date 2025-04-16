/*
  File: password-manager.h
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void cipher(char[],char[],char[]);

void save_password();

void open_password();

void display_password();

void display_references();

void erase_vault();

char password[100], reference[100], encrypted[100], key[100], decrypted[100];
