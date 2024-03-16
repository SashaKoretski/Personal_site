//111_Корецкий_Александр_вывод_всех_К-элементных_подмножеств_из_N

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
 
 #define N 16
 
int main()
{
    int k, n, w, s, d, b, j, i, sz, h, check;
    int st[N];
    int res[N];
	char myfilename[120];
	FILE*fin;
	
    printf ("Vvedite k -->");
    scanf ("%d",&k);
	printf("Vvedite imia faila dlia vivoda -->"); 
	scanf("%s", myfilename); 
	fin = fopen(myfilename, "w"); //открываем файл
	
	if (!fin) { 
		printf("Ne udalod' naiti fail %s\n", myfilename); //проверяем, есть ли вообще такой файл
		return -1;
	}
	
    if (k <= 0 || k > N) printf("OSHIBKA");//выводим ошибку, если что-то не так
	else
	{
		for (i = 0; i < N; i += 1)
			st[i] = pow(2,i);
		sz = pow(2,N);
		
		for (i = 1; i < sz - 1; i += 1) //рассмотрим все подмножества и найдем из них нужные
		{
			w = 0;
			for (j = 0; j < N; j += 1)
			{
				if (i & st[j]) res[j] = 1; //используем побитовое И чтобы заполнить массив res
				else res[j] = 0;
				
				w += res[j];
				if (w == k)
				{
					check = 0;
					for (h = 0; h < N; h += 1)
					{
						check += res[h];
					}
					
					if (check == k) //проверяем, действительно ли в подмножестве К элементов
					{
						for ( j = 0; j < N; j += 1) //выводим К-элементное подмножество
						{
							b = res[j] * (j+1);
							if (res[j] != 0) fprintf(fin, "%d ",b );
						}
					fprintf(fin, "\n");
					}
				}
	
			}
	
		}
	}
    return 0;
}