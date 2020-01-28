// choose.c
#include <stdio.h>
#include "solitaire.h"

int ChooseNumber(int begin, int end);
int IsNumberBetween(int target, int begin, int end);
int ChoosePile(void);
int ChooseOutputPile(void);
int GetMax(int array[], int size);
int CharToInt(int ch);
void EmptyBuffer(void);

int ChooseNumber(int begin, int end) {
	int choice = 0;
	do {
		choice = CharToInt(getchar());
	} while(!IsNumberBetween(choice, begin, end));
	EmptyBuffer();
	return choice;
}
int IsNumberBetween(int target, int begin, int end) {
	if (target < begin)
		return 0;
	if (target > end)
		return 0;
	return 1;
}
int ChoosePile(void) {
	int index = 0;
	/* get pile number 1 ~ NUMBER_OF_PILES, set index 0 ~ (NUMBER_OF_PILES - 1) */
	index = ChooseNumber(1, NUMBER_OF_PILES) - 1;
	return index;
}
int ChooseOutputPile(void) {
	int index = 0;
	/* get output pile number 1 ~ kNumberOfShape, set index 0 ~ (kNumberOfShape - 1) */
	index = ChooseNumber(1, kNumberOfShape) - 1;
	return index;
}
int GetMax(int array[], int size) {
	int max = array[0];
	for (int i = 1; i < size; ++i)
		if (max < array[i])
			max = array[i];
	return max;
}
int CharToInt(int ch) {
	return ch - 48;
}
void EmptyBuffer(void) {
	while (getchar() != '\n');
}
