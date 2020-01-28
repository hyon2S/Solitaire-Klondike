// pile.c
#include <stdlib.h>
#include "solitaire.h"

int pile_top[NUMBER_OF_PILES] = { -1, -1, -1, -1, -1, -1, -1 };
Group* piles[NUMBER_OF_PILES][NUMBER_OF_PILES] = { 0 }; /* piles[pile number][height] */

void AddPileCard(int card, int pile);
int GetPileCard(int pile);
int RemovePileCard(int pile);
/* Merge groups. the number of groups in pile doesn't increase. */
void MergePileGroup(Group* above, int pile);
/* Add a group onto the top group of the pile. the number of groups in pile increases. */
void AddPileGroup(Group* group, int pile);
Group* RemovePileGroup(int pile);
int IsAddablePileCard(int card, int pile);
int IsMergeablePileGroup(Group* group, int pile);
int IsPileEmpty(int pile);
Group* GetPileTopGroup(int pile);
Group* GetPileNthGroup(int pile, int index);

void AddPileCard(int card, int pile) {
	Group* top = NULL;
	if (IsPileEmpty(pile)) {
		top = ConstructGroup(1);
		AddPileGroup(top, pile);
	}
	else
		top = GetPileTopGroup(pile);
	MergeCardGroup(card, top);
}
int GetPileCard(int pile) {
	Group* top_group = GetPileTopGroup(pile);
	int card = GetGroupTopCard(top_group);
	return card;
}
int RemovePileCard(int pile) {
	Group* top = GetPileTopGroup(pile);
	int card = RemoveCardGroup(top);
	if (IsGroupEmpty(top)) {
		DestructGroup(top);
		pile_top[pile]--;
	}
	return card;
}
void MergePileGroup(Group* above, int pile) {
	Group* below = GetPileTopGroup(pile);
	MergeGroupGroup(below, above);
}
void AddPileGroup(Group* group, int pile) {
	int top;
	pile_top[pile]++;
	top = pile_top[pile];
	piles[pile][top] = group;
}
Group* RemovePileGroup(int pile) {
	Group* group = GetPileTopGroup(pile);
	pile_top[pile]--;
	return group;
}
int IsAddablePileCard(int card, int pile) {
	Group* group = NULL;
	if (IsPileEmpty(pile))
		if (GetCardNumber(card) == 13)
			return 1;
		else
			return 0;

	group = GetPileTopGroup(pile);
	if (IsMergeableGroupCard(group, card))
		return 1;
	return 0;
}
int IsMergeablePileGroup(Group* group, int pile) {
	int bottom = 0;
	if (IsPileEmpty(pile)) {
		bottom = GetGroupBottomCard(group);
		if (GetCardNumber(bottom) == 13)
			return 1;
		else
			return 0;
	}
	if (IsMergeableGroupGroup(GetPileTopGroup(pile), group))
		return 1;
	return 0;
}
int IsPileEmpty(int pile) {
	if (pile_top[pile] == -1)
		return 1;
	return 0;
}
Group* GetPileTopGroup(int pile) {
	int top = pile_top[pile];
	return piles[pile][top];
}
Group* GetPileNthGroup(int pile, int index) {
	return piles[pile][index];
}
