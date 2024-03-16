//111_Корецкий_Александр_быстрая_сортировка
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include<stdlib.h>
#include<time.h>

#include "d_p.h"

#define N 8000
#define eps 0,00001

void gen(double *arr, int sz) //генерация массива случайных чисел на отрезке [-1;1]
{
    double p = 0.0;
	int i;
    for (i = 0; i < sz; i++)
    {
        p = ((-50 + rand() % 100));
        arr[i] = p / 50;
    }
}

void sort( double *arr, int *index, int a, int b) //сортировка массива
{
    int i, j;
    double y, l;

    i = a;
    j = b;

    l = arr[index[(a + (b - a) / 2)]];
    do
    {
        while (arr[index[i]] < l)
        {
            i+=1;
        }
        while (arr[index[j]] > l)
        {
            j-=1;
        }
        if (i <= j)
        {
            if (arr[index[i]] > arr[index[j]])
            {
                y = index[i];
                index[i] = index[j];
                index[j] = y;
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
        sort(arr, index, i, b);
    }
    if (j > a) 
    {
        sort(arr, index, a, j);
    }
}

void read (double *arr, int sz, FILE *fin) //чтение массива из файла
{
	int i;
	for (int i = 0; i < sz; i += 1)
	{
				fscanf(fin, "%d", &arr[i]);
	}
}

int check (double *arr, int sz) //проверка массива на отсортированность
{
	int i;
	for (i = 0; i < sz; i += 1)
	{
		if ((arr[i] - arr[i - 1]) < eps) 
		{	
			return 0;
		}
		else 
		{
			return 1;
			break;
		}
	}
}








