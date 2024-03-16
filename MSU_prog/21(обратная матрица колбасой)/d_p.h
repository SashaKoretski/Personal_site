//111_Корецкий_Александр_обратная_матрица

#define N 10

#define Ep 0.001

double modu(double A);//модуль
int raw(double A, double B);//равенство
void creation(double matrix[N * N]);//создание матрицы
void creat_E(double matrix[N * N]);//вывод матрицы
void vivod(double matrix[N * N]);//вывод матрицы
void zapis(double matrix[N * N], double matrix1[N * N]);//запись матрицы
void change_strok(double matrix[N * N], int s1, int s2);//маняет строки местами
void umnoj_stroki(double matrix[N * N], int s, double k);//умножает строку на число
void sum_strok(double matrix[N * N], int s1, int s2, double k);//прибавляет к строке другую с коэффициентом
int check(double matrix[N]);//проверка на единичность матрицы
void treug_matrix(int f, double matrix[N * N], double matrix2[N * N]);//перевод квадратной матрицы к треугольному виду
void edenich_matrix(double matrix[N * N], double matrix2[N * N]);//перевод матрицы треугольного вида к единичной
void proisv_matric(double matrix1[N * N], double matrix2[N * N], double mat[N * N]);//произведение матриц
extern FILE* fin;