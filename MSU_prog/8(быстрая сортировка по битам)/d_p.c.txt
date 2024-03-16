//111_Корецкий_Александр_быстрая_сортировка_по_битам
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include<stdlib.h>
#include<time.h>

#include "d_p.h"

#define N 8000
#define eps 0,00001

void gen(int *arr, int sz) //генерация массива случайных чисел на отрезке [-1;1]
{
    int p;
	int i;
    for (i = 0; i < sz; i++)
    {
        p = rand();
        arr[i] = p;
    }
}

void sort(int *brr, int *arr, int a, int b) //сортировка массива
{
    int i, j, y, l;

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
				
				y = brr[i];
                brr[i] = brr[j];
                brr[j] = y;
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
        sort(brr, arr, i, b);
    }
    if (j > a) 
    {
        sort(brr, arr, a, j);
    }
}

void read (int *arr, int sz, FILE *fin) //чтение массива из файла
{
	int i;
	for (int i = 0; i < sz; i += 1)
	{
				fscanf(fin, "%d", &arr[i]);
	}
}

int check (int *arr, int sz) //проверка массива на отсортированность
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








