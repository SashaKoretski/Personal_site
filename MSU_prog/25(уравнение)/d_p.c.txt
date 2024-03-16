//111_Корецкий_Александр_итог
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include<stdlib.h>
#include <math.h>

#include "d_p.h"

#define Ep 0.0001 //эпсилон
#define Nnn 1000 

double f(double x) //уравнение
{
	return pow(x, 3) + x;
}

double fff(double x) //уравнение
{
	return integ(0, x, f) - 5 * sqrt(x) - alfa;
}

double hord(double A, double B, double (*eq)(double)) //точка пересечения хорды с ОХ
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

double integ(double A, double B, double (*f)(double))

{
	double n, G, H, D;
	G = 0;
	n = 1;
	D = B - A;
	G = G + ((f(A) + f(A + D)) * D / 2);
	while (modu(G - H) >= Ep)
	{
		H = G;
		n = n * 2;
		G = 0.0;
		D = (B - A) / n;
		for (int i = 0; i < n; i++)
		{
			G = G + ((f(A + D * i) + f(A + D * (i + 1))) * D / 2);
		}
	}
	if (modu(G - H) < Ep)
	{
		return(G);
	}
}

double reshenie (double A, double B, int *mist, double (*f)(double))
{
	double C;
	*mist = 0;
	
	if (f(A) * f(B) > 0) //проверка
	{
		*mist = 1;
	}
	
	while (1) //нахождение хорд
		{
			fprintf(fin, "%.4lf	", A);
			fprintf(fin, "%.4lf	", f(A));
			fprintf(fin, "%.4lf	", B);
			fprintf(fin, "%.4lf\n", f(B));
			
			C = hord(A, B, f);
			
			if (raw(f(C), 0) == 1)
			{
				break;
			}
			else if (f(A) * f(C) < 0) B = C;
			else A = C;
		}
	return C;
}