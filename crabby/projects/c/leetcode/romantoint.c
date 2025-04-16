#include <stdio.h>
#include <string.h>
#include <ctype.h>

int value(char r)
{
    r = toupper(r);
    switch (r) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToInt(char* s)
{
    int sum = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        int current_value = value(s[i]);
        if (i < len - 1) {
            int next_value = value(s[i + 1]);
            if (current_value < next_value) {
                sum -= current_value;
            } else {
                sum += current_value;
            }
        } else {
            sum += current_value;
        }
    }
    return sum;
}

int main()
{
    char romanInput[20];
    printf("enter roman numeral string: ");
    scanf("%s", romanInput);
    int result = romanToInt(romanInput);
    printf("Integer value: %d\n", result);
    return 0;
}
