//111_Корецкий_Александр_интерполяция

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include<stdlib.h>

#include "d_p.h"

double summ (double *x) //сумма
{
	double S = 0;
	int i;
	
	for (i = 0; i < N; i += 1)
	{
		S += x[i];
	}
	return S;
}

double summ_xy (double *x, double *y) //сумма произведений
{
	double S = 0;
	int i;
	
	for (i = 0; i < N; i += 1)
	{
		S += x[i] * y[i];
	}
	return S;
}

double summ_sq (double *x) //сумма квадратов
{
	double S = 0;
	int i;
	
	for (i = 0; i < N; i += 1)
	{
		S += x[i] * x[i];
	}
	return S;
}

double A_uravn(double *x, double *y) //коэффициент А
{
	return (N * summ_xy(x, y) - (summ(x) * summ(y))) / (N * summ_sq(x) - summ(x) * summ(x));
}

double B_uravn(double *x, double *y) //коэффициент Б
{
	return (summ(y) - A_uravn(x, y) * summ(x)) / N;
}









