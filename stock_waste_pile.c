// stock_waste_pile.c
/*
int stock[TOTAL_NUMBER_OF_CARD];
stock : 0~(front - 1)
waste pile: front ~ rear
int front : index of the top of the waste pile.
int rear : index of the first card of stock and waste pile. It marks the boundary of alive(?) cards and dead(?) cards which move out to somewhere during play.
*/
#include "solitaire.h"

int GetNumberOfCardStock(void);
int GetNumberOfCardWastePile(void);
int GetWastePileCard(void);
int IsStockEmpty(void);
int IsWastePileEmpty(void);
/* move a card from stock to waste pile so that player can see the card. */
void StockToWastePile(void);
void UndoStockToWastePile(void);
/* Remove the top of waste pile card and return the card. */
int RemoveWastePileCard(void);
/* it works as UndoRemoveWastePileCard(). */
void AddWastePileCard(int card);
/* move the whole cards in waste pile to stock. */
void WastePileToStock(void);

int GetNumberOfCardStock(void) { return front; }
int GetNumberOfCardWastePile(void) { return rear + 1 - front; }
int GetWastePileCard(void) { return stock[front]; }
int IsStockEmpty(void) {
	if (GetNumberOfCardStock() == 0)
		return 1;
	return 0;
}
int IsWastePileEmpty(void) {
	if (GetNumberOfCardWastePile() == 0)
		return 1;
	return 0;
}
void StockToWastePile(void) { front--; }
void UndoStockToWastePile(void) { front++; }
int RemoveWastePileCard(void) {
	int card = stock[front];

	for (int i = front; i < rear; i++)
		stock[i] = stock[i + 1];
	rear--;
	return card;
}
void AddWastePileCard(int card) {
	for (int i = rear; i >= front; i--)
		stock[i] = stock[i + 1];
}
void WastePileToStock(void) { front = rear + 1; }
