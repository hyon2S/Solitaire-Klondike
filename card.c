// card.c
/*
0		1		2		3
DIA(R)	HRT(R)	SPD(B)	CLB(B)
0~12	13~25	26~38	39~51
*/
#include "solitaire.h"

const int kMaxCardNumber = 13;
const int kNumberOfColor = 2;
const int kNumberOfShape = 4;

int GetCardNumber(int card);
Shape GetCardShape(int card);
Color GetCardColor(int card);
int GetCard(int number, Shape shape);
/* Check the rule to place a card on another card in piles. */
int IsAddableCardToCard(int below, int above);

int GetCardNumber(int card) {
	int number = card % kMaxCardNumber + 1;
	return number;
}
Shape GetCardShape(int card) {
	return card / kMaxCardNumber;
}
Color GetCardColor(int card) {
	return card / (kMaxCardNumber * kNumberOfColor);
}
int GetCard(int number, Shape shape) {
	return kMaxCardNumber * shape + number - 1;
}
int IsAddableCardToCard(int below, int above) {
	int below_number = GetCardNumber(below);
	int above_number = GetCardNumber(above);
	Color below_color = GetCardColor(below);
	Color above_color = GetCardColor(above);

	if (below_number != above_number + 1)
		return 0;
	if (below_color == above_color)
		return 0;
	return 1;
}
