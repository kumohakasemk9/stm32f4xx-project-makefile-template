#include <stm32f4xx.h>
#include <string.h>

void delay(unsigned long);
void debug(char*);

void main() {
	RCC->AHB1ENR = 0xffffffff;
	RCC->APB1ENR = 0xffffffff;
	RCC->APB2ENR = 0xffffffff;
	GPIOA->MODER |= 0x280000;
	GPIOA->AFR[1] = 0x770;
	USART1->BRR = 104 << 4;
	USART1->CR1 = (1 << 13) + 0xc;
	TIM2->CR1 = 0x1;
	TIM2->DIER = 0x1;
	TIM2->ARR = 8000000;
	TIM5->CR1 = 0x1;
	TIM5->DIER = 0x1;
	TIM5->ARR = 16000000;
	NVIC_EnableIRQ(TIM2_IRQn);
	NVIC_EnableIRQ(TIM5_IRQn);
	GPIOB->MODER = 0x55000000;
	char buffer[32];
	int pos = 0;
	debug(">");
	while(1) {
		if((USART1->SR & (1 << 5)) != 0) {
			char r = USART1->DR;
			if(r == '\r') {
				buffer[pos] = '\0';
				pos = 0;
				if(strcmp("start",buffer) == 0) {
					TIM2->CR1 = 1;
					debug("Timer1 started.\r\n");
				} else if(strcmp("stop",buffer) == 0) {
					TIM2->CR1 = 0;
					debug("Timer1 stopped.\r\n");
				} else {
					debug("Command not registered.\r\n");
				}
				debug("> ");
			} else {
				buffer[pos] = r;
				pos++;
				if(pos > 30) {
					buffer[pos] = '\0';
					debug("Overflow: Buffer cleared.\r\n");
					pos = 0;
				}
			}
		}
	}
}

void debug(char *d) {
	while(*d) {
		USART1->DR = *d;
		while((USART1->SR & (1 << 6)) == 0);
		USART1->SR &= ~(1 << 6);
		d++;
	}
}

void delay(unsigned long a) {
	for(unsigned long i = 0; i < a;i++);
}

void TIM2_Handler() {
	TIM2->SR &= ~0x1;
	if((GPIOB->ODR & 0x8000) == 0) {
		GPIOB->BSRRL = 0x8000;
	} else {
		GPIOB->BSRRH = 0x8000;
	}
}
void TIM5_Handler() {
	TIM5->SR &= ~0x1;
	if((GPIOB->ODR & 0x4000) == 0) {
		GPIOB->BSRRL = 0x4000;
	} else {
		GPIOB->BSRRH = 0x4000;
	}
}