//111_Корецкий_Александр_интерполяция

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include<stdlib.h>

#include "d_p.h"

int main() {
	double arrX[N], arrY[N];
	double A, B;
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
	
	A = A_uravn(arrX, arrY); //находим коэффициенты
	B = B_uravn(arrX, arrY);
	
	printf("%lf * X + (%lf) = Y", A, B);
	return 0;
}
