//111_Корецкий_Александр_алфавитный порядок

#define N1 200
extern FILE *fin;

typedef struct Node
{   
	int kolvo;
    char key[N1];
    struct Node* left;
    struct Node* right;
} Node;

void insert(Node **head, char value[]);
void fwrit(Node *root);
int srv(char s1[], char s2[]);
void copy(char a[], char b[]);