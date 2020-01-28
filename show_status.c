// show_status.c

#include <stdio.h>
#include "solitaire.h"

/***************************************************************************
       STOCK      WASTE PILE                                      OUTPUT PILE
     :15 CARDS    : 3 CARDS                        DIA(R)      HRT(R)      SPD(B)      CLB(B)
      -------      -------                        -------     -------     -------     -------
     |       |    |       |                      |       |   |       |   |       |   |       |
     |       |    | 10 of |                      |   0   |   |   A   |   |   2   |   |   A   |
     |       |    | DIA(R)|                      |       |   |       |   |       |   |       |
     |       |    |       |                      |       |   |       |   |       |   |       |
      -------      -------                        -------     -------     -------     -------


    PILE_1        PILE_2        PILE_3        PILE_4        PILE_5        PILE_6        PILE_7
      ?         J of SPD(B)       ?
 10 of DIA(R)  10 of HRT(R)  10 of HRT(R)

...

Players can see the cards in the top group of each piles only.
Players can't see the other groups in piles.
'?' means hidden cards.
******************************************************************************
       STOCK      WASTE PILE                                      OUTPUT PILE
     : 0 CARDS    : 0 CARDS                        DIA(R)      HRT(R)      SPD(B)      CLB(B)
      -------      -------                        -------     -------     -------     -------
space|       |spa |       | space_3              |       |spa|       |   |       |   |       |
_1   |       |ce_2|       |                      |   K   |ce_|   Q   |   |   K   |   |   J   |
     |       |    |       |                      |       |4  |       |   |       |   |       |
     |       |    |       |                      |       |   |       |   |       |   |       |
      -------      -------                        -------     -------     -------     -------

*********************************************************************************
spa PILE_1 space_2PILE_2        PILE_3        PILE_4        PILE_5        PILE_6        PILE_7
ce_1  ?         J of SPD(B)       ?
 10 of DIA(R)  10 of HRT(R)  10 of HRT(R)

**********************************************************************************/
void ShowStatus(int card_width);
/*       STOCK      WASTE PILE                                      OUTPUT PILE */
void PrintStockOutputPileTitle(int space_1, int space_2, int space_3);
/*     :15 CARDS    : 3 CARDS                        DIA(R)      HRT(R)      SPD(B)      CLB(B) */
void PrintStockNumberOutputPileShape(int space_1, int space_2, int space_3, int space_4);
/*    -------      -------                        -------     -------     -------     -------
     |       |    |       |                      |       |   |       |   |       |   |       |
     |       |    | 10 of |                      |   0   |   |   A   |   |   2   |   |   A   |
     |       |    | DIA(R)|                      |       |   |       |   |       |   |       |
     |       |    |       |                      |       |   |       |   |       |   |       |
      -------      -------                        -------     -------     -------     -------
*/
void PrintStockOutputPileCard(int space_1, int space_2, int space_3, int space_4, int card_width);
/*      -------      -------                        -------     -------     -------     ------- */
void PrintStockOutputPileCardEdge(int space_1, int space_2, int space_3, int space_4, int card_width);
/*     |       |    |       | */
void PrintstockCardEmpty(int space_1, int space_2, int card_width);
/*     |       |    | 10 of | */
void PrintstockCardFilledNumber(int space_1, int space_2, int card_width);
/*     |       |    | DIA(R)| */
void PrintstockCardFilledShape(int space_1, int space_2, int card_width);
/*                      |       |   |       |   |       |   |       | */
void PrintOutputPileCardEmpty(int space_3, int space_4, int card_width);
/*                      |   0   |   |   A   |   |   2   |   |   A   | */
void PrintOutputPileCardFilled(int space_3, int space_4);
/*    PILE_1        PILE_2        PILE_3        PILE_4        PILE_5        PILE_6        PILE_7 */
void PrintPileTitle(int space_1, int space_2);

void ShowStatus(int card_width) {
	BreakLine(1);
	PrintStockOutputPileTitle(7, 6, 38);
	BreakLine(1);
	PrintStockNumberOutputPileShape(5, 4, 24, 6);
	BreakLine(1);
	PrintStockOutputPileCard(5, 4, 22, 3, card_width);
	BreakLine(3);
	PrintPileTitle(4, 8);
	BreakLine(1);
	PrintPiles(1, 2, 12);
	BreakLine(1);
}
void PrintStockOutputPileTitle(int space_1, int space_2, int space_3) {
	PrintSpace(space_1);
	printf("STOCK");
	PrintSpace(space_2);
	printf("WASTE PILE");
	PrintSpace(space_3);
	printf("OUTPUT PILE");
}
void PrintStockNumberOutputPileShape(int space_1, int space_2, int space_3, int space_4) {
	PrintSpace(space_1);
	putchar(':');
	PrintTwoDigitNumber(GetNumberOfCardStock());
	printf(" CARDS");
	PrintSpace(space_2);
	putchar(':');
	PrintTwoDigitNumber(GetNumberOfCardWastePile());
	printf(" CARDS");
	PrintSpace(space_3 - space_4);
	for (int i = 0; i < kNumberOfShape; ++i) {
		PrintSpace(space_4);
		PrintShape(i);
		putchar('(');
		PrintColor(i / 2);
		putchar(')');
	}
}
void PrintStockOutputPileCard(int space_1, int space_2, int space_3, int space_4, int card_width) {
	/* 1st line */
	PrintStockOutputPileCardEdge(space_1, space_2, space_3, space_4, card_width);
	BreakLine(1);
	/* 2nd line */
	PrintstockCardEmpty(space_1, space_2, card_width);
	PrintOutputPileCardEmpty(space_3, space_4, card_width);
	BreakLine(1);
	/* 3rd line */
	if (IsWastePileEmpty())
		PrintstockCardEmpty(space_1, space_2, card_width);
	else
		PrintstockCardFilledNumber(space_1, space_2, card_width);
	PrintOutputPileCardFilled(space_3, space_4);
	BreakLine(1);
	/* 4th line */
	if (IsWastePileEmpty())
		PrintstockCardEmpty(space_1, space_2, card_width);
	else
		PrintstockCardFilledShape(space_1, space_2, card_width);
	PrintOutputPileCardEmpty(space_3, space_4, card_width);
	BreakLine(1);
	/* 5th line */
	PrintstockCardEmpty(space_1, space_2, card_width);
	PrintOutputPileCardEmpty(space_3, space_4, card_width);
	BreakLine(1);
	/* 6th line */
	PrintStockOutputPileCardEdge(space_1, space_2, space_3, space_4, card_width);
}
void PrintStockOutputPileCardEdge(int space_1, int space_2, int space_3, int space_4, int card_width) {
	PrintSpace(space_1 + 1);
	PrintCardUpperLine(card_width);
	PrintSpace(space_2 + 2);
	PrintCardUpperLine(card_width);
	PrintSpace(space_3 - space_4);
	for (int i = 0; i < kNumberOfShape; i++) {
		PrintSpace(space_4 + 2);
		PrintCardUpperLine(card_width);
	}
}
void PrintstockCardEmpty(int space_1, int space_2, int card_width) {
	PrintSpace(space_1);
	putchar('|');
	PrintSpace(card_width);
	putchar('|');
	PrintSpace(space_2);
	putchar('|');
	PrintSpace(card_width);
	putchar('|');
}
void PrintstockCardFilledNumber(int space_1, int space_2, int card_width) {
	PrintSpace(space_1);
	putchar('|');
	PrintSpace(card_width);
	putchar('|');
	PrintSpace(space_2);
	putchar('|');
	PrintSpace(1);
	PrintTwoDigitCardNumber(GetCardNumber(GetWastePileCard()));
	printf(" of ");
	putchar('|');
}
void PrintstockCardFilledShape(int space_1, int space_2, int card_width) {
	PrintSpace(space_1);
	putchar('|');
	PrintSpace(card_width);
	putchar('|');
	PrintSpace(space_2);
	putchar('|');
	PrintSpace(1);
	PrintShape(GetCardShape(GetWastePileCard()));
	putchar('(');
	PrintColor(GetCardColor(GetWastePileCard()));
	putchar(')');
	putchar('|');
}
void PrintOutputPileCardEmpty(int space_3, int space_4, int card_width) {
	PrintSpace(space_3 - space_4);
	for (int i = 0; i < kNumberOfShape; i++) {
		PrintSpace(space_4);
		putchar('|');
		PrintSpace(card_width);
		putchar('|');
	}
}
void PrintOutputPileCardFilled(int space_3, int space_4) {
	PrintSpace(space_3 - space_4);
	for (int i = 0; i < kNumberOfShape; i++) {
		PrintSpace(space_4);
		putchar('|');
		PrintSpace(2);
		if (IsOutputPileEmpty(i))
			PrintTwoDigitCardNumber(0);
		else
			PrintTwoDigitCardNumber(GetCardNumber(GetOutputPileCard(i)));
		PrintSpace(3);
		putchar('|');
	}
}
void PrintPileTitle(int space_1, int space_2) {
	PrintSpace(space_1);
	for (int i = 1; i < NUMBER_OF_PILES; i++) {
		printf("PILE_%d", i);
		PrintSpace(space_2);
	}
	printf("PILE_%d", NUMBER_OF_PILES);
}
