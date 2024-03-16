//111_Корецкий_Александр_сортировка_пузырьком

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

void sort(double *arr, int sz) { 

	int i, j;
	double b;
	
	for (i = 0; i < sz; i+=1) {
		for (j = 0; j < (sz - 1); j+=1) {
			if (arr[j] > arr[j + 1]) {
				b = arr[j]; 
				arr[j] = arr[j + 1]; 
				arr[j + 1] = b; 
			}
		}
	}
}












