//111_Корецкий_Александр_итог

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include<stdlib.h>
#include <math.h>

#include "d_p.h"

#define Ep 0.0001 //эпсилон
#define Nnn 1000 
FILE*fin;
double alfa;

int main() {
	double A, B, C;
	int mist;
	char myfilename[120];
	
	
	printf("Vvedite imia logfaila: "); //находим логфайл
	scanf("%s", myfilename); 
	fin = fopen(myfilename, "w"); 
	if (!fin) { 
		printf("Ne udalod' naiti fail %s\n", myfilename);
		return -1;
	}

	printf("Vvedite levyy konets otrezka:");
	scanf("%lf", &A);
	printf("Vvedite pravyy konets otrezka:");
	scanf("%lf", &B);
	
	printf("Vvedite alfa:");
	scanf("%lf", &alfa);
	
	C = reshenie(A, B, &mist, fff);
	
	if (mist == 1) //вывод ошибки
	{
		printf ("!!OSHIBKA!! Koordinati koncov otreska odnogo snaka");
	}
	else
	{
		printf ("Reshenie-->%lf", C);
	}
	return 0;
}
