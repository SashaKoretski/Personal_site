//111_Корецкий_Александр_поиск_корня_методом_хорд
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include<stdlib.h>

#include "d_p.h"

#define Ep 0.0001 //эпсилон

double eq(double x) //уравнение
{
	return 5 * x * x * x + x * x - 6 * x + 3;
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