// output_pile.c
#include "solitaire.h"

/* each of the four int means the topmost card number in each outputpile. 0 means empty, 13 means full. */
int output_pile[4] = { 0, 0, 0, 0 };

int GetOutputPileCard(Shape);
void AddOutputPileCard(Shape shape);
int RemoveOutputPileCard(Shape);
int IsAddableOutputPileCard(int card, Shape shape);
int IsOutputPileEmpty(Shape shape);
int IsOutputPileFull(Shape shape);

int GetOutputPileCard(Shape shape) {
	int number = output_pile[shape];
	return GetCard(number, shape);
}
void AddOutputPileCard(Shape shape) {
	output_pile[shape]++;
}
int RemoveOutputPileCard(Shape shape) {
	int number = output_pile[shape];
	output_pile[shape]--;
	return GetCard(number, shape);
}
int IsAddableOutputPileCard(int card, Shape shape) {
	int top_card = GetOutputPileCard(shape);
	if (IsOutputPileFull(shape))
		return 0;
	if (shape != GetCardShape(card))
		return 0;
	if (IsOutputPileEmpty(shape)) {
		if (GetCardNumber(card) == 1)
			return 1;
		return 0;
	}
	if (GetCardNumber(top_card) + 1 == GetCardNumber(card))
		return 1;
	return 0;
}
int IsOutputPileEmpty(Shape shape) {
	if (output_pile[shape] == 0)
		return 1;
	return 0;
}
int IsOutputPileFull(Shape shape) {
	if (output_pile[shape] == 13)
		return 1;
	return 0;
}
