// start.c
/*
Shuffle cards and put 1, 2, ..., 7 cards into pile_1, pile_2, ..., pile_7 and put the rest of deck in stock.

Set pool[] = { 0, 1, ..., 51}
Move cards from pool[] to stock[] in random order.
Take 1 + 2 + ... + 7 = 28 cards from stock[] and put them into 7 piles.
Use the rest of cards in stock[] as STOCK.
*/
/*
0		1		2		3
DIA(R)	HRT(R)	SPD(B)	CLB(B)
0~12	13~25	26~38	39~51
*/
#include <stdlib.h>
#include <time.h>
#include "solitaire.h"

int stock[TOTAL_NUMBER_OF_CARD] = { 0 };
/* index of the top of the waste pile. It will be set in SetStockIndex(). */
int front = 0;
/* index of the first card of stock and waste pile. It marks the boundary of alive(?) cards and dead(?) cards which move out to somewhere during play. It will be set in SetStockIndex(). */
int rear = 0;

void SetCards(void);
void InitPool(int pool[], int size);
void RandomPick(int pool[], int size);
int SetPile(int size);
void SetStockIndex(int size);

void SetCards(void) {
	int pool[TOTAL_NUMBER_OF_CARD] = { 0 };
	int size = TOTAL_NUMBER_OF_CARD;

	srand(time(NULL));

	InitPool(pool, size);
	RandomPick(pool, size);
	size = SetPile(size);
	SetStockIndex(size);
}
void InitPool(int pool[], int size) {
	for (int i = 0; i < size; ++i)
		pool[i] = i;
}
void RandomPick(int pool[], int size) {
	int boundary = size;
	int picked = 0;

	for (int i = 0; i < size; i++) {
		picked = rand() % boundary;
		stock[i] = pool[picked];
		boundary--;
		pool[picked] = pool[boundary];
	}
}
int SetPile(int size) {
	int card = 0;
	Group* group = NULL;

	for (int pile = 0; pile < NUMBER_OF_PILES; pile++) {
		for (int j = 0; j <= pile; ++j) {
			size--;
			card = stock[size];
			group = ConstructGroup(1);
			MergeCardGroup(card, group);
			AddPileGroup(group, pile);
		}
	}
	return size;
}
void SetStockIndex(int size) {
	front = size;
	rear = size - 1;
}
