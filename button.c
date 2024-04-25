#include "button.h"
struct Button button;
void setup_input()
{
	button.nutOne=0;
	button.cntOne=0;
	GPIOA->ODR |= (1<<0); // pull - up
	
}
int readInput(int bit)
{
	if((GPIOA->IDR&(bit<<0))==0)
		return 0;
	else
		return 1;
}
void function_button(void)
{
	button.nutOne=readInput(0);
	if(!button.nutOne)
	{
		button.one=true;
		return;
	}
	if(button.one)
	{
		button.cntOne+=1;
		button.one=false;
	}
}
