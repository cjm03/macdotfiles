// nvim: projects/c/icex

/* 
file: icex04.c
programmer: Charles Moye
C291
Provide two integers as input, returns Y if first is larger, returns N if second is larger, returns = if integers are equal


*/


#include <stdio.h>

char if_larger(int a, int b) {
    if (a > b) {
        return 'Y';
    } else if (a < b) {
        return 'N';
    } else {
        return '=';
    }
}


int main() {
    int first_integer;
    int second_integer;
    printf("Enter your two integers, separated by a single space: ");
    scanf("%d %d", &first_integer, &second_integer);
    char return_value = if_larger(first_integer, second_integer);
    printf("%c\n", return_value);
}
