//111_Корецкий_Александр_экспонента

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include<stdlib.h>
#include<time.h>

#include "d_p.h"

#define Ep 0.0001 //эпсилон


int main() {
	double A;
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
	printf("Vvedite chislo: "); //узнаем точки
	scanf("%lf", &A); 
	
	printf("%lf", expa(A, fin)); //находим экспоненту
	return 0;
}
