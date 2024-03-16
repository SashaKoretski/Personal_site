//111_Корецкий_Александр_экспонента
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include<stdlib.h>
#include<time.h>

#include "d_p.h"

#define Ep 0.0001 //эпсилон


int faktor(int A) //факториал
{
	int i = 1;
	int B = 1;
	for (i; i <= A; i += 1)
	{
		B *= i;
	}
	return B;
}

double step(double X, int n) //возведение в степень
{
	int i = 0;
	double Y = 1;
	for (i; i < n; i += 1)
	{
		Y *= X;
	}
	return Y;
}

double slog(double Ch, int St) //слогаемое
{
	return (step(Ch, St)) / (faktor(St));
}

double expa(double A, FILE *fin) //экспонента 
{
	int i = 0;
	double Ex = 0;
	double time = 0;
	clock_t st, end;
	for (i; i > -1; i += 1)
	{
		st = clock();
		fprintf(fin, "%.4lf ", Ex);
		fprintf(fin, "%.4lf\n", time);
		if (slog(A, i) < Ep) break;
		else Ex += slog(A, i);
		end = clock();
		time += (double)(end - st) / CLOCKS_PER_SEC; //подсчет времени
	}
	return Ex;
}