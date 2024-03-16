//111_Корецкий_Александр_разворот_битового_представления_числа
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include<stdlib.h>
#include<time.h>

#include "d_p.h"

void rev(int *arr, int sz)  //разворот_битового_представления_числа
{
	int i = 0;
	int p;
	
	for (i; i < sz / 2; i += 1)
	{
		if (sz % 2 == 1 && i == sz / 2)
		{
			break;
		} 
		else 
		{
			arr[sz - i - 1] = arr[i];
		}
	}
}