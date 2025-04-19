#include <stdio.h>
#include <stdbool.h>


// Syntax for defining a structure
// struct name {
//     type componentName1;
//     type componentName2;
//     ...;
//     type componentNameN;
// };
// Syntax for defining a variable of a structure
// struct name variableName;
enum Suit {
    club,
    diamond,
    heart,
    spade
};

enum Face {
    one, two, three, four, five, six, seven,
    eight, nine, ten, jack, queen, king, ace
};

struct Card {
    enum Suit suit;
    int suitValue;
    enum Face face;
    int faceValue;
    bool isWild;
};
int main()
{
    struct Card card;
}
