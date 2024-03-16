//111_Корецкий_Александр_поиск_минимума
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include<stdlib.h>
#include<time.h>

#include "d_p.h"

#define Ep 0.0001 //эпсилон
#define N 10

double eq(double x) //уравнение
{
	return x * x * x * x - x * x * x - 3 * x * x + 6 * x - 9;
}

double parmin(double A, double B, double C) //минимум параболы
{
	double aa, bb;
	aa = (eq(C) - (C * (eq(B) - eq(A)) + B * eq(A)) / (B - A)) / (C * (C - A - B) + A * B);
	bb = (eq(B) - eq(A)) / (B - A) - aa * (A + B);
	return (- bb) / (2 * aa); 
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

double MINF(double A, double B, FILE *fin) //минимум функции
{
	double As, Bs, Cs, Rr;
	double time = 0;
	clock_t st, end;
	
	Rr = (B - A) / N;
	As = A;
	Bs = As + Rr;
	while (1)
	{
		st = clock();
		fprintf(fin, "%.4lf	", As);
		fprintf(fin, "%.4lf	", eq(As));
		fprintf(fin, "%.4lf	", Bs);
		fprintf(fin, "%.4lf ", eq(Bs));
		fprintf(fin, "%.4lf\n", time);
			
		if (raw(Rr, Ep) == 1)
		{
			break;
		} else if (eq(Bs) < eq(As))
		{
			As += Rr;
			Bs += Rr;
		} else if (eq(Bs) > eq(As))
		{
			As -= Rr;
			Rr /= 3;
			Bs = As + Rr;
		}
		end = clock();
		time += (double)(end - st) / CLOCKS_PER_SEC; //подсчет времени
	}
	return As;
}