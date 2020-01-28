// series.c
#include <stdlib.h>
#include "solitaire.h"

int* ConstructSeries(int size);
void DestructSeries(int* series);
int* IncreaseSeriesSize(int* series, int size);
void MergeSeriesCard(int* series, int top, int card);
void MergeSeriesSeries(int* below_series, int* above_series, int below_top, int above_top);

int* ConstructSeries(int size) {
	int* series = (int*)malloc(sizeof(int) * size);
	return series;
}
void DestructSeries(int* series) { free(series); }
int* IncreaseSeriesSize(int* series, int size) {
	int* increased = (int*)realloc(series, sizeof(int) * size);
	return increased;
}
void MergeSeriesCard(int* series, int top, int card) {
	series[top] = card;
}
void MergeSeriesSeries(int* below_series, int* above_series, int below_top, int above_top) {
	for (int i = 0; i <= above_top; ++i)
		below_series[below_top + i + 1] = above_series[i];
}
