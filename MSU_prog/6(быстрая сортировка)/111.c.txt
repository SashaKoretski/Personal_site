//111_Корецкий_Александр_быстрая_сортировка

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include<stdlib.h>
#include <math.h>
#include<time.h>

#include "d_p.h"

int main() {
	double arr[N];
	double time;
	int i;
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
	
	gen(arr, N);
	
	fprintf(fin, " ");
	for (i = 0; i < N; i+=1)
    {
        if (i % 10 != 0)
            fprintf(fin, "%7.3lf ", arr[i]);
        if (i % 10 == 0 && i != 0)
            fprintf(fin, "%7.3lf\n ", arr[i]);
    }
	
	st = clock();
	sort(arr, 0, (N-1));
	end = clock();
	
	fprintf(fin, "\n");
	fprintf(fin, "\n");
    fprintf(fin, "Otsortirovannaia posledovatelnost'\n");
    fprintf(fin, "\n");
	
	fprintf(fin, " ");
	for (i = 0; i < N; i+=1)
    {
        if (i % 10 != 0)
            fprintf(fin, "%7.3lf ", arr[i]);
        if (i % 10 == 0 && i != 0)
            fprintf(fin, "%7.3lf\n ", arr[i]);
    }
	
	time = (double)(st - end) / CLOCKS_PER_SEC;
	
	printf ("%lf", time);
	return 0;
}
