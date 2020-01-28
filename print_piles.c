// print_piles.c

/***************************************************************************
s     ?      sp J of SPD(B)       ?
p10 of DIA(R)ac10 of HRT(R)  10 of HRT(R)
a            e_
c            2               pile_card_wi
e                            dth
_
1
********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "solitaire.h"

/*
      ?         J of SPD(B)       ?        ......
 10 of DIA(R)  10 of HRT(R)  10 of HRT(R)  ......
 .....
*/
void PrintPiles(int space_1, int space_2, int pile_card_width);
/* return the number of '?' cards in pile. doesn't count top group. */
int GetPileNumberOfUnknownCards(int pile);
/* return the number of cards in pile. */
int GetPileNumberOfCards(int pile);
/* 10 of DIA(R) */
int PrintPileTopGroupNthCard(int pile, int index);

void PrintPiles(int space_1, int space_2, int pile_card_width) {
	int pile_number_of_unknown_cards[NUMBER_OF_PILES] = { 0 };
	int pile_number_of_cards[NUMBER_OF_PILES] = { 0 };
	int pile_index[NUMBER_OF_PILES] = { 0 };

	int number_of_lines = 0;

	for (int pile = 0; pile < NUMBER_OF_PILES; ++pile)
		if (IsPileEmpty(pile)) {
			pile_number_of_unknown_cards[pile] = 0;
			pile_number_of_cards[pile] = 0;
		} else {
			pile_number_of_unknown_cards[pile] = GetPileNumberOfUnknownCards(pile);
			pile_number_of_cards[pile] = GetPileNumberOfCards(pile);
		}

	number_of_lines = GetMax(pile_number_of_cards, NUMBER_OF_PILES);

	/* printing part. */
	for (int line = 0; line < number_of_lines; ++line) {
		PrintSpace(space_1);
		for (int pile = 0; pile < NUMBER_OF_PILES; ++pile) {
			if (pile_number_of_unknown_cards[pile] > line)
				PrintPileQuestionMark(pile_card_width);
			else if (pile_number_of_cards[pile] > line) {
				PrintPileTopGroupNthCard(pile, pile_index[pile]);
				pile_index[pile]++;
			}
			else
				PrintSpace(pile_card_width);
			PrintSpace(space_2);
		}
		BreakLine(1);
	}
}
int GetPileNumberOfUnknownCards(int pile) {
	int sum = 0;
	Group* group = NULL;
	for (int index = 0; index < pile_top[pile]; ++index) { /* doesn't include top group. */
		group = GetPileNthGroup(pile, index);
		sum += group->top + 1;
	}
	return sum;
}
int GetPileNumberOfCards(int pile) {
	int sum = 0;
	Group* group = NULL;
	for (int index = 0; index <= pile_top[pile]; ++index) { /* include top group. */
		group = GetPileNthGroup(pile, index);
		sum += group->top + 1;
	}
	return sum;
}
int PrintPileTopGroupNthCard(int pile, int index) {
	Group* group = GetPileTopGroup(pile);
	int card = GetGroupNthCard(group, index);
	PrintTwoDigitCardNumber(GetCardNumber(card));
	printf(" of ");
	PrintShape(GetCardShape(card));
	putchar('(');
	PrintColor(GetCardColor(card));
	putchar(')');
}
