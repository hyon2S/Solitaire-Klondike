// solitaire.h

#define TOTAL_NUMBER_OF_CARD 52
#define NUMBER_OF_PILES 7

extern const int kMaxCardNumber;
extern const int kNumberOfColor;
extern const int kNumberOfShape;

typedef struct { int size; int top; int* series; } Group;
typedef enum { DIA, HRT, SPD, CLB} Shape;
typedef enum { R, B } Color;
typedef enum { STOCK_TO_WASTE_PILE = 1, WASTE_PILE_TO_STOCK, WASTE_PILE_TO_PILE, WATSTE_PILE_TO_OUTPUT_PILE, PILE_TO_PILE, PILE_TO_OUTPUT_PILE, SHOW_RULES, STOP_GAME } Option;

extern int pile_top[NUMBER_OF_PILES];
extern Group* piles[NUMBER_OF_PILES][NUMBER_OF_PILES]; /* piles[pile number][height] */

extern int stock[TOTAL_NUMBER_OF_CARD];
/* index of the top of the waste pile. */
extern int front;
/* index of the first card of stock and waste pile. It marks the boundary of alive(?) cards and dead(?) cards which move out to somewhere during play. */
extern int rear;
/* each of the four int means the topmost card number in each outputpile. 0 means empty, 13 means full. */
extern int output_pile[4];

// card.c
int GetCardNumber(int card);
Shape GetCardShape(int card);
Color GetCardColor(int card);
int GetCard(int number, Shape shape);
int IsAddableCardToCard(int below, int above);

// choose.c
int ChooseNumber(int begin, int end);
int IsNumberBetween(int target, int begin, int end);
int ChoosePile(void);
int ChooseOutputPile(void);
int GetMax(int array[], int size);
int CharToInt(int ch);
void EmptyBuffer(void);

// end.c
void End(void);

//group.c
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

// output_pile.c
int GetOutputPileCard(Shape);
void AddOutputPileCard(Shape shape);
int RemoveOutputPileCard(Shape);
int IsAddableOutputPileCard(int card, Shape shape);
int IsOutputPileEmpty(Shape shape);
int IsOutputPileFull(Shape shape);

// pile.c
void AddPileCard(int card, int pile);
int GetPileCard(int pile);
int RemovePileCard(int pile);
void MergePileGroup(Group* above, int pile);
void AddPileGroup(Group* group, int pile);
Group* RemovePileGroup(int pile);
int IsAddablePileCard(int card, int pile);
int IsMergeablePileGroup(Group* group, int pile);
int IsPileEmpty(int pile);
Group* GetPileTopGroup(int pile);
Group* GetPileNthGroup(int pile, int index);

// play.c
void Play(void);
int IsWin(void);

// playing_option.c
int ShowOptions(void);
void DoOption(int choice);
int OptionStockToWastePile(void);
int OptionWastePileToStock(void);
int OptionWastePileToPile(void);
int OptionWastePileToOutputPile(void);
int OptionPileToPile(void);
int OptionPileToOutputPile(void);
void ShowRules(void);

// print.c
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

// print_piles.c
void PrintPiles(int space_1, int space_2, int pile_card_width);
int GetPileNumberOfUnknownCards(int pile);
int GetPileNumberOfCards(int pile);
int PrintPileTopGroupNthCard(int pile, int index);

// series.c
int* ConstructSeries(int size);
void DestructSeries(int* series);
int* IncreaseSeriesSize(int* series, int size);
void MergeSeriesCard(int* series, int top, int card);
void MergeSeriesSeries(int* below_series, int* above_series, int below_top, int above_top);

// show_status.c
void ShowStatus(int card_width);
void PrintStockOutputPileTitle(int space_1, int space_2, int space_3);
void PrintStockNumberOutputPileShape(int space_1, int space_2, int space_3, int space_4);
void PrintStockOutputPileCard(int space_1, int space_2, int space_3, int space_4, int card_width);
void PrintStockOutputPileCardEdge(int space_1, int space_2, int space_3, int space_4, int card_width);
void PrintstockCardEmpty(int space_1, int space_2, int card_width);
void PrintstockCardFilledNumber(int space_1, int space_2, int card_width);
void PrintstockCardFilledShape(int space_1, int space_2, int card_width);
void PrintOutputPileCardEmpty(int space_3, int space_4, int card_width);
void PrintOutputPileCardFilled(int space_3, int space_4);
void PrintPileTitle(int space_1, int space_2);

// start.c
void SetCards(void);
void InitPool(int pool[], int size);
void RandomPick(int pool[], int size);
int SetPile(int size);
void SetStockIndex(int size);

// stock_waste_pile.c
int GetNumberOfCardStock(void);
int GetNumberOfCardWastePile(void);
int GetWastePileCard(void);
int IsStockEmpty(void);
int IsWastePileEmpty(void);
void StockToWastePile(void);
void UndoOpenStockCard(void);
int RemoveWastePileCard(void);
void AddWastePileCard(int card);
void WastePileToStock(void);
