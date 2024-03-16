//111_Корецкий_Александр_функции

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

#include "d_p.h"

int my_strcmp(const char *A, const char *B)
{
    unsigned f = strlen(A);
    unsigned l = strlen(B);
 
    if(f == l) return 0;
 
    return (f < l) ? -1 : 1;
}

char *my_strcpy(char *A, char *B) 
{
	while(*B!='\0') *(A++) = *(B++);
	return B;
}

int my_strstr(const char *A, const char *B)
{
    int k = 0, i, y = 0;
    for(i = 0; A[i] != '\0'; i++)
    {
        while(B[k] != '\0')
		{
            if(A[i] == B[k]) k++;
			else break;
            if (y == 0) y = i;
		}
    }
	return y;
}

char *my_strcat(char *A, char *B)
{
	while (*A)
	{
		A++;
	}
	while(*B)
	{
		*A = *B;
		A++;
		B++;
	}
	*A = '\0';
	return A;
}