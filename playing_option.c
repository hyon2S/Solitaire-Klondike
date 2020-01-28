// playing_option.c

#include <stdio.h>
#include <stdlib.h>
#include "solitaire.h"

int ShowOptions(void);
void DoOption(int choice);
/* move a card from stock to waste pile so that player can see the card. */
int OptionStockToWastePile(void);
/* move the whole cards in waste pile to stock. it works when the stock is empty only. */
int OptionWastePileToStock(void);
int OptionWastePileToPile(void);
int OptionWastePileToOutputPile(void);
int OptionPileToPile(void);
int OptionPileToOutputPile(void);
void ShowRules(void);

int ShowOptions(void) {
	int choice = 0;

	puts("Choose action (1 ~ 8) and then press enter:");
	printf("%d. Turn over a card from stock\n", STOCK_TO_WASTE_PILE);
	printf("%d. Move the whole cards in waste pile to stock\n", WASTE_PILE_TO_STOCK);
	printf("%d. Move a card from waste pile to pile\n", WASTE_PILE_TO_PILE);
	printf("%d. Move a card from waste pile to output pile\n", WATSTE_PILE_TO_OUTPUT_PILE);
	printf("%d. Move cards from one pile to another pile\n", PILE_TO_PILE);
	printf("%d. Move a card from pile to output pile\n", PILE_TO_OUTPUT_PILE);
	printf("%d. Show rules\n", SHOW_RULES);
	printf("%d. Stop game\n", STOP_GAME);

	choice = ChooseNumber(1, 8);
	return choice;
}
void DoOption(int choice) {
	printf("Do Option %d.\n", choice);
	PrintSleep(1);
	switch (choice) {
		case STOCK_TO_WASTE_PILE:
			OptionStockToWastePile();
			break;
		case WASTE_PILE_TO_STOCK:
			OptionWastePileToStock();
			break;
		case WASTE_PILE_TO_PILE:
			OptionWastePileToPile();
			break;
		case WATSTE_PILE_TO_OUTPUT_PILE:
			OptionWastePileToOutputPile();
			break;
		case PILE_TO_PILE:
			OptionPileToPile();
			break;
		case PILE_TO_OUTPUT_PILE:
			OptionPileToOutputPile();
			break;
		case SHOW_RULES: ShowRules(); break;
	}
}
int OptionStockToWastePile(void) {
	if (IsStockEmpty()) {
		PrintNoCard();
		return 0;
	}
	StockToWastePile();
	puts("Turn over a card from stock and place it on waste pile.");
	return 1;
}
int OptionWastePileToStock(void) {
	if (IsStockEmpty()) {
		WastePileToStock();
		puts("Move the whole cards in waste pile to stock.");
		return 1;
	}
	PrintCannotMove();
	return 0;
}
int OptionWastePileToPile(void) {
	int pile_index = 0;
	int waste_pile_card = 0;

	if (IsWastePileEmpty()) {
		PrintNoCard();
		return 0;
	}
	puts("Choose pile number (1 ~ 7):");
	pile_index = ChoosePile(); /* pile_index : 0~ 6 */
	waste_pile_card = GetWastePileCard();
	if (IsAddablePileCard(waste_pile_card, pile_index)) {
		RemoveWastePileCard();
		AddPileCard(waste_pile_card, pile_index);
		printf("Move a card from waste pile to pile_%d.\n", pile_index + 1); /* 1~7 */
		return 1;
	}
	PrintCannotMove();
	return 0;
}
int OptionWastePileToOutputPile(void) {
	int output_pile_index = 0;
	int waste_pile_card = 0;

	if (IsWastePileEmpty()) {
		PrintNoCard();
		return 0;
	}
	puts("Choose output pile type (DIA: 1, HRT: 2, SPD:3, CLB: 4):");
	output_pile_index = ChooseOutputPile();
	waste_pile_card = GetWastePileCard();
	if (IsAddableOutputPileCard(waste_pile_card, output_pile_index)) {
		RemoveWastePileCard();
		AddOutputPileCard(output_pile_index);
		printf("Move a card from waste pile to output pile ");
		PrintShape(output_pile_index);
		putchar('.');
		return 1;
	}
	PrintCannotMove();
	return 0;
}
int OptionPileToPile(void) {
	int pile_from = 0, pile_to = 0;
	Group* from_group = NULL;

	puts("Choose pile from which cards removed (1 ~ 7):");
 	pile_from = ChoosePile(); /* 0~6 */
	puts("Choose pile to which cards added (1 ~ 7):");
	pile_to = ChoosePile(); /* 0~6 */
	if (pile_from == pile_to) {
		PrintCannotMove();
		return 0;
	}
	if (IsPileEmpty(pile_from)) {
		PrintNoCard();
		return 0;
	}
	from_group = GetPileTopGroup(pile_from);
	if (IsMergeablePileGroup(from_group, pile_to)) {
		if (IsPileEmpty(pile_to)) {
			AddPileGroup(from_group, pile_to);
			RemovePileGroup(pile_from);
		}
		else {
			MergePileGroup(from_group, pile_to);
			DestructGroup(RemovePileGroup(pile_from));
		}
		printf("Move cards from pile_%d to pile_%d.\n", pile_from + 1, pile_to + 1); /* 1~7 */
		return 1;
	}
	PrintCannotMove();
	return 0;
}
int OptionPileToOutputPile(void) {
	int pile_index = 0;
	int output_pile_index = 0;
	int pile_card = 0;
	puts("Choose pile number (1 ~ 7):");
	pile_index = ChoosePile(); /* 0~6 */
	puts("Choose output pile type (DIA: 1, HRT: 2, SPD:3, CLB: 4):");
	output_pile_index = ChooseOutputPile(); /* 0~3 */
	if (IsPileEmpty(pile_index)) {
		PrintNoCard();
		return 0;
	}
	pile_card = GetPileCard(pile_index);
	if (IsAddableOutputPileCard(pile_card, output_pile_index)) {
		AddOutputPileCard(output_pile_index);
		RemovePileCard(pile_index);
		printf("Move a card from pile_%d to output pile ", pile_index + 1); /* 1~7 */
		PrintShape(output_pile_index);
		putchar('.');
		return 1;
	}
	PrintCannotMove();
	return 0;
}
void ShowRules(void) {
	/*Victory Condition*/
	puts("Victory Condition:");
	puts("Move all cards from stock and 7 piles to output piles.");
	BreakLine(1);
	/*Stock and Waste pile*/
	puts("Stock and Waste pile:");
	puts("if stock has no cards, do option 2.");
	puts("Option 2 doesn't work unless stock is empty.");
	BreakLine(1);
	/*Piles*/
	puts("Piles:");
	puts("Cards can only be placed on other cards in increasing order (A, 2, 3, ..., 10, J, Q, K) and red(R) and black(B) alternatively.");
	puts("All revealed Cards in each piles move together as a group among piles.");
	puts("Only K can be moved to an empty pile.");
	puts("The topmost card(it is at the bottom when it is shown on the screen) of each piles can be moved to output piles.");
	BreakLine(1);
	/*Output piles*/
	puts("Output piles:");
	puts("Cards can be placed on an output pile if they have the same shape.");
	puts("Cards can only be placed on in increasing order (A, 2, 3, ..., 10, J, Q, K).");
	BreakLine(1);
	puts("Press enter to continue.");
	TakeABreak();
}