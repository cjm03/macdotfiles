#ifndef CARDS_H
#define CARDS_H

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
typedef struct { Suit suit; int suitValue; Face face; int faceValue; bool isWild; } Card;                     
typedef struct { Card* hand[kCardsInHand]; int cardsDealt; } Hand;
typedef struct { Card ordered[kCardsInDeck]; Card* shuffled[kCardsInDeck]; int numDealt; bool bIsShuffled; } Deck;
typedef struct { Card* shuffled[kCardsInDeck]; int numDealt; bool bIsShuffled; } Shuffled;

/* Constants */
const bool kWildCard = true;
const bool kNotWildCard = false;

/* Prototypes */
void InitializeHand(    Hand* pHand);
void InitializeDeck(    Deck* pDeck);
Card* DealCardFromDeck( Deck* pDeck);
void PrintDeck(         Deck* pDeck);
void PrintCard(         Card* pCard);
void ShuffleDeck(       Deck* pDeck);
void PrintAllHands(     Hand* hands[kNumHands]);
void AddCardToHand(     Hand* pHand, Card* pCard);
void CardToString(      Card* pCard, char pCardStr[20]);
void InitializeCard(    Card* pCard, Suit s, Face f, bool w);
void PrintHand(         Hand* pHand, char* pHandStr, char* pLeadStr);

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
    if (pHand->cardsDealt == kCardsInHand) return;
    pHand->hand[pHand->cardsDealt] = pCard;
    pHand->cardsDealt++;
}

Card* DealCardFromDeck(Deck* pDeck)
{
    Card* pCard = pDeck->shuffled[pDeck->numDealt];
    pDeck->shuffled[pDeck->numDealt] = NULL;
    pDeck->numDealt++;
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

    for (int i = 0; i < kCardsInHand; i++) {

        pHand->hand[i] = NULL;
    }
}

void InitializeDeck(Deck* pDeck)    
{ 
    Face f[] = {two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace}; 
    Card* pC;

    for (int i = 0; i < kCardsInSuit; i++) {            
        
        pC = &(pDeck->ordered[i + (0 * kCardsInSuit)]);          
        InitializeCard(pC, spade, f[i], kNotWildCard);

        pC = &(pDeck->ordered[i + (1 * kCardsInSuit)]);           
        InitializeCard(pC, heart, f[i], kNotWildCard);

        pC = &(pDeck->ordered[i + (2 * kCardsInSuit)]);          
        InitializeCard(pC, diamond, f[i], kNotWildCard);

        pC = &(pDeck->ordered[i + (3 * kCardsInSuit)]);          
        InitializeCard(pC, club, f[i], kNotWildCard);
    }
    for (int i = 0; i < kCardsInDeck; i++) {
        pDeck->shuffled[i] = &(pDeck->ordered[i]);
    }
    pDeck->bIsShuffled = false;
    pDeck->numDealt = 0;
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

    for (int i = 0; i < kCardsInHand; i++) {

        printf("%s", pLeadStr);
        PrintCard(pHand->hand[i]);                              
        printf("\n");
    }
}

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
            PrintCard(pDeck->shuffled[i]);                      
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
            PrintCard(&(pDeck->ordered[index]));                

            index = i + (1 * kCardsInSuit);
            printf("   (%2d)", index + 1);
            PrintCard(&(pDeck->ordered[index]));                

            index = i + (2 * kCardsInSuit);
            printf("   (%2d)", index + 1);
            PrintCard(&(pDeck->ordered[index]));                

            index = i + (3 * kCardsInSuit);
            printf("   (%2d)", index + 1);
            PrintCard(&(pDeck->ordered[index]));                

            printf("\n");
        }
    }
    printf("\n\n");
}

void ShuffleDeck(Deck* pDeck)
{
    long randIndex;           
    srand(time(NULL));          

    Card* pTmpCard;            
    for (int thisIndex = 0; thisIndex < kCardsInDeck; thisIndex++) {
        randIndex = rand() % kCardsInDeck; 
          
        pTmpCard                   = pDeck->shuffled[thisIndex];
        pDeck->shuffled[thisIndex] = pDeck->shuffled[randIndex];
        pDeck->shuffled[randIndex] = pTmpCard;
    }
    pDeck->bIsShuffled = true;
}

void PrintAllHands(Hand* hands[kNumHands])
{
    PrintHand(hands[0], "Hand 1:", "                    ");                 
    PrintHand(hands[1], "Hand 2:", " ");                                    
    PrintHand(hands[2], "Hand 3:", "                                    "); 
    PrintHand(hands[3], "Hand 4:", "                    ");                 
}









#endif
