//111_Корецкий_Александр_интерполяция

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include<stdlib.h>

#include "d_p.h"

void sort(double *arrX, double *arrY, int a, int b) //сортировка точек по иксам
{
    int i, j;
    double y, l;

    i = a;
    j = b;

    l = arrX[(a + (b - a) / 2)];
    do
    {
        while (arrX[i] < l)
        {
            i+=1;
        }
        while (arrX[j] > l)
        {
            j-=1;
        }
        if (i <= j)
        {
            if (arrX[i] > arrX[j])
            {
                y = arrX[i];
                arrX[i] = arrX[j];
                arrX[j] = y;
				
				y = arrY[i];
                arrY[i] = arrY[j];
                arrY[j] = y;
            }
            i+=1;
            if (j > 0)
            {
                j-=1;
            }
        }
    }
    while (i <= j);

    if (i < b) 
    {
        sort(arrX, arrY, i, b);
    }
    if (j > a) 
    {
        sort(arrX, arrY, a, j);
    }
}

double new_y (double x1, double y1, double x2, double y2, double newx) //прямая по двум точкам 
{
	return (newx - x1) * (y2 - y1) / (x2 - x1) + y1;
}










