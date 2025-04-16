/*
  File: key-generator.c
*/

extern void key_generator(char *key, int n)
{
  srand((unsigned int)(time(NULL)));
  int index = 0;

  char strings[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    for(index = 0; index <n; index++)
    {
      key[index] = strings[rand() % (sizeof strings - 1)];
    }
  key[index]='\0';
}
