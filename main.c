#include "TM4C123.h"                    // Device header
#include "PLL.h"
void timerInit(void);
void delaySec(int delay);
int main()
{
	int count = 0;
initPLL(Bus_80MHz);	
timerInit();

	
SYSCTL->RCGCGPIO = 0x02;
while(!(SYSCTL->PRGPIO)){};

GPIOB->DIR = 0x41;
GPIOB->DEN = 0x41;
GPIOB->PUR = 0x41;
GPIOB->DATA = 0;
while(1){
	
delaySec(3);
GPIOB->DATA = 0x41;
delaySec(3);	
GPIOB->DATA = 0;
}

}

void timerInit(void){
	SysTick->CTRL = 0;
	SysTick->LOAD = 16000000;
	SysTick->CTRL = 5;
	
}

void delaySec(int delay){
	for(int i = 0; i<(5*delay); i++){//so do it 5 times and that should be 1 sec.
	while((SysTick->CTRL&0x10000)==0){}; //if really is 80MHz should time out in 0.2 seconds.
}
	
}