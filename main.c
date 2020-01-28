// main.c
#include "solitaire.h"

int main() {
	/* Shuffle cards and set 1, 2, ..., 7 cards in pile_1, pile_2, ..., pile_7 and put the rest of deck in stock. */
	SetCards();
	ShowRules();
	Play();
	/* free all the allocated memories. */
	End();
	return 0;
}
