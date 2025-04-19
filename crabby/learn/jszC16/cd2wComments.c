#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* Enumerations */
typedef enum { club = 1, diamond, heart, spade } Suit;
typedef enum { one = 1, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace } Face;

/* Structures */
typedef struct {            
    Suit    suit;           
    int     suitValue;      
    Face    face;           
    int     faceValue;      
    bool    isWild;         
} Card;                     
typedef struct {
    int cardsDealt;
    Card* pCard1;
    Card* pCard2;
    Card* pCard3;
    Card* pCard4;
    Card* pCard5;
} Hand;

/* Constants */
const int kCardsInDeck  = 52;
const int kCardsInHand  = 5;
const int kCardsInSuit  = 13;
const bool kWildCard    = true;
const bool kNotWildCard = true;

/* Prototypes */
void CardToString(      Card* pCard, char pCardStr[20]);
void AddCardToHand(     Hand* pHand, Card* pCard);
Card** GetCardInHand(   Hand* pHand, int cardIndex);
Card* DealCardFromDeck( Card deck[], int index);
void InitializeCard(    Card* pCard, Suit s, Face f, bool w);
void InitializeHand(    Hand* pHand);
void InitializeDeck(    Card* pDeck);
void PrintCard(         Card* pCard);
void PrintHand(         Hand* pHand, char* pHandStr, char* pLeadStr);
void PrintDeck(         Card* pDeck);

/*--------------------------------------------------------------------------------------------------------------------------------*/

/* MAIN */
int main(void)
{
    Card deck[kCardsInDeck];
    Card* pDeck = deck;
    
    InitializeDeck(pDeck);
    PrintDeck(pDeck);
    printf("\n");


    Hand h1;
    Hand* pHand = &h1;          // Pointer to the address of the structure h1
    Card* pCard = &h1.card5;

    h1.cardsDealt = 0;          // h1 structure's cardsDealt component is set to 0
    Suit s;
    Face f;

    //pHand->card5.suit = club;   // Pointer to the h1 structure's component card5 used to access/assign card5's component suit
    // pCard->suit = club;
    //pHand->card5.face = ace;    // Pointer to the h1 structure's component card5 used to access/assign card5's component face
    // pCard->face = ace;

    InitializeCard(pCard, club, ace, kNotWildCard);

    //s = pHand->card5.suit;      // enum type Suit's variable s is assigned a pointer to h1's component card5's component suit
    s = pCard->suit;
    //f = pHand->card5.face;      // enum type Suit's variable f is assigned a pointer to h1's component card5's component face
    f = pCard->face;
}

/*--------------------------------------------------------------------------------------------------------------------------------*/

/* Functions */
void CardToString(Card* pCard, char pCardStr[20])
{
    switch (pCard->face) {
        case two:   strcpy(pCardStr, "    2 "); break;
        case three: strcpy(pCardStr, "    3 "); break;
        case four:  strcpy(pCardStr, "    4 "); break;
        case five:  strcpy(pCardStr, "    5 "); break;
        case six:   strcpy(pCardStr, "    6 "); break;
        case seven: strcpy(pCardStr, "    7 "); break;
        case eight: strcpy(pCardStr, "    8 "); break;
        case nine:  strcpy(pCardStr, "    9 "); break;
        case ten:   strcpy(pCardStr, "   10 "); break;
        case jack:  strcpy(pCardStr, " Jack "); break;
        case queen: strcpy(pCardStr, "Queen "); break;
        case king:  strcpy(pCardStr, " King "); break;
        case ace:   strcpy(pCardStr, "  Ace "); break;
        default:    strcpy(pCardStr, "  ??? "); break;
    }
    switch (pCard->suit) {
        case spade:     strcat(pCardStr, "of Spades  "); break;
        case heart:     strcat(pCardStr, "of Hearts  "); break;
        case diamond:   strcat(pCardStr, "of Diamonds"); break;
        case club:      strcat(pCardStr, "of Clubs   "); break;
        default:        strcat(pCardStr, "of ???s    "); break;
    }
}

void AddCardToHand(Hand* pHand, Card* pCard)
{
    int numInHand = pHand->cardsDealt;
    if (numInHand == kCardsInHand) return;

    Card** ppC = GetCardInHand(pHand, numInHand);
    *ppC = pCard;

    /* switch (numInHand) {
        case 0: pHand->pCard1 = pCard; break;
        case 1: pHand->pCard2 = pCard; break;
        case 2: pHand->pCard3 = pCard; break;     Conceptually simpler way to achieve the same result
        case 3: pHand->pCard4 = pCard; break;
        case 4: pHand->pCard5 = pCard; break;
        default: break;
    } */

    pHand->cardsDealt++;
}

Card** GetCardInHand(Hand* pHand, int cardIndex) // Pass a pointer to a Hand and the index of desired card. Return is the address 
{                                                //  of the indexed card inside the Hand structure provided.
    Card** ppC;

    switch (cardIndex) {

        case 0: ppC = &(pHand->pCard1); break;    // Since '&' and '->' operators hold the same precedence, we put parentheses around
        case 1: ppC = &(pHand->pCard2); break;    //  'pHand->card' so it gets the 'Card' structure, and then the '&' assigns pC
        case 2: ppC = &(pHand->pCard3); break;    //  with the address of that structure.
        case 3: ppC = &(pHand->pCard4); break;
        case 4: ppC = &(pHand->pCard5); break;
    }
    return ppC;
}

Card* DealCardFromDeck( Card deck[], int index)
{
    Card* pCard = &deck[index];
    return pCard;
}

void InitializeCard(Card* pCard, Suit s, Face f, bool w)
{
    pCard->suit         = s;
    pCard->suitValue    = (int) s;
    pCard->face         = f;
    pCard->faceValue    = (int) f;
    pCard->isWild       = w;
}

void InitializeHand(Hand* pHand)
{
    pHand->cardsDealt = 0;
    pCard1 = NULL;
    pCard2 = NULL;
    pCard3 = NULL;
    pCard4 = NULL;
    pCard5 = NULL;
}

void InitializeDeck(Card* pDeck)    // pass a pointer pointing to deck of type Card
{ // The for loop iterates 13 times & each iteration will modify 4 card components of 4 cards. I.E., the first iteration will modify
    // pDeck[0], pDeck[13], pDeck[26], and pDeck[39]. The fifth iteration modifies pDeck[4], pDeck[17], pDeck[30], and pDeck[43].
    
    Face f[] = {two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace}; // Lookup table with each value sequentially corresponding to how it will be indexed
    Card* pC;

    for (int i = 0; i < kCardsInSuit; i++) {            // 13 Iterations (0 .. 12)
        
        pC = &(pDeck[i + (0 * kCardsInSuit)]);          // Set pCard equal to the address of pDeck's index which is calculated by 
        InitializeCard(pC, spade, f[i], kNotWildCard);

        /* pCard->suit = spade;                         // multiplying 0 and kCardsInSuit (13), and then adding the current iteration of i.
        pCard->suitValue = (int) spade;
        pCard->face = f[i];
        pCard->faceValue = (int) f[i]; */

        pC = &(pDeck[i + (1 * kCardsInSuit)]);          // Same as above ^ , but the multiplier is 1. This is so we can 
        InitializeCard(pC, heart, f[i], kNotWildCard);

        /* pCard->suit = heart;                         // assign cards 1-13, 14-26, 27-39, and 40-52 simultaneously.
        pCard->suitValue = (int) heart;
        pCard->face = f[i];
        pCard->faceValue = (int) f[i]; */

        pC = &(pDeck[i + (2 * kCardsInSuit)]);          // Same as above but multiplier is 2.
        InitializeCard(pC, diamond, f[i], kNotWildCard);

        /* pCard->suit = diamond;
        pCard->suitValue = (int) diamond;
        pCard->face = f[i];
        pCard->faceValue = (int) f[i]; */

        pC = &(pDeck[i + (3 * kCardsInSuit)]);          // ^^^
        InitializeCard(pC, club, f[i], kNotWildCard);

        /* pCard->suit = club;
        pCard->suitValue = (int) club;
        pCard->face = f[i];
        pCard->faceValue = (int) f[i]; */
    }
}

void PrintCard(Card* pCard)
{
    char cardStr[20] = {0};
    CardToString(pCard, cardStr);
    printf("%18s", cardStr);
}

void PrintHand(Hand* pHand, char* pHandStr, char* pLeadStr)
{
    printf("%s%s\n", pLeadStr, pHandStr);

    for (int i = 0; i < pHand->cardsDealt; i++) {

        Card* pCard = GetCardInHand(pHand, i);
        printf("%s", pLeadStr);
        PrintCard(pCard);
        printf("\n");
    }
}

void PrintDeck(Card* pDeck)
{
    printf("%d cards in the deck\n\n", kCardsInDeck);
    printf("The ordered deck: \n");
    for (int i = 0; i < kCardsInSuit; i++) {
        int index = i + (0 * kCardsInSuit);
        printf("(%2d)", index + 1);
        PrintCard(&(pDeck[index]));

        index = i + (1 * kCardsInSuit);
        printf("   (%2d)", index + 1);
        PrintCard(&(pDeck[index]));

        index = i + (2 * kCardsInSuit);
        printf("   (%2d)", index + 1);
        PrintCard(&(pDeck[index]));

        index = i + (3 * kCardsInSuit);
        printf("   (%2d)", index + 1);
        PrintCard(&(pDeck[index]));

        printf("\n");
    }
    printf("\n\n");
}













