//111_Корецкий_Александр_разворот_битового_представления_числа

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include<stdlib.h>
#include<time.h>

#include "d_p.h"

int main() {
	int ch = 3453;
	int ch2;
	int j = 0;
	int arr[16];
	printf("Vvedite chislo, chie bitovoe predstavlenie vi xotite rasvernut'-->"); //считываем число
	scanf("%d", &ch);
	printf("\n");
	for (j; j < 16; j+=1)//запись числа в двоичной форме
	{
		ch2 = (int)ch % 2;
		ch = (ch-ch2) / 2;
		arr[j] = ch2;
		printf("%d", arr[j]);
	}
	
	printf("-->");
	rev(arr, 16);//реверс
	
	j = 0;
	for (j; j < 16; j+=1)//запись развернутого числа в двоичной форме
	{
		printf("%d", arr[j]);
	}
	return 0;
}
