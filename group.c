// group.c
#include <stdlib.h>
#include "solitaire.h"

Group* ConstructGroup(int size);
void DestructGroup(Group* group);
void MergeGroupGroup(Group* below, Group* above);
void DoubleGroupSize(Group* group);
int RemoveCardGroup(Group* group);
void MergeCardGroup(int card, Group* group);
int IsMergeableGroupCard(Group* group, int card);
int IsMergeableGroupGroup(Group* below, Group* above);
int GetGroupBottomCard(Group* group);
int GetGroupTopCard(Group* group);
int GetGroupSize(Group* group);
int GetGroupTop(Group* group);
int GetGroupNthCard(Group* group, int index);
int* GetGroupSeries(Group* group);
int IsGroupEmpty(Group* group);
int IsGroupFull(Group* group);

Group* ConstructGroup(int size) {
	Group* group = (Group*)malloc(sizeof(int)*2 + sizeof(int*));
	group->series = ConstructSeries(size);
	group->size = size;
	group->top = -1;
	return group;
}
void DestructGroup(Group* group) {
	DestructSeries(group->series);
	free(group);
}
void MergeGroupGroup(Group* below, Group* above) {
	int below_top = GetGroupTop(below);
	int above_top = GetGroupTop(above);

	while (GetGroupSize(below) < below_top + above_top + 2)
		DoubleGroupSize(below);
	MergeSeriesSeries(GetGroupSeries(below), GetGroupSeries(above), below_top, above_top);
	below->top = below_top + above_top + 1;
}
void DoubleGroupSize(Group* group) {
	int size = GetGroupSize(group);
	int* series = IncreaseSeriesSize(GetGroupSeries(group), size * 2);
	group->size = size * 2;
	group->series = series;
}
int RemoveCardGroup(Group* group) {
	int card = GetGroupTopCard(group);
	group->top--;
	return card;
}
void MergeCardGroup(int card, Group* group) {
	int* series = NULL;
	int top = group->top + 1;
	if (IsGroupFull(group))
		DoubleGroupSize(group);
	series = GetGroupSeries(group);
	MergeSeriesCard(series, top, card);
	group->top = top;
}
int IsMergeableGroupCard(Group* group, int card) {
	int below = GetGroupTopCard(group);
	if (IsAddableCardToCard(below, card))
		return 1;
	return 0;
}
int IsMergeableGroupGroup(Group* below, Group* above) {
	int below_card = GetGroupTopCard(below);
	int above_card = GetGroupBottomCard(above);
	if (IsAddableCardToCard(below_card, above_card))
		return 1;
	return 0;
}
int GetGroupBottomCard(Group* group) {
	return group->series[0];
}
int GetGroupTopCard(Group* group) {
	int top = group->top;
	return group->series[top];
}
int GetGroupSize(Group* group) { return group->size; }
int GetGroupTop(Group* group) { return group->top; }
int GetGroupNthCard(Group* group, int index) {
	int* series = group -> series;
	return series[index];
}
int* GetGroupSeries(Group* group) { return group->series; }
int IsGroupEmpty(Group* group) {
	if (group->top == -1)
		return 1;
	return 0;
}
int IsGroupFull(Group* group) {
	int top = group->top, size = group->size;
	if (top + 1 == size)
		return 1;
	return 0;
}
