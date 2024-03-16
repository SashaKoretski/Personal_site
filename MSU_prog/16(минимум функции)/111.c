//111_Корецкий_Александр_поиск_минимума

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include<stdlib.h>
#include<time.h>

#include "d_p.h"

#define Ep 0.0001 //эпсилон
#define N 10

int main() {
	double A, B;
	char myfilename[120];
	FILE*fin;
	
	printf("Vvedite imia logfaila: "); //находим логфайл
	scanf("%s", myfilename); 
	fin = fopen(myfilename, "w"); 
	if (!fin) { 
		printf("Ne udalod' naiti fail %s\n", myfilename);
		return -1;
	}
	
	printf("\n");
	printf("Vvedite pervuiu tochku: "); //узнаем точки
	scanf("%lf", &A); 
	printf("Vvedite vtoruiu tochku: ");
	scanf("%lf", &B); 
	
	printf("%lf", MINF(A, B, fin)); //находим минимум
	return 0;
}
