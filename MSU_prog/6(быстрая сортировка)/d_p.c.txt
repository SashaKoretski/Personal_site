//111_Корецкий_Александр_быстрая_сортировка

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include<stdlib.h>
#include <math.h>
#include "d_p.h"

void gen(double *arr, int sz)
{
    double p = 0.0;
	int i;
    for (i = 0; i < sz; i++)
    {
        p = ((-50 + rand() % 100));
        arr[i] = p / 50;
    }
}

void sort( double *arr, int a, int b)
{
    int i, j;
    double y, l;

    i = a;
    j = b;

    l = arr[(a + (b - a) / 2)];
    do
    {
        while (arr[i] < l)
        {
            i+=1;
        }
        while (arr[j] > l)
        {
            j-=1;
        }
        if (i <= j)
        {
            if (arr[i] > arr[j])
            {
                y = arr[i];
                arr[i] = arr[j];
                arr[j] = y;
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
        sort(arr, i, b);
    }
    if (j > a) 
    {
        sort(arr, a, j);
    }
}












