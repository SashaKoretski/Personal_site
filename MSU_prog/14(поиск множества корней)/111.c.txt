//111_Корецкий_Александр_поиск_множества_корней

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#include "d_p.h"

#define Ep 0.0001 //эпсилон
#define Nn 10000

int main() {
	double A, B, As, Bs, Ch;
	int i;
	char myfilename[120];
	FILE*fin;
	
	printf("Vvedite imia logfaila: "); //находим логфайл
	scanf("%s", myfilename); 
	fin = fopen(myfilename, "w"); 
	if (!fin) { 
		printf("Ne udalod' naiti fail %s\n", myfilename);
		return -1;
	}
	fprintf(fin, "Xa	F(Xa)		Xb	F(Xb)	time	\n");
	
	printf("\n");
	printf("Vvedite pervuiu tochku: "); //узнаем точки
	scanf("%lf", &A); 
	printf("Vvedite vtoruiu tochku: ");
	scanf("%lf", &B); 
	
	As = A;
	Bs = A;
	Ch = (B - A) / Nn;
	
	for (i = 0; i < Nn; i += 1)
	{
		Bs += Ch;
		reshenie (As, Bs, fin);
		As = Bs;
	}
	return 0;
}
