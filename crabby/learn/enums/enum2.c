#include <stdio.h>

enum result_code {
    noError = 0,
    unhandledEnumeration,
    unknownError
};

enum suit {
    spade,
    heart,
    diamond,
    club
};

enum result_code cardFunc(enum suit var)
{
    if (var == spade) {
        return noError;
    } else if (var == heart) {
        return noError;
    } else if (var == diamond) {
        return unknownError;
    } else if (var == club) {
        return noError;
    } else {
        return unhandledEnumeration;
    }
}

const char* suitToStr(enum suit var)
{
    switch (var) {
        case spade:     return "Spade";
        case heart:     return "Heart";
        case diamond:   return "Diamond";
        case club:      return "Club";
        default:        return "Invalid";
    }
}

int main()
{
    enum suit c1, c2;
    enum result_code result1, result2;
    c1 = spade; // since card is an enumerated type, it may only be assigned a value specified in the type
    c2 = diamond;
    result1 = cardFunc(c1);
    result2 = cardFunc(c2);
    if (noError != result1) {
        printf("Error\n");
    } else {
        printf("Card: %s\n", suitToStr(c1));
    }
    if (noError != result2) {
        printf("Error\n");
    } else {
        printf("Card: %s\n", suitToStr(c2));
    }
}
