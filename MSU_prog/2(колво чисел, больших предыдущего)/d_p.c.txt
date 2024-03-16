#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <math.h>
#include "d_p.h"

int data_processing(int sz, int *A) { //вводим функцию

	int F;

	for (int j = 0; j < sz - 1; j += 1){
		if (A[j + 1] > A[j]) F += 1; //проверяем сколько чисел, больших предыдущего
	}

	return F;
}

int size(FILE*fin){ //делаем функцию, считывающую первый элемент (размер массива)
	int x;
	fscanf(fin, "%d", &x);
	
	if (x < 2) return -1; //проверяем, достаточно ли элементов в файле
	
	return x; //сделаем итогом функции размер массива
}