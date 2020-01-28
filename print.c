// print.c
#include "solitaire.h"
#include <stdio.h>
#include <windows.h>

/* print out numbers in two digit, for all printed numbers occupy the same space. ('10' has two letters.) */
void PrintTwoDigitCardNumber(int number);
void PrintTwoDigitNumber(int number);
void PrintShape(Shape);
void PrintColor(Color);
void PrintCannotMove(void);
void PrintNoCard(void);
void PrintSpace(int repetition);
void BreakLine(int repetition);
void PrintCardUpperLine(int card_width);
void PrintPileQuestionMark(int width);
void PrintSleep(int repetition);
void ClearScreen(void);
void TakeABreak(void);

void PrintTwoDigitCardNumber(int number) {
	if (number == 1)
		printf(" A");
	else if (number == 11)
		printf(" J");
	else if (number == 12)
		printf(" Q");
	else if (number == 13)
		printf(" K");
	else
		printf("%2d", number);
}
void PrintTwoDigitNumber(int number) {
	printf("%2d", number);
}
void PrintShape(Shape shape) {
	switch (shape) {
	case DIA:
		printf("DIA");
		break;
	case HRT:
		printf("HRT");
		break;
	case SPD:
		printf("SPD");
		break;
	case CLB:
		printf("CLB");
		break;
	}
}
void PrintColor(Color color) {
	switch (color) {
	case R:
		printf("R");
		break;
	case B:
		printf("B");
		break;
	}
}
void PrintCannotMove() {
	puts("Cannot Move.");
}
void PrintNoCard() {
	puts("No Card.");
}
void PrintSpace(int repetition) {
	for (int i = 0; i < repetition; ++i)
		putchar(' ');
}
void BreakLine(int repetition) {
	for (int i = 0; i < repetition; ++i)
		putchar('\n');
}
void PrintCardUpperLine(int card_width) {
	for (int i = 0; i < card_width; i++)
		putchar('-');
}
void PrintPileQuestionMark(int width) {
	int half_width = width / 2;
	PrintSpace(width - half_width - 1);
	putchar('?');
	PrintSpace(half_width);
}
void PrintSleep(int repetition) {
	for (int i = 0; i < repetition; ++i)
		Sleep(200);
}
void ClearScreen(void) {
	system("cls");
}
void TakeABreak(void) { getchar(); }
