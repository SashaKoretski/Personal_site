//111_Корецкий_Александр_поиск_интеграла
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#include "d_p.h"

#define Ep 0.0001 //эпсилон

double eq(double x) //уравнение
{
	return sin(x);
	//return sin(6 * x) - 0.5 * cos(x);
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

double integ(double A, double B, int Nn, FILE *fin) //интеграл
{
	int mist = 0;
	double C, I, Aa, Bb;
	double time = 0;
	clock_t st, end;
	
	Aa = A;
	Bb = B;
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
			C = hord(A, B);
			st = clock();
			fprintf(fin, "%.4lf	", A);
			fprintf(fin, "%.4lf	", eq(A));
			fprintf(fin, "%.4lf	", B);
			fprintf(fin, "%.4lf ", eq(B));
			fprintf(fin, "%.4lf\n", time);
			
			if (raw(eq(C), 0) == 1)
			{
				I = (1 / 2) * (eq(Aa) * (C - Aa) + eq(Bb) * (Bb - C));
				fprintf(fin, "\n");
				fprintf(fin, "\n");
				break;
			}
			else if (eq(A) * eq(C) < 0) B = C;
			else A = C;
			end = clock();
			time += (double)(end - st) / CLOCKS_PER_SEC; //подсчет времени
		}
	} 
	else
	{
		I = (eq(Aa) + eq(Bb)) * (Bb - Aa) / 2;
	}
	return I;
}