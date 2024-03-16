//111_Корецкий_Александр_интерполяция

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include<stdlib.h>

#include "d_p.h"

int main() {
	double arrX[N], arrY[N];
	double newX, newY;
	int i;
	
	printf("Vvedite Xi: "); //узнаем иксы и игреки
	
	for (i = 0; i < N; i+=1)
    {
        scanf("%lf", &arrX[i]);
    }
	
	printf("Vvedite Yi: ");
	
	for (i = 0; i < N; i+=1)
    {
        scanf("%lf", &arrY[i]);
    }
	
	sort(arrX, arrY, 0, (N-1)); //сортируем точки по иксам
	
	printf("Vvedite novii X: "); //узнаем новый икс
    scanf("%lf", &newX);
	
	if (newX < arrX[0] || newX > arrX[N - 1]) //проверяем, находится ли новый икс на данном отрезке
	{
		printf("Novii X ne popadaet v dannii otresok.");
	}
	else
	{
		for (i = 0; i < (N - 1); i+=1)
		{
			if (newX >= arrX[i] && newX <= arrX[i + 1]) break; //находим, на каком из отрезков находится новый икс
		}
		
		newY = new_y(arrX[i], arrY[i], arrX[i + 1], arrY[i + 1], newX); //находим новый игрек
	}
	
	printf("Y = %lf", newY);
	return 0;
}
