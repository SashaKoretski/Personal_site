#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <math.h>
#include "d_p.h"

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

int main() {
	char myfilename[120];
	int kol, resultat, y, N;
	int A[100];
	FILE*fin;
	int end = 0;

	printf("Vvedite imia faila c posledovatel'nost'iu -->"); //просим ввести имя файла для проверки
	scanf("%s", myfilename); //считываем имя файла
	fin = fopen(myfilename, "r"); //открываем файл
	
	if (!fin) { 
		printf("Ne udalod' naiti fail %s\n", myfilename); //проверяем, есть ли вообще такой файл
		return -1;
	}

	kol = size(fin);	//назначаем переменной result значение, равное значению выполненой функции

	if (kol == -1){
		printf("V faile nedostatochno dannih.\n"); //если в функции недостаточно элементов, выводим данное сообщение
	}	else {
		
			N = kol;
	
			for (int i = 0; i < N; i += 1){
				fscanf(fin, "%d", &A[i]);				//заполняем массив
			}
			
			end = data_processing(N, A);
			
			printf("V faile %d chisel, bol'shih predidushchego.\n", end); //если все прошло хорошо, выводим ответ
		}
	return 0;
}
