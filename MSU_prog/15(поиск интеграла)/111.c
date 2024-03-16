//111_Корецкий_Александр_поиск_множества_корней

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include<stdlib.h>
#include<math.h>

#include "d_p.h"

#define Ep 0.0001 //эпсилон
#define Nnn 1000

int main() {
	double A, B, As, Bs, Ch, In1, In2;
	int i, Nn;
	
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
	
	Nn = Nnn;
	
	In1 = 0;
	As = A;
	Bs = A;
	Ch = (B - A) / Nn;
	
	for (i = 0; i < Nn; i += 1)
	{
		Bs += Ch;
		In1 += integ(As, Bs, Nn, fin);
		As = Bs;
	}
	
	Nn *= 2;
	
	while(1)
	{
		In2 = 0;
		As = A;
		Bs = A;
		Ch = (B - A) / Nn;
		
		for (i = 0; i < Nn; i += 1)
		{
			Bs += Ch;
			In2 += integ(As, Bs, Nn, fin);
			As = Bs;
		}
		
		if (raw(In1, In2) == 1)
		{
			break;
		}
		else 
		{
			Nn *= 2;
			In1 = In2;
		}
	}
	
	printf("%lf", In1);
	return 0;
}
