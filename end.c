// end.c
#include <stdlib.h>
#include "solitaire.h"

void End(void);

void End(void) {
	Group* group = NULL;
	for (int i = 0; i < NUMBER_OF_PILES; ++i) {
		while (!IsPileEmpty(i)) {
			group = RemovePileGroup(i);
			DestructGroup(group);
		}
	}
}
