//111_Корецкий_Александр_обратная_матрица

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>

#include "d_p.h"
FILE* fin;

int main() {
	double matrix[N * N];
	double matrix_begin[N * N];
	double matrix_end[N * N];
	double matrix_check[N * N];
	double koef;
	int i, j, h, l;
	char myfilename[120];

    printf("Vvedite imia logfaila:");
    scanf("%s", myfilename);
    fin = fopen(myfilename, "r");

    if (!fin)
    {
        printf("Ne udalod' naiti fail %s\n", myfilename);
        return -1;
    }

	fprintf(fin, "Dannaia matrica:");
	creation (matrix_begin);
	creat_E(matrix_end);
	
	vivod(matrix_begin);
	
	zapis(matrix_begin, matrix);
	
	treug_matrix(N, matrix, matrix_end);
	edenich_matrix(matrix, matrix_end);
	
	fprintf(fin, "Matrica, obratnaia dannoi:");
	vivod(matrix_end);
	
	proisv_matric(matrix_begin, matrix_end, matrix_check);
	fprintf(fin, "Proisvedenie matric:");
	vivod(matrix_check);
	
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
