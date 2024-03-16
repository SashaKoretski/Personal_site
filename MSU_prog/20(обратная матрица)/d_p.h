//111_Корецкий_Александр_обратная_матрица

#define N 10
#define M 10
#define Ep 0.001

double modu(double A);//модуль
int raw(double A, double B);//равенство
void creation(double matrix[][2 * N]);//создание матрицы
void vivod(double matrix[][2 * N], FILE *fin);//вывод матрицы
void small_vivod(double matrix[][N], FILE *fin);//вывод матрицы
void zapis(int x, double matrix[][2 * N], double matrix1[][N]);//запись матрицы
void change_strok(double matrix[][2 * N], int s1, int s2, FILE *fin);//маняет строки местами
void umnoj_stroki(double matrix[][2 * N], int s, double k, FILE *fin);//умножает строку на число
void sum_strok(double matrix[][2 * N], int s1, int s2, double k, FILE *fin);//прибавляет к строке другую с коэффициентом
int check(double matrix[][N]);//проверка на единичность матрицы
void treug_matrix(int f, double matrix[][2 * N], FILE *fin);//перевод квадратной матрицы к треугольному виду
void edenich_matrix(double matrix[][2 * N], FILE *fin);//перевод матрицы треугольного вида к единичной
void proisv_matric(double matrix1[][N], double matrix2[][N], double mat[][N]);//произведение матриц