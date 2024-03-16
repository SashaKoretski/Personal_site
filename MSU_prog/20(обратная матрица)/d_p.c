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

void creation(double matrix[][2 * N])//создание матрицы
{
	int i, j;
	
	for (i = 0; i < M; i+=1) 
    {
		for (j = 0; j < N; j+=1)
		{
			matrix[i][j] = ((-50 + rand() % 100));
		}
        
    }
	
	for (i = 0; i < M; i+=1)
    {
		for (j = N; j < 2 * N; j+=1)
		{
			if (j - N == i)
			{
				matrix[i][j] = 1;
			}
			else
			{
				matrix[i][j] = 0;
			}
		}
        
    }
}

void vivod(double matrix[][2 * N], FILE *fin)//вывод матрицы
{
	int i, j;
	
	for (i = 0; i < M; i += 1) 
    {
		fprintf(fin,"\n");
		for (j = 0; j < 2 * N; j += 1)
		{
			fprintf(fin, "%7.3lf ", matrix[i][j]);
		}
        
    }	
	
	fprintf(fin,"\n\n");
}

void small_vivod(double matrix[][N], FILE *fin)//вывод матрицы
{
	int i, j;
	
	for (i = 0; i < M; i += 1) 
    {
		fprintf(fin,"\n");
		for (j = 0; j < N; j += 1)
		{
			fprintf(fin, "%7.3lf ", matrix[i][j]);
		}
        
    }	
	
	fprintf(fin,"\n\n");
}

void zapis(int x, double matrix[][2 * N], double matrix1[][N])//запись матрицы
{
	int i, j;

	for (i = 0; i < M; i += 1) 
	{
		for (j = 0; j < N; j += 1)
		{
			matrix1[i][j] = matrix[i][j + x];
		}
		
	}	
}

void change_strok(double matrix[][2 * N], int s1, int s2, FILE *fin)//маняет строки местами
{
	int i;
	double p;
	
	for(i = 0; i < 2 * N; i += 1)
	{
		p = matrix[s2][i];
		matrix[s2][i] = matrix[s1][i];
		matrix[s1][i] = p;
		
	}
	
	fprintf(fin, "Meniaem mestami stroki %d i %d", s1, s2);
	vivod(matrix, fin);
}

void umnoj_stroki(double matrix[][2 * N], int s, double k, FILE *fin)//умножает строку на число
{
	int i;
	
	for(i = 0; i < 2 * N; i += 1)
	{
		matrix[s][i] *= k;
	}
	
	fprintf(fin, "Umnojaem stroku %d na %7.3lf", s, k);
	vivod(matrix, fin);
}

void sum_strok(double matrix[][2 * N], int s1, int s2, double k, FILE *fin)//прибавляет к строке другую с коэффициентом
{
	int i;
	
	for(i = 0; i < 2 * N; i += 1)
	{
		matrix[s1][i] += k * matrix[s2][i];
	}
	
	fprintf(fin, "Pribavliaem k %d stroke %d stroku s koefficientom %7.3lf", s1, s2, k);
	vivod(matrix, fin);
}

int check(double matrix[][N])//проверка на единичность матрицы
{
	int j, i;
	int c = 0;
	
	for(i = 0; i < N; i += 1)
	{
		for(j = 0; j < N; j += 1)
		{
			if ((j == i && raw(matrix[j][i], 1) == 1.000) || (j != i && raw(matrix[j][i], 0.000) == 1)) c += 1;
		}
	}
	
	if(c == N * N) return 1;
	else return 0;
}

void treug_matrix(int f, double matrix[][2 * N], FILE *fin)//перевод квадратной матрицы к треугольному виду
{
	int h, l, i;
	if (f == 1)
	{
		umnoj_stroki(matrix, N - f, (1 / matrix[M - 1][N - 1]),fin);
	}
	else
	{
		h = N - f;
		l = h + 1;
		while (matrix[h][i] == 0)
		{
			change_strok(matrix, h, l, fin);
			l += 1;
		}	
		
		for(i = h + 1; i < M; i += 1)
		{
			sum_strok(matrix, i, h, -(matrix[i][h])/(matrix[h][h]), fin);
		}
		
		umnoj_stroki(matrix, N - f, (1 / matrix[h][h]),fin);
		treug_matrix(f - 1, matrix, fin);
	}
}

void edenich_matrix(double matrix[][2 * N], FILE *fin)//перевод матрицы треугольного вида к единичной
{
	int i, j;
	for(i = N - 1; i > 0; i -= 1)
	{
		for(j = 0; j < i; j += 1)
		{
			sum_strok(matrix, j, i, -matrix[j][i], fin);
		}
	}
}

void proisv_matric(double matrix1[][N], double matrix2[][N], double mat[][N])//произведение матриц
{
	int i, j, h;

	for (i = 0; i < N; i += 1) 
	{
		for (j = 0; j < N; j += 1)
		{
			mat[i][j] = 0;
			for (h = 0; h < N; h += 1)
				{
					mat[i][j] += matrix1[i][h] * matrix2[h][j];
				}
		}
		
	}	
}




