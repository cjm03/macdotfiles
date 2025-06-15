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
    Card* hand[kCardsInHand];
    int cardsDealt;
} Hand;
typedef struct {
    Card ordered[kCardsInDeck];
    Card* shuffled[kCardsInDeck];
    int numDealt;
    bool bIsShuffled;
} Deck;
typedef struct {
    Card* shuffled[kCardsInDeck];
    int numDealt;
    bool bIsShuffled;
} Shuffled;

/* Constants */
const bool kWildCard    = true;
const bool kNotWildCard = false;
// ACTH = 1, DCFD = 1, CTS = 1, PC = 6, PH = 4, IC = 4, IH = 1, ID = 1, PD = 2, SD = 1
/* Prototypes */

    // Operations on a Hand
void InitializeHand(    Hand* pHand);
void AddCardToHand(     Hand* pHand,            Card* pCard);
void PrintHand(         Hand* pHand,            char* pHandStr,     char* pLeadStr);
void PrintAllHands(     Hand* hands[kNumHands]);

    // Operations on a Deck
void InitializeDeck(    Deck* pDeck);
Card* DealCardFromDeck( Deck* pDeck);
void PrintDeck(         Deck* pDeck);
    
    // Operations on a Card (or related)
void CardToString(      Card* pCard,            char pCardStr[20]);
void InitializeCard(    Card* pCard,            Suit s,             Face f,     bool w);
void PrintCard(         Card* pCard);

    // Operations related to shuffling
void ShuffleDeck(       Deck* pDeck);
// void PrintShuffled(     Shuffled* pShuffled);
// void InitializeShuffled(Shuffled* pShuffled, Deck[] pDeck);

/*--------------------------------------------------------------------------------------------------------------------------------*/

/* MAIN */
int main(void)
{
    Deck deck;
    Deck* pDeck = &deck;
    InitializeDeck(pDeck);                                          // ID
    PrintDeck(pDeck);                                               // PD
    ShuffleDeck(pDeck);                                             // SD
    PrintDeck(pDeck);                                               // PD
    Hand h1, h2, h3, h4;
    Hand* hands[] = {&h1, &h2, &h3, &h4};
    
    for (int i = 0; i < kNumHands; i++) {

        InitializeHand(hands[i]);                                   // IH
    }

    for (int i = 0; i < kCardsInHand; i++) {
        for (int j = 0; j < kNumHands; j++) {
            
            AddCardToHand(hands[j], DealCardFromDeck(pDeck));       // ACTH = 1, DCFD = 1, CTS = 1, PC = 6, PH = 4, IC = 4, IH = 1, ID = 1, PD = 2, SD = 1
        }
    }
    PrintAllHands(hands);
    PrintDeck(pDeck);
}

/*--------------------------------------------------------------------------------------------------------------------------------*/

/* Functions */

// ##########################
// ###                   ###
// ###   CardToString    ### 
// ###                   ###
// ##########################
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

// ############################
// ###                     ###
// ###    AddCardToHand    ###
// ###                     ###
// ############################
void AddCardToHand(Hand* pHand, Card* pCard)
{
    if (pHand->cardsDealt == kCardsInHand) return;
    pHand->hand[pHand->cardsDealt] = pCard;
    pHand->cardsDealt++;
}

// ###############################
// ###                        ###
// ###    DealCardFromDeck    ###
// ###                        ###
// ###############################
Card* DealCardFromDeck(Deck* pDeck)
{
    Card* pCard = pDeck->shuffled[pDeck->numDealt];
    pDeck->shuffled[pDeck->numDealt] = NULL;
    pDeck->numDealt++;
    return pCard;
}

// #############################
// ###                      ###
// ###    InitializeCard    ###
// ###                      ###
// #############################
void InitializeCard(Card* pCard, Suit s, Face f, bool w)
{
    pCard->suit         = s;
    pCard->suitValue    = (int) s;
    pCard->face         = f;
    pCard->faceValue    = (int) f;
    pCard->isWild       = w;
}

// #############################
// ###                      ###
// ###    InitializeHand    ###
// ###                      ###
// #############################
void InitializeHand(Hand* pHand)
{
    pHand->cardsDealt = 0;

    for (int i = 0; i < kCardsInHand; i++) {

        pHand->hand[i] = NULL;
    }
}

// #############################
// ###                      ###
// ###    InitializeDeck    ###
// ###                      ###
// #############################
void InitializeDeck(Deck* pDeck)    // pass a pointer pointing to deck of type Card     // CTS = 1, PC = 6, PH = 4, IC = 4
{ 
    Face f[] = {two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace}; // Lookup table with each value sequentially corresponding to how it will be indexed
    Card* pC;

    for (int i = 0; i < kCardsInSuit; i++) {            // 13 Iterations (0 .. 12)
        
        pC = &(pDeck->ordered[i + (0 * kCardsInSuit)]);          // Set pCard equal to the address of pDeck's index which is calculated by 
        InitializeCard(pC, spade, f[i], kNotWildCard);

        pC = &(pDeck->ordered[i + (1 * kCardsInSuit)]);          // Same as above ^ , but the multiplier is 1. This is so we can 
        InitializeCard(pC, heart, f[i], kNotWildCard);

        pC = &(pDeck->ordered[i + (2 * kCardsInSuit)]);          // Same as above but multiplier is 2.
        InitializeCard(pC, diamond, f[i], kNotWildCard);

        pC = &(pDeck->ordered[i + (3 * kCardsInSuit)]);          // ^^^
        InitializeCard(pC, club, f[i], kNotWildCard);
    }
    for (int i = 0; i < kCardsInDeck; i++) {
        pDeck->shuffled[i] = &(pDeck->ordered[i]);
    }
    pDeck->bIsShuffled = false;
    pDeck->numDealt = 0;
}

// ########################
// ###                 ###
// ###    PrintCard    ###
// ###                 ###
// ########################
void PrintCard(Card* pCard)
{
    char cardStr[20] = {0};
    CardToString(pCard, cardStr);                               // CTS = 1, PC = 6, PH = 4
    printf("%18s", cardStr);
}

// ##########################
// ###                   ###
// ###    PrintHand      ###
// ###                   ###
// ##########################
void PrintHand(Hand* pHand, char* pHandStr, char* pLeadStr)
{
    printf("%s%s\n", pLeadStr, pHandStr);

    for (int i = 0; i < kCardsInHand; i++) {

        printf("%s", pLeadStr);
        PrintCard(pHand->hand[i]);                              // PC
        printf("\n");
    }
}

// ########################
// ###                 ###
// ###    PrintDeck    ###
// ###                 ###
// ########################
void PrintDeck(Deck* pDeck)
{
    printf("%d cards in the deck\n\n", kCardsInDeck);
    printf("Deck %s shuffled\n", pDeck->bIsShuffled ? "is" : "is not");
    printf("%d cards dealt into %d hands\n", pDeck->numDealt, kNumHands);

    if (pDeck->bIsShuffled == true) {
        if (pDeck->numDealt > 0) {
            printf("The remaining shuffled deck:\n");
        } else {
            printf("The full shuffled deck:\n");
        }
        for (int i = pDeck->numDealt, j = 0; i < kCardsInDeck; i++, j++) {
            printf("(%2d)", i + 1);
            PrintCard(pDeck->shuffled[i]);                      // PC
            if (j == 3) {
                printf("\n");
                j = -1;
            } else {
                printf("\t");
            }
        }
    } else {
        printf("The ordered deck: \n");
        for (int i = 0; i < kCardsInSuit; i++) {
            int index = i + (0 * kCardsInSuit);
            printf("(%2d)", index + 1);
            PrintCard(&(pDeck->ordered[index]));                // PC

            index = i + (1 * kCardsInSuit);
            printf("   (%2d)", index + 1);
            PrintCard(&(pDeck->ordered[index]));                // PC

            index = i + (2 * kCardsInSuit);
            printf("   (%2d)", index + 1);
            PrintCard(&(pDeck->ordered[index]));                // PC

            index = i + (3 * kCardsInSuit);
            printf("   (%2d)", index + 1);
            PrintCard(&(pDeck->ordered[index]));                // PC

            printf("\n");
        }
    }
    printf("\n\n");
}

// ##########################
// ###                   ###
// ###    ShuffleDeck    ###
// ###                   ###
// ##########################
void ShuffleDeck(Deck* pDeck)
{
    long randIndex;           // long to store the shuffling index
    srand(time(NULL));          // seed the PRNG

    Card* pTmpCard;             // create temp card pointer for swapping
    for (int thisIndex = 0; thisIndex < kCardsInDeck; thisIndex++) {
        randIndex = rand() % kCardsInDeck; // 0 .. 51
          // swap
        pTmpCard                   = pDeck->shuffled[thisIndex];
        pDeck->shuffled[thisIndex] = pDeck->shuffled[randIndex];
        pDeck->shuffled[randIndex] = pTmpCard;
    }
    pDeck->bIsShuffled = true;
}

// ##########################
// ###                   ###
// ###   PrintAllHands   ###
// ###                   ###
// ##########################
void PrintAllHands(Hand* hands[kNumHands])
{
    PrintHand(hands[0], "Hand 1:", "                    ");                 // PH
    PrintHand(hands[1], "Hand 2:", " ");                                    // PH
    PrintHand(hands[2], "Hand 3:", "                                    "); // PH
    PrintHand(hands[3], "Hand 4:", "                    ");                 // PH
}












