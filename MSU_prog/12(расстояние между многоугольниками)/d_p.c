//111_Корецкий_Александр_расстояние_между_многоугольниками
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#include "d_p.h"

#define N 2000 //количество точек
#define M 1000 //количество рандомных чисел, чтобы сгенерировать одно нормальное

double dist (double x1, double y1, double x2, double y2) //расстояние между двумя точками
{
	return sqrt(pow ((x1 - x2), 2) + pow ((y1 - y2), 2));
}

int vip (double *xarr, double *yarr, double *xvip, double *yvip, int min, int sz) //количество точек в выпуклой оболочке
{
	int st1, h, m;
	st1 = 0;
	h = min;
	m = 0;
	
	if (st1 == min) st1 = 1;
	
	while (st1 != min) {
		m += 1;
		st1 = where(xarr, yarr, xvip, yvip, m, h, sz);
		h = st1;
	}
	
	return m;
}

int where (double *xarr, double *yarr, double *xvip, double *yvip, int m, int h, int sz) //смотрит, где находится точка, записывает в массив с выпуклой оболочкой
{
	int  st2, i;
	double gg;
	
	st2 = 0;
	
	for (i = 0; i < N; i += 1) {
		gg = (xarr[st2] - xarr[h]) * (yarr[i] - yarr[h]) - (xarr[i] - xarr[h]) * (yarr[st2] - yarr[h]);
		if (gg > 0)
			st2 = i;
	}
	
	xvip[m] = xarr[st2];
	yvip[m] = yarr[st2];
	
	return st2;
}

double min_dist (double *xvip1, double *yvip1, double *xvip2, double *yvip2, double *end, int sz1, int sz2) //находит минимальное расстояние между двумя множествами точек
{
	int i, j;
	double minD;
	minD = 10000.0;
	for (i = 0; i < sz1; i += 1)
	{
		for (j = 0; j < sz2; j += 1)
		{
			if (dist(xvip1[i], yvip1[i], xvip2[j], yvip2[j]) < minD)
			{
				minD = dist(xvip1[i], yvip1[i], xvip2[j], yvip2[j]);
				end[0] = xvip1[i];
				end[1] = yvip1[i]; 
				end[2] = xvip2[j];
				end[3] = yvip2[j];
			}
		}
	}
	return minD;
}




