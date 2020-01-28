// play.c

#include <stdio.h>
#include "solitaire.h"

void Play(void);
int IsWin(void);

void Play(void) {
	int choice = 0;
	int win = 0, stop = 0;
	while (!win && !stop) {
		ClearScreen();
		ShowStatus(7);
		PrintSleep(1);
		choice = ShowOptions();
		if (choice == STOP_GAME)
			stop = 1;
		else {
			DoOption(choice);
			PrintSleep(5);
		}
		win = IsWin();
	}
	if (win) {
		ClearScreen();
		ShowStatus(7);
		puts("You Win.");
	}
	else if (stop)
		puts("Stop Game.");
	PrintSleep(5);
	TakeABreak();
}
int IsWin(void) {
	for (int shape = 0; shape < kNumberOfShape; shape++)
		if (!IsOutputPileFull(shape))
			return 0;
	return 1;
}
