#include "stm32f10x.h"                  // Device header

void primjer1();
void primjer2();
void primjer3();
void primjer4();
void primjer5();
void primjer6();
void primjer7();
void primjer8();

int main() {
	
	RCC ->APB2ENR |= (1 << 2);
	GPIOA ->CRL |= GPIO_CRL_MODE;
	GPIOA -> CRL &=~ GPIO_CRL_CNF;
	
	while(1) {
		primjer1();
		primjer2();
		primjer3();
		primjer4();
		primjer5();
		primjer6();
	}
	
}

///////////////////////////////
void primjer1() {
	for(int i = 0; i <= 7;i++){
		for(int j = 0; j < 50000; j++);
		GPIOA -> ODR |= (1 << i);
		
	}
	for(int i = 7; i >= 0;i--){
		for(int j = 0; j < 50000; j++);
		GPIOA -> ODR &=~ (1 << i);
		
	}
}
////////////////////////////////
void primjer2() {
	int k = -1;
	for(int i = 0; i <= 7;i++) {
		for(int j = 0; j < 50000; j++);
		GPIOA -> ODR |= (1 << i);
		for(int j = 0; j < 50000; j++);
		GPIOA -> ODR &=~ (1 << k);
		k++;
	}
	
	GPIOA -> ODR &=~ (1 << 7);
	k = 8;
	for(int i = 7; i >= 0;i--) {
		for(int j = 0; j < 50000; j++);
		GPIOA -> ODR |= (1 << i);
		for(int j = 0; j < 50000; j++);
		GPIOA -> ODR &=~ (1 << k);
		k--;
	}
}
/////////////////////////////////
void primjer3() {
	for(int i = 0; i <=7; i+=2 ) {
		GPIOA -> ODR |= (1 << i);
		for(int j = 0; j < 50000; j++);
	}
	for(int i = 0; i <= 7;i++){
		GPIOA -> ODR &=~ (1 << i);
	}
	for(int i = 1; i <=7; i+=2 ) {
		GPIOA -> ODR |= (1 << i);
		for(int j = 0; j < 50000; j++);
	}
	for(int i = 0; i <= 7;i++){
		GPIOA -> ODR &=~ (1 << i);
	}
}
/////////////////////////////////
void primjer4() {
	
	for(int i = 0; i <= 7;i++){
		for(int j = 0; j < 50000; j++);
		GPIOA -> ODR |= (1 << i);
	}
	
	for(int j = 0; j < 50000; j++);
	
	for(int i = 0; i <= 7;i++){
		GPIOA -> ODR &=~ (1 << i);
	}
	
	for(int i = 7; i >= 0;i--){
		for(int j = 0; j < 50000; j++);
		GPIOA -> ODR |= (1 << i);
	}
	
	for(int j = 0; j < 50000; j++);
	
		for(int i = 0; i <= 7;i++){
		GPIOA -> ODR &=~ (1 << i);
	}
		
}
/////////////////////////////////
void primjer5() {
	int j=3,k=4;
	
	for(int i = 0; i <= 3;i++) {
		if(j >= 0) {
			GPIOA -> ODR |= (1 <<j);
		}
		j--;
		if(k <= 7)
		GPIOA -> ODR |= (1 <<k);
		k++;
	
	for(int j = 0; j < 50000; j++);
	}
	//////////////////////
	for(int l = 0; l <= 7;l++){
		GPIOA -> ODR &=~ (1 << l);
	}
	
	k=0,j=7;
	for(int i = 0; i <= 3;i++) {
		if(j >= 4) {
			GPIOA -> ODR |= (1 <<j);
		}
		j--;
		if(k <= 7) {
			GPIOA -> ODR |= (1 <<k);
		k++;
		}
	for(int j = 0; j < 50000; j++);
	}
	for(int l = 0; l <= 7;l++){
		GPIOA -> ODR &=~ (1 << l);
	}
	
	
}

void primjer6() {
	int j = 7;
	for(int i = 0; i < 5;i++) {
		GPIOA -> ODR |= (1 << i);
		GPIOA -> ODR |= (1 << j);
		
		
		GPIOA -> ODR &=~ (1 << (i-1));
		GPIOA -> ODR &=~ (1 << (j+1));
		
		j--;
		
		for(int j = 0; j < 50000; j++);
	}
	
	int m = 3,n=4,l=1;
	for(int i = 0; i < 5;i++) {
		GPIOA -> ODR |= (1 << m);
		GPIOA -> ODR |= (1 << n);
		
		
		if(l < 1){
			GPIOA -> ODR &=~ (1 << (m+1));
			GPIOA -> ODR &=~ (1 << (n-1));
		}
		l--;
		m--;
		n++;
		
		for(int j = 0; j < 50000; j++);
	}
}