//111_Корецкий_поиск и замена

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* fin;
    FILE* fout;
    char str[50];
    char* A;
    char myfilename1[120];
    char myfilename2[120];

    printf("Vvedite imia faila1:");
    scanf("%s", myfilename1);
    fin = fopen(myfilename1, "r");

    if (!fin)
    {
        printf("Ne udalod' naiti fail %s\n", myfilename1);
        return -1;
    }

    printf("Vvedite imia faila2:");
    scanf("%s", myfilename2);
    fout = fopen(myfilename2, "w");

    if (!fout)
    {
		printf("Ne udalod' naiti fail %s\n", myfilename2);
        return -1;
    }

    while (1)
    {
        A = fgets(str, sizeof(str), fin);
		
        if (A == NULL)
        {
            if (feof(fin) != 0)
            {
                break;
            }
        }
		
        for (int i = 0; i < (sizeof(str)-1); i++)
        {
            if ((str[i] == 'f') && (str[i+1] == 'i') && (str[i+2] == 'n'))
            {
                fprintf(fout,"fin-");
            }
			fputc(str[i], fout);
        }
    }

    fclose(fin);
    fclose(fout);
    return 0;
}