//111_Корецкий_Александр_поиск_множества_корней
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#include "d_p.h"

#define Ep 0.0001 //эпсилон

double eq(double x) //уравнение
{
	return sin(6 * x) - 0.5 * cos(x);
}

double hord(double A, double B) //точка пересечения хорды с ОХ
{
	return (A * eq(B) - B * eq(A)) / (eq(B) - eq(A)); 
}

double modu(double A) //модуль
{
	if (A > 0) return A;
	else return -A;
}

int raw(double A, double B) //равенство
{
	double Ee = Ep;
	if ((modu(B - A)) < Ee)
	{
		return 1;
	}
	else return 0;
}

void reshenie(double A, double B, FILE *fin) //поиск решения
{
	int mist = 0;
	double C;
	double time = 0;
	clock_t st, end;
	if (eq(A) * eq(B) > 0) //проверка
	{
		mist = 1;
	} 
	else if (A > B)
	{
		mist = 2;
	}
	
	if (mist == 0) 
	{
		while (1) //нахождение хорд
		{
			st = clock();
			fprintf(fin, "%.4lf	", A);
			fprintf(fin, "%.4lf	", eq(A));
			fprintf(fin, "%.4lf	", B);
			fprintf(fin, "%.4lf ", eq(B));
			fprintf(fin, "%.4lf\n", time);
			
			C = hord(A, B);
			
			if (raw(eq(C), 0) == 1)
			{
				fprintf(fin, "\n");
				printf ("%.4lf ", C);
				break;
			}
			else if (eq(A) * eq(C) < 0) B = C;
			else A = C;
			end = clock();
			time += (double)(end - st) / CLOCKS_PER_SEC; //подсчет времени
		}
	}
}