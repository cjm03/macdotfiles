#include <stdio.h>

int main() {
  int integer = 0;
  int sum = 0;
  int intcount = 0;
  int avg = 0;

  do {
    printf("Enter an integer value: ");
    scanf(" %d", &integer);
    sum = sum + integer;
    intcount = intcount + 1;
  } while (integer != 0);

  intcount = intcount - 1;
  avg = sum / intcount;
  printf("The average of entered integers is: ");
  printf("%d", avg);
  printf("\n");
}
