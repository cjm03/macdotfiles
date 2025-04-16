#include <stdio.h>

int main() {
  int startint = 0;
  int inputint = 0;

  printf("Enter your integer (greater than 0!): ");
  scanf(" %d", &inputint);

  while (startint <= inputint) {
    if (startint == 0) {
      printf("0\n");
    } else if (startint % 3 == 0 && startint % 5 == 0) {
      printf("fizzbuzz\n");
    } else if (startint % 3 == 0) {
      printf("fizz\n");
    } else if (startint % 5 == 0) {
      printf("buzz\n");
    } else {
      printf("%d\n", startint);
    }
    startint++;
  }
}
