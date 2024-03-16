//111_Корецкий_Александр_быстрая_сортировка_по_битам

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include<stdlib.h>
#include<time.h>

#include "d_p.h"

#define N 8000
#define eps 0,00001

int main() {
	int arr[N];
	int brr[N];
	int dop[16];
	double time;
	int i, j, k, m, kol, ch, ch2;
	clock_t st, end; 
	char myfilename[120];
	FILE*fin;

	printf("Vvedite imia faila, gde vi hotite sgenerirovat' posledovatel'noct'-->"); //открываем файл
	scanf("%s", myfilename); 
	fin = fopen(myfilename, "w"); 
	
	if (!fin) { 
		printf("Ne udalod' naiti fail %s\n", myfilename); //проверяем, есть ли вообще такой файл
		return -1;
	}
	
	gen(arr, N); //генерация массива
	
	for (i = 0; i < N; i+=1) //запись массива в файл
    {
        fprintf (fin, "%d: ", arr[i]);
		j = 1;
		kol = 0;
		ch2 = arr[i];
		for (j; j < 17; j+=1)
		{
			ch = (int)ch2 % 2;
			ch2 = (ch2-ch) / 2;
			kol += ch;
			dop[j] = ch;
		}
		brr[i] = kol;
		m = 15;
		for (m; m > 0; m -= 1) fprintf (fin, "%d", dop[m]);
		fprintf (fin, ": %d\n", brr[i]);
    }
	
	st = clock();
	sort(arr, brr, 0, (N-1)); //сортировка массива
	end = clock();
	time = (double)(end - st) / CLOCKS_PER_SEC; //подсчет времени
	
	fprintf(fin, "\n");
	fprintf(fin, "\n");
    fprintf(fin, "Otsortirovannaia posledovatelnost'\n");
    fprintf(fin, "\n");
	fprintf(fin, " ");
	
	if (check(arr, N) == 1) //проверка на отсортированность
	{
		printf("OSHIBKA");
	}
	else
	{
		for (i = 0; i < N; i+=1) //запись массива в файл
    {
        fprintf (fin, "%d: ", arr[i]);
		j = 1;
		ch2 = arr[i];
		for (j; j < 17; j+=1)
		{
			ch = (int)ch2 % 2;
			ch2 = (ch2-ch) / 2;
			dop[j] = ch;
		}
		m = 15;
		for (m; m > 0; m -= 1) fprintf (fin, "%d", dop[m]);
		fprintf (fin, ": %d\n", brr[i]);
    }
	
		printf ("%lf", time); //вывод времени
	}
	return 0;
}
