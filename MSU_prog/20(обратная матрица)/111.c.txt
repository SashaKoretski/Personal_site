//111_Корецкий_Александр_обратная_матрица

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>

#include "d_p.h"

int main() {
	double matrix[M][2 * N];
	double matrix_begin[M][N];
	double matrix_end[M][N];
	double matrix_check[M][N];
	double koef;
	int i, j, h, l;
	char myfilename[120];
	FILE*fin;

	printf("Vvedite imia logfaila-->"); //открываем файл
	scanf("%s", myfilename); 
	fin = fopen(myfilename, "w"); 
	
	if (!fin) { 
		printf("Ne udalod' naiti fail %s\n", myfilename); //проверяем, есть ли вообще такой файл
		return -1;
	}

	creation (matrix);
	zapis(0, matrix, matrix_begin);
	fprintf(fin, "Dannaia matrica:");
	small_vivod(matrix_begin, fin);
	
	treug_matrix(N, matrix, fin);
	edenich_matrix(matrix, fin);
	
	zapis(N, matrix, matrix_end);
	fprintf(fin, "Matrica, obratnaia dannoi:");
	small_vivod(matrix_end, fin);
	
	proisv_matric(matrix_begin, matrix_end, matrix_check);
	fprintf(fin, "Proisvedenie matric:");
	small_vivod(matrix_check, fin);
	
	if (check(matrix_check) == 1)
	{
		fprintf(fin, "Matrica iavliaetcia obratnoi!!!");
	}
	else
	{
		fprintf(fin, "Osibka!!!");
	}
	return 0;
}
