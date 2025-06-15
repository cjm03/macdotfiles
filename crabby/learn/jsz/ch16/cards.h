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

#endif
