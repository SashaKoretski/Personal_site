//111_Корецкий_Александр_расстояние_между_многоугольниками

double dist (double x1, double y1, double x2, double y2); //расстояние между двумя точками
int vip (double *xarr, double *yarr, double *xvip, double *yvip, int min, int sz); //количество точек в выпуклой оболочке
int where (double *xarr, double *yarr, double *xvip, double *yvip, int m, int h, int sz); //смотрит, где находится точка, записывает в массив с выпуклой оболочкой
double min_dist (double *xvip1, double *yvip1, double *xvip2, double *yvip2, double *end, int sz1, int sz2); //находит минимальное расстояние между двумя множествами точек