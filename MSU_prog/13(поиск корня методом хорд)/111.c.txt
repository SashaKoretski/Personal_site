//111_Корецкий_Александр_поиск_корня_методом_хорд

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include<stdlib.h>

#include "d_p.h"

#define Ep 0.0001 //эпсилон
#define odin -2.0000 //точки
#define dwa -1.0000

int main() {
	double A, B, C;
	int mist = 0;
	char myfilename[120];
	FILE*fin;
	
	printf("Vvedite imia logfaila: "); //находим логфайл
	scanf("%s", myfilename); 
	fin = fopen(myfilename, "w"); 
	if (!fin) { 
		printf("Ne udalod' naiti fail %s\n", myfilename);
		return -1;
	}

	A = odin;
	B = dwa;

	if (eq(A) * eq(B) > 0) //проверка
	{
		mist = 1;
	}
	
	if (mist == 0) 
	{
		while (1) //нахождение хорд
		{
			fprintf(fin, "%.4lf	", A);
			fprintf(fin, "%.4lf	", eq(A));
			fprintf(fin, "%.4lf	", B);
			fprintf(fin, "%.4lf\n", eq(B));
			
			C = hord(A, B);
			
			if (raw(eq(C), 0) == 1)
			{
				printf ("%.4lf ", C);
				break;
			}
			else if (eq(A) * eq(C) < 0) B = C;
			else A = C;
		}
	}
	else if (mist == 1) //вывод ошибки
	{
		printf ("!!OSHIBKA!! Koordinati koncov otreska odnogo snaka");
	}
	return 0;
}
