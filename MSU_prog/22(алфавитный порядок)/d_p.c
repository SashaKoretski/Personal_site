//111_Корецкий_Александр_алфавитный порядок
#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "d_p.h"

void insert(Node **head, char value[])
{
	Node *tmp = NULL;
	Node *ins = NULL;
	if (*head == NULL)
	{
		*head = (Node*) malloc(sizeof(Node));
			(*head)->left = (*head)->right = NULL;
			strncpy((*head)->key, "", sizeof((*head)->key));
		copy((*head)->key, value);
			(*head)->kolvo=1;
		return;
	}
	
	tmp = *head;
		if (srv(value, tmp->key) == -1)
		{
			insert (&(tmp->right), value);
		}
		else if (srv(value, tmp->key) == 1)
		{
			insert(&(tmp->left), value);
		}
		else 
		{
			(tmp->kolvo)=(tmp->kolvo)+1;
		}
}

void fwrit(Node *root)
{
	if (root == NULL) 
	{	
		return;
	}	
	fwrit(root->left);
	if((root->key)[0] != '\0') 
	{
		printf("%d %s\n", root->kolvo, root->key);
	}
	fwrit(root->right);
}

int srv(char s1[], char s2[])
{
	int n;
	for(n = 0; (s1[n] != '\0') || (s2[n] != '\0'); n += 1)
	{
		if (s1[n] != s2[n]) break;
	}
	if (s1[n] < s2[n]) return 1;
	if (s1[n] > s2[n]) return -1;
	return 0;
}

void copy(char a[], char b[])
{
	int i;
	for(i = 0; i < strlen(b); i += 1) a[i] = b[i];
}