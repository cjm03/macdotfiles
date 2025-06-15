#include <stdio.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

void printDate(Date* pDate)
{
    int m, d, y;
    m = pDate->month;
    d = pDate->day;
    y = pDate->year;
    printf("\n    Displaying the elements via values local to the function (y, m, d):\n");
    printf("\n\t%4d-%d-%d\n", y, m, d);
    printf("\n    Displaying the elements via pointers to the structure passed to the function (pDate-><element>):\n");
    printf("\n\t%4d-%d-%d\n\n", pDate->year, pDate->month, pDate->day);
}

int main(void)
{
    Date anniversary;
    Date* pAnniversary = &anniversary;
    anniversary.day   = 18;
    anniversary.month = 8;
    anniversary.year  = 1990;

    // While it may seem that you would access an element of anniversary via the pointer like this:
//  *pAnniversary.month
    // this will not work due to the . operator holding a higher precedence than the * operator. This element
    // reference will fail evaluation and be inaccessible. However, we can manipulate the order of evaluation to 
    // bypass the . operator's higher precedence:
//  (*pAnniversary).day         <--  anniversary.day;
//  (*pAnniversary).month       <--  anniversary.month;
//  (*pAnniversary).year        <--  anniversary.year;
    // Due to the frequency of needing to reference structure elements via pointers, there is a simpler alternative
    // syntax to access structure elements via pointers, which involves the -> operator:
//  pAnniversary->day           <--  (*pAnniversary).day;
//  pAnniversary->month         <--  (*pAnniversary).month;
//  pAnniversary->year          <--  (*pAnniversary).year;

    printf("Passing pAnniversary to printDate:\n");
    printDate(pAnniversary);
    printf("Passing the address of anniversary to printDate:\n");
    printDate(&anniversary);
}


