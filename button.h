#include "stm32f10x.h"                  // Device header
#include <stdbool.h>

void setup_input();
int readInput(int bit);
void function_button(void);
typedef struct Button{
	int nutOne;
	int cntOne;
	bool one;
};
extern struct Button button;