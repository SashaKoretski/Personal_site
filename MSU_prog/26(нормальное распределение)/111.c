//111_Корецкий_Александр_нормальное распределение

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include<stdlib.h>
#include<math.h>

#define N 2000 //количество точек
#define M 1000 //количество точек

int main() {
	int i, j;
	double p, h, k;
	double A[N];
	char myfilename1[120];
	FILE*fin1;
	
	printf("Vvedite imia faila, gde vi hotite sgenerirovat' normalnie tochki-->"); //открываем файл
	scanf("%s", myfilename1); 
	fin1 = fopen(myfilename1, "w"); 
	
	if (!fin1) { 
		printf("Ne udalod' naiti fail %s\n", myfilename1); //проверяем, есть ли вообще такой файл
		return -1;
	}
	
	for (j = 0; j < N; j += 1)       //генерируем числа в диапазоне (-1, 1) и делим на их количество,
	{						        //таким образом получаем нормальное число, затем также генерируем 
		h = 0;				       //второе и записываем каждое в свой массив - у нас есть нормальные
		for (i = 0; i < M; i += 1)//х и у!!
		{
			p = ((-50 + rand() % 100));
			p /= 50; 
			h += p;
		}
		k = h / M;
		A[j] = k;
	}
	
	for (i = 0; i < N; i += 1) //выводим все точки в файл
	{
		fprintf (fin1, "%.5lf\n", A[i]);
	}

	return 0;
}
