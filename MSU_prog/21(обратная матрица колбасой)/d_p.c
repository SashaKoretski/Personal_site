//111_Корецкий_Александр_обратная_матрица

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>

#include "d_p.h"

double modu(double A)//модуль
{
	if (A > 0) return A;
	else return -A;
}

int raw(double A, double B)//равенство
{
	double Ee = Ep;
	if ((modu(B - A)) < Ee)
	{
		return 1;
	}
	else return 0;
}

void creation(double matrix[N * N])//создание матрицы
{
	int j;
	
	for (j = 0; j < N * N; j += 1) 
    {
		matrix[j] = ((-50 + rand() % 100));
    }
}
	
void creat_E(double matrix[N * N])//создание матрицы E
{
	int j;
	
	for (j = 0; j < N * N; j += 1) 
    {
		matrix[j] = 0;
    }
	
	for (j = 0; j < N * N; j += N + 1) 
    {
		matrix[j] = 1;
    }
}

void vivod(double matrix[N * N])//вывод матрицы
{
	int i, j;
	
	for (i = 0; i < N; i += 1) 
    {
		fprintf(fin, "\n");
		for (j = 0; j < N; j += 1)
		{
			fprintf(fin, "%7.3lf ", matrix[j + N * i]);
		}
        
    }	
	
	fprintf(fin, "\n\n");
}

void zapis(double matrix[N * N], double matrix1[N * N])//запись матрицы
{
	int i, j;

	for (i = 0; i < N; i += 1) 
	{
		for (j = 0; j < N; j += 1)
		{
			matrix1[j + N * i] = matrix[j + N * i];
		}
		
	}	
}

void change_strok(double matrix[N * N], int s1, int s2)//маняет строки местами
{
	int i;
	double p;
	
	for(i = 0; i < N; i += 1)
	{
		p = matrix[i + N * s2];
		matrix[i + N * s2] = matrix[i + N * s1];
		matrix[i + N * s1] = p;
		
	}
	
	fprintf(fin, "Meniaem mestami stroki %d i %d", s1, s2);
	vivod(matrix);
}

void umnoj_stroki(double matrix[N * N], int s, double k)//умножает строку на число
{
	int i;
	
	for(i = 0; i < 2 * N; i += 1)
	{
		matrix[i + N * s] *= k;
	}
	
	fprintf(fin, "Umnojaem stroku %d na %7.3lf", s, k);
	vivod(matrix);
}

void sum_strok(double matrix[N * N], int s1, int s2, double k)//прибавляет к строке другую с коэффициентом
{
	int i;
	
	for(i = 0; i < N; i += 1)
	{
		matrix[i + N * s1] += k * matrix[i + N * s2];
	}
	
	fprintf(fin, "Pribavliaem k %d stroke %d stroku s koefficientom %7.3lf", s1, s2, k);
	vivod(matrix);
}

int check(double matrix[N])//проверка на единичность матрицы
{
	int j, i;
	int c = 0;
	
	for(i = 0; i < N; i += 1)
	{
		for(j = 0; j < N; j += 1)
		{
			if ((j == i && raw(matrix[i + N * j], 1) == 1.000) || (j != i && raw(matrix[i + N * j], 0.000) == 1)) c += 1;
		}
	}
	
	if(c == N * N) return 1;
	else return 0;
}

void treug_matrix(int f, double matrix[N * N], double matrix2[N * N])//перевод квадратной матрицы к треугольному виду
{
	int h, l, i;
	if (f == 1)
	{
		umnoj_stroki(matrix2, N - f, (1 / matrix[N * N - 1]));
		umnoj_stroki(matrix, N - f, (1 / matrix[N * N - 1]));	
	}
	else
	{
		h = N - f;
		l = h + 1;
		while (matrix[h + N * h] == 0)
		{
			change_strok(matrix, h, l);
			change_strok(matrix2, h, l);
			l += 1;
		}	
		
		for(i = h + 1; i < N; i += 1)
		{
			sum_strok(matrix2, i, h, -(matrix[h + N * i])/(matrix[h + N * h]));
			sum_strok(matrix, i, h, -(matrix[h + N * i])/(matrix[h + N * h]));
		}
		
		umnoj_stroki(matrix2, N - f, (1 / matrix[h + N * h]));
		umnoj_stroki(matrix, N - f, (1 / matrix[h + N * h]));
		treug_matrix(f - 1, matrix, matrix2);
	}
}

void edenich_matrix(double matrix[N * N], double matrix2[N * N])//перевод матрицы треугольного вида к единичной
{
	int i, j;
	for(i = N - 1; i > 0; i -= 1)
	{
		for(j = 0; j < i; j += 1)
		{
			sum_strok(matrix2, j, i, -matrix[i + N * j]);
			sum_strok(matrix, j, i, -matrix[i + N * j]);
		}
	}
}

void proisv_matric(double matrix1[N * N], double matrix2[N * N], double mat[N * N])//произведение матриц
{
	int i, j, h;

	for (i = 0; i < N; i += 1) 
	{
		for (j = 0; j < N; j += 1)
		{
			mat[j + N * i] = 0;
			for (h = 0; h < N; h += 1)
			{
				mat[j + N * i] += matrix1[h + N * i] * matrix2[j + N * h];
			}
		}
	}	
}




