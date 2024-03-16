//111_Корецкий_Александр_итог

extern FILE*fin;
extern double alfa;

double f(double x); //уравнение
double fff(double x);
double hord(double A, double B, double (*eq)(double)); //хорда
double modu(double A); //модуль
int raw(double A, double B); //равенство
double integ(double A, double B, double (*eq)(double));
double reshenie (double A, double B, int *mist, double (*f)(double));