#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/* Enumerations */
typedef enum { club = 1, diamond, heart, spade } Suit;
typedef enum { one = 1, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace } Face;
enum { kCardsInDeck = 52, kCardsInSuit = 13, kCardsInHand = 5, kNumHands = 4 };

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
typedef struct {
    Card* shuffled[kCardsInDeck];
    int numDealt;
    bool bIsShuffled;
} Shuffled;

/* Constants */
const bool kWildCard    = true;
const bool kNotWildCard = false;

/* Prototypes */

    // Operations on a Hand
void InitializeHand(    Hand* pHand);
void AddCardToHand(     Hand* pHand, Card* pCard);
void PrintHand(         Hand* pHand, char* pHandStr, char* pLeadStr);
Card** GetCardInHand(   Hand* pHand, int cardIndex);

    // Operations on a Deck
void InitializeDeck(    Card* pDeck);
Card* DealCardFromDeck( Card deck[], int index);
void PrintDeck(         Card* pDeck);
    
    // Operations on a Card (or related)
void CardToString(      Card* pCard, char pCardStr[20]);
void InitializeCard(    Card* pCard, Suit s, Face f, bool w);
void PrintCard(         Card* pCard);

    // Operations related to shuffling
void InitializeShuffled(Shuffled* pShuffled, Deck[] pDeck);
void PrintShuffled(     Shuffled* pShuffled);
void ShuffleDeck(       Shuffled* pShuffled);

/*--------------------------------------------------------------------------------------------------------------------------------*/

/* MAIN */
int main(void)
{
    Card deck[kCardsInDeck];
    Card* pDeck = deck;
    InitializeDeck(&deck[0]);
    Hand h1, h2, h3, h4;
    InitializeHand(&h1);
    InitializeHand(&h2);
    InitializeHand(&h3);
    InitializeHand(&h4);
    
    for (int i = 0; i < kCardsInHand; i++) {

        AddCardToHand(&h1, DealCardFromDeck(pDeck, i     ));
        AddCardToHand(&h2, DealCardFromDeck(pDeck, i + 13));
        AddCardToHand(&h3, DealCardFromDeck(pDeck, i + 26));
        AddCardToHand(&h4, DealCardFromDeck(pDeck, i + 39));
    }

    PrintHand(&h1, "Hand 1:", "                    ");
    PrintHand(&h2, "Hand 2:", " ");
    PrintHand(&h3, "Hand 3:", "                                    ");
    PrintHand(&h4, "Hand 4:", "                    ");
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

Card* DealCardFromDeck(Card deck[], int index)
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
    pHand->pCard1 = NULL;
    pHand->pCard2 = NULL;
    pHand->pCard3 = NULL;
    pHand->pCard4 = NULL;
    pHand->pCard5 = NULL;
}

void InitializeDeck(Card* pDeck)    // pass a pointer pointing to deck of type Card
{ 
    Face f[] = {two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace}; // Lookup table with each value sequentially corresponding to how it will be indexed
    Card* pC;

    for (int i = 0; i < kCardsInSuit; i++) {            // 13 Iterations (0 .. 12)
        
        pC = &(pDeck[i + (0 * kCardsInSuit)]);          // Set pCard equal to the address of pDeck's index which is calculated by 
        InitializeCard(pC, spade, f[i], kNotWildCard);

        pC = &(pDeck[i + (1 * kCardsInSuit)]);          // Same as above ^ , but the multiplier is 1. This is so we can 
        InitializeCard(pC, heart, f[i], kNotWildCard);

        pC = &(pDeck[i + (2 * kCardsInSuit)]);          // Same as above but multiplier is 2.
        InitializeCard(pC, diamond, f[i], kNotWildCard);

        pC = &(pDeck[i + (3 * kCardsInSuit)]);          // ^^^
        InitializeCard(pC, club, f[i], kNotWildCard);
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

        Card* pCard = *GetCardInHand(pHand, i);
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

void ShuffleDeck(Shuffled* pDeck)
{
    long randomIndex;           // long to store the shuffling index
    srand(time(NULL));          // seed the PRNG

    Card* pTmpCard;             // create temp card pointer for swapping
    for (int thisIndex = 0; thisIndex < kCardsInDeck; thisIndex++) {
        randomIndex = rand() % kCardsInDeck; // 0 .. 51
          // swap
        pTmpCard                        = pDeck->shuffled[thisIndex];
        pDeck->shuffled[thisIndex]      = pDeck->shuffled[randomIndex];
        pDeck->shuffled[randomIndex]    = pTmpCard;
    }
    pDeck->bIsShuffled = true;
}













