//111_Корецкий_Александр_функции

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

#include "d_p.h"

int main() {
	char A[] = "aaa";
	char B[] = "aba";
	char C[] = "aaa";
	char D[] = "bbb";
	char E[] = "sprjpjpjsdfabcdplfam[pn";
	char F[] = "abcd";
	char G[] = "aaabbb";
	
	if (strcmp(A, B) * my_strcmp(A, B) >= 0 && strcmp(A, C) * my_strcmp(A, C) >= 0)
	{
		printf("my_strcmp rabotaiet!!!\n");
	}
	else 
	{
		printf("my_strcmp ne rabotaiet!!!\n");
	}
	
	strcpy(B, A);
	my_strcpy(D, A);
	
	if (my_strcmp(D, B) == 0)
	{
		printf("my_strcpy rabotaiet!!!\n");
	}
	else 
	{
		printf("my_strcpy ne rabotaiet!!!\n");
	}

	if (my_strstr(E, F) == 11)
	{
		printf("my_strstr rabotaiet!!!\n");
	}
	else 
	{
		printf("my_strstr ne rabotaiet!!!\n");
	}
	
	my_strcat(D, A);
	
	if (my_strcmp(D, G) == 0)
	{
		printf("my_strcat rabotaiet!!!\n");
	}
	else 
	{
		printf("my_strcat ne rabotaiet!!!\n");
	}
	return 0;
}
