//111-Корецкий-Александр-алфавитный порядок
#include <stdio.h>
#include <string.h>

#include "d_p.h"

FILE* fin;

int main()
{
	int i, j, chis = 0, n, k, dlina = 0, r, st = 0, true = 0, ab; 
    char prob[]=",. :;()[]&!'+=-{}#\|/_*";
	char slovo[N1];
	Node *tree = NULL;
	FILE *Pas;
	char myfilename[120];
	char myfilename1[120];
	
	printf("Vvedite imia logfaila:");
    scanf("%s", myfilename);
    Pas = fopen(myfilename, "r");

    if (!Pas)
    {
        printf("Ne udalod' naiti fail %s\n", myfilename);
        return -1;
    }
	
	printf("Vvedite imia logfaila:");
    scanf("%s", myfilename1);
    fin = fopen(myfilename1, "r");

    if (!fin)
    {
        printf("Ne udalod' naiti fail %s\n", myfilename1);
        return -1;
    }
	
	n = strlen(prob);
	
	while (slovo[i] != EOF)
	{
		chis = 0;
		strncpy(slovo, "", sizeof(slovo));
		for (i = 0; chis == 0; i += 1)
		{
			slovo[i] = getc(Pas);
			for(k=0; k < n; k += 1)
			{
				if(slovo[i] == prob[k])
				{
					slovo[i] = '\0';
					chis = -1;
					if(i == 0) chis = 2;
				}
			}
			if (slovo[i] == EOF)
			{
				chis = 2;
				break;
			}
		}
		if(chis != 2)
		{
			fprintf(fin, "%s\n", slovo);
			insert(&tree, slovo);
		}	
	}	
	fwrit(tree);
    return 0;
}
