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

int main() {
	int i, j, min1, min2, vsz1, vsz2;
	double h, p, k, w, minA, minB, minfin;
	char myfilename1[120];
	FILE*fin1;
	char myfilename2[120];
	FILE*fin2;
	char myfilename3[120];
	FILE*fin3;
	char myfilename4[120];
	FILE*fin4;
	char myfilename5[120];
	FILE*fin5;
	double xarr1[N];
	double yarr1[N];
	double xvip1[N];
	double yvip1[N];
	double xarr2[N];
	double yarr2[N];
	double xvip2[N];
	double yvip2[N];
	double end[4];

	printf("Vvedite imia faila, gde vi hotite sgenerirovat' normalnie tochki-->"); //открываем файл
	scanf("%s", myfilename1); 
	fin1 = fopen(myfilename1, "w"); 
	
	if (!fin1) { 
		printf("Ne udalod' naiti fail %s\n", myfilename1); //проверяем, есть ли вообще такой файл
		return -1;
	}
	
	printf("Vvedite imia faila, gde vi hotite poluchit' tochki vipukloi obolochki-->"); //открываем файл
	scanf("%s", myfilename2); 
	fin2 = fopen(myfilename2, "w"); 
	
	if (!fin2) { 
		printf("Ne udalod' naiti fail %s\n", myfilename2); //проверяем, есть ли вообще такой файл
		return -1;
	}
	
	printf("Vvedite imia faila, gde vi hotite sgenerirovat' normalnie tochki-->"); //открываем файл
	scanf("%s", myfilename3); 
	fin3 = fopen(myfilename3, "w"); 
	
	if (!fin3) { 
		printf("Ne udalod' naiti fail %s\n", myfilename3); //проверяем, есть ли вообще такой файл
		return -1;
	}
	
	printf("Vvedite imia faila, gde vi hotite poluchit' tochki vipukloi obolochki-->"); //открываем файл
	scanf("%s", myfilename4); 
	fin4 = fopen(myfilename4, "w"); 
	
	if (!fin4) { 
		printf("Ne udalod' naiti fail %s\n", myfilename4); //проверяем, есть ли вообще такой файл
		return -1;
	}
	
	printf("Vvedite imia faila, gde budut dve blijaishie tochki-->"); //открываем файл
	scanf("%s", myfilename5); 
	fin5 = fopen(myfilename5, "w"); 
	
	if (!fin5) { 
		printf("Ne udalod' naiti fail %s\n", myfilename5); //проверяем, есть ли вообще такой файл
		return -1;
	}

	for (j = 0; j < N; j += 1)       //генерируем числа в диапазоне (-1, 1) и делим на их количество,
	{						        //таким образом получаем нормальное число, затем также генерируем 
		h = 0;				       //второе и записываем каждое в свой массив - у нас есть нормальные
		for (i = 0; i < M; i += 1)//х и у!!
		{
			p = ((-50 + rand() % 100));
			h += p / 50;
		}
		
		k = h / M;
		xarr1[j] = k;
		
		h = 0;
		for (i = 0; i < M; i += 1)
		{
			p = ((-50 + rand() % 100));
			h += p / 50;
		}
		
		k = h / M;
		yarr1[j] = k;
	}
	
	w = (-50 + rand() % 100) / 34; //генерируем числа
	for (j = 0; j < N; j += 1)
	{
		h = 0;
		for (i = 0; i < M; i += 1)
		{
			p = ((-50 + rand() % 100));
			h += p / 50;
		}
		
		k = h / M;
		xarr2[j] = k + w;
		
		h = 0;
		for (i = 0; i < M; i += 1)
		{
			p = ((-50 + rand() % 100));
			h += p / 50;
		}
		
		k = h / M;
		yarr2[j] = k + w;
	}

	for (i = 0; i < N; i += 1) //выводим все точки в файл
	{
		fprintf (fin1, "%.5lf     ", xarr1[i]);
		fprintf (fin1, "%.5lf\n", yarr1[i]);
		fprintf (fin3, "%.5lf     ", xarr2[i]);
		fprintf (fin3, "%.5lf\n", yarr2[i]);
	}

	minA = 100.0;
	minB = 100.0;
	
	for (j = 0; j < N; j += 1) //ищем индекс самой правой точки
	{
		if (xarr1[j] < minA)
		{
			minA = xarr1[j];
			min1 = j;
		}
	}	
	
	for (j = 0; j < N; j += 1) //ищем индекс самой правой точки
	{
		if (xarr2[j] < minB)
		{
			minB = xarr2[j];
			min2 = j;
		}
	}	

	xvip1[0] = xarr1[min1];
	yvip1[0] = yarr1[min1];	//записываем эти точки в массив с точками из выпуклой ободочки
	xvip2[0] = xarr2[min2];
	yvip2[0] = yarr2[min2];
	
	vsz1 = vip (xarr1, yarr1, xvip1, yvip1, min1, N); //находим выпуклые оболочки
	vsz2 = vip (xarr2, yarr2, xvip2, yvip2, min2, N);

	for (i = 0; i < vsz1; i += 1) //выводим точки, принадлежащие выпуклой оболочке
	{
		fprintf (fin2, "%.5lf     ", xvip1[i]);
		fprintf (fin2, "%.5lf\n", yvip1[i]);
	
	}	
	fprintf (fin2, "%.5lf     ", xvip1[0]); //выводим первую точку еще раз, чтобы закончить многоугольник
	fprintf (fin2, "%.5lf", yvip1[0]);
	
	for (i = 0; i < vsz2; i += 1) //выводим точки, принадлежащие выпуклой оболочке
	{
		fprintf (fin4, "%.5lf     ", xvip2[i]);
		fprintf (fin4, "%.5lf\n", yvip2[i]);
	
	}		
	fprintf (fin4, "%.5lf     ", xvip2[0]); //выводим первую точку еще раз, чтобы закончить многоугольник
	fprintf (fin4, "%.5lf", yvip2[0]);
	
	minfin = min_dist (xvip1, yvip1, xvip2, yvip2, end, vsz1, vsz2); //находим минимальное расстояние
	
	fprintf (fin5, "%.5lf     ", end[0]); //записываем в файл две ближайшие точки
	fprintf (fin5, "%.5lf\n", end[1]);
	fprintf (fin5, "%.5lf     ", end[2]); 
	fprintf (fin5, "%.5lf", end[3]);
	
	printf ("\n\n");
	printf ("Minimal'noe rasstoianie mejdu mnogougolnikami--> %.5lf", minfin); //выводим минимальное расстояние
	return 0;
}
