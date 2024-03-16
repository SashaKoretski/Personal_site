//111_Корецкий_Александр_сортировка_индексов
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include<stdlib.h>
#include<time.h>

#include "d_p.h"

#define N 16000
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

void sort(double *arr, int *index, int sz) //сортировка
{

	double y;
	int i, j;

	for (i = 0; i < sz; i++) 
	{
		for (j = 0; j < sz - 1; j++) 
		{
			if (arr[index[j]] > arr[index[j+1]]) 
			{
				y = index[j];
				index[j] = index[j+1];
				index[j+1] = y;
			}
		}
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








