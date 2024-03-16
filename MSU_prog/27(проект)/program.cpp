#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;
#define PI 3.14159265
#define eps 0.0000001

class Point {
	// класс точка
	private:
		double x, y; // координаты точки
	public:
		int cluster;
		Point(double xx, double yy) : x(xx), y(yy), cluster(-1) {};
        ~Point() {}
        Point(const Point& p) : x(p.x), y(p.y), cluster(p.cluster) {}
		double getX() {
			return x;
		}
		double getY() {
			return y;
		}
		double distanceTo(Point p) {
		// расстояние от этой точки до точки (xx, yy)
			return sqrt((p.getX() - x)*(p.getX()-x) + (p.getY()-y)*(p.getY()-y));
		}
		Point& operator =(const Point& p)  {x=p.x;y=p.y; cluster=p.cluster; return *this;}
		void operator +=(const Point& p) {x+=p.x;y+=p.y;}
		void operator *=(const Point& p) {x*=p.x;y*=p.y;}
};

class Group {
	private:
		// массив точек, содержащихся в группе
		vector <Point> list;
		// число точек в группе
		int p_count;
		// центра масс
		Point gr_center;
		// цвет группы
		int r = rand() % 256, g = rand() % 256, b = rand() % 256;
	public:
		Group (double x, double y, double disp1, double disp2, int N) : list(), p_count(N), gr_center(0,0){
			// Генерация N - точек
			for (int i = 0; i < N; i++) {
				double s1 = 0, s2 = 0;
				for (int j = 0; j < 1000; j++) {
					s1+= (rand() % 1000) * 0.002 - 1;
					s2+= (rand() % 1000) * 0.002 - 1;
				}
				Point p(x + disp1* s1/1000, y + disp2 * s2/1000);
				list.push_back(p);
			}
			p_count = list.size();
			gr_center = mCenter();

		}
		void add_point(Point p) {
		// добавление точки в группу
			list.push_back(p);
			p_count++;
			gr_center = mCenter();
		}
		int get_size() {
			// вывод количества точек
			return list.size();
		}

		Point mCenter() {
			// Возвращаем центр масс группы
			double xs = 0, ys = 0;
			for (int i = 0; i < p_count; i++) {
				xs+= list[i].getX();
				ys+= list[i].getY();
			}
			Point p(xs/p_count, ys/p_count);
			return p;
		}
		void move(double x, double y) {
			// смещение группы на вектор {x, y}
			Point p(x, y);
			for (int i = 0; i < p_count; i++)
				list[i]+= p;
			gr_center = mCenter();
		}

		void rotate(double alfa) {
			// Вращения отн-но центра масс на alfa по часовой
			double x, y;
			Point p = mCenter();
			for (int i = 0; i < p_count; i++) {
				x = list[i].getX() - p.getX();
				y = list[i].getY() - p.getY();
				list[i] = Point(x*cos(alfa*PI/180) + y*sin(alfa*PI/180) + p.getX(),
								y*cos(alfa*PI/180) - x*sin(alfa*PI/180) + p.getY());
			}
		}
		void scale (double k1, double k2) {
			// растяжение группы в k1 - раз по Х, k2 - раз по Y
			Point p(k1, k2);
			for (int i = 0; i < p_count; i++)
				list[i]*= p;
			gr_center = mCenter();
		}
		void print_group(ofstream& print, bool colourful) {
		// вывод всех точек группы
			for (int i = 0; i < p_count; i++) {
				print << list[i].getX() << " " << list[i].getY();
				if (colourful) {
					print << " " << r << " " << g << " " << b;
				}
				print << endl;
			}
		}
		friend class Field;
		friend class Cluster_search;
};

class Cluster {
	private:
		vector <Point> points;
		int r = rand() % 256, g = rand() % 256, b = rand() % 256;
	public:
		Point c{0, 0};
		Cluster(Point p) : points(), c(p) {}
		void add_point(Point p) {
			points.push_back(p);
		}
		Point mCenter() {
			double xs = 0, ys = 0;
			for (int i = 0; i < (int)points.size(); i++) {
				xs+= points[i].getX();
				ys+= points[i].getY();
			}
			Point p(xs/(int)points.size(), ys/(int)points.size());
			return p;
		}
		void print_cluster(ofstream& print) {
		// вывод всех точек группы
			for (int i = 0; i < (int)points.size(); i++)
				print << points[i].getX() << " " << points[i].getY() << " " << r << " " << g << " " << b << endl;

		}
		void clear() {
			// удалить все точки кластера
			points.clear();
		}
};

class Cluster_search {
	private:
		vector <Cluster> cl_list;
	public:
		bool fill_clusters(int k, vector <Group>& gr_list) {
			// заполняем кластеры точками поля
			bool changed = false;
			for (int i = 0; i < (int)gr_list.size();i++) {
				for (int j = 0; j < gr_list[i].get_size();j++) {
					Point p = gr_list[i].list[j];
					int candidat;
					double dist = 10000;
					for (int l = 0; l < k;l++) {
						if (p.distanceTo(cl_list[l].c) < dist) {
							dist = p.distanceTo(cl_list[l].c);
							candidat = l;
						}
					}
					if (p.cluster != candidat) {
						changed = true;
						gr_list[i].list[j].cluster = candidat;
					}
					cl_list[candidat].add_point(p);
				}
			}
			return changed;
		}
		void print_all() {
			// печать всех кластеров
			ofstream print("clusters.txt");
			for (int i = 0; i < (int)cl_list.size(); i++) {
				cl_list[i].print_cluster(print);
			}
		}
		friend class Field;
};

class Field {
	// Ситдиков Даниил 211 группа
	// класс поле
	private:
		int size = 0; // количество точек
		vector <Point*> points;
	public:
		vector <Group> gr_list;
		Cluster_search s;
		double **distances; // матрица расстояний
		char** matrix;
		bool visit[100000];
		vector <int> a, b;
		Point get_p(int id) {
			int i = 0, j = 0;
			while (i <= id) {
				i+=gr_list[j].p_count;
				j++;
			}
			j--;
			i-= gr_list[j].p_count;

			return gr_list[j].list[id-i];
		}
		void add(Group g) {
			// добавляем группу в поле
			gr_list.push_back(g);
			size+=g.p_count;
		}
		void load (ifstream& file) {
			double x, y;
			int r, g, b;
			int r1 = 0, g1 = 0, b1 = 0;
			int id = 0;
			while (file >> x >> y >> r >> g >> b) {
				if (r1 != r || g1 != g || b1 != b) {
					Group gr(0, 0, 0, 0, 0);
					add(gr);
					id = gr_list.size()-1;
				}
				Point p(x, y);
				gr_list[id].add_point(p);
				r1 = r;
				g1 = g;
				b1 = b;
			}
            group_list();
		}
		void fill_matrix() {
			// заполняем матрицу расстояниями
			distances = new double*[size];
   			for (int i = 0; i < size; i++) distances[i] = new double[size];
   			int x = 0, y = 0;
   			for (int i = 0; i < (int)gr_list.size();i++) { for (int j = 0; j < (int)gr_list[i].get_size();j++) {
				y = 0;
				for (int l = 0; l < (int)gr_list.size();l++) { for (int n = 0; n < (int)gr_list[l].get_size();n++) {
					Point p1 = gr_list[i].list[j];
					Point p2 = gr_list[l].list[n];
					distances[x][y] = distances[y][x] = p1.distanceTo(p2);
					y++;
					}}
				x++;
			}}
		}
		Point random_point() {
			// возвращаем случайную точку поля
			int r;
			Point p(0, 0);
			r = rand() % size;

			for (int i = 0; i < (int)gr_list.size(); i++) {
				if (gr_list[i].get_size() > r) {
					p = gr_list[i].list[r];
					i = gr_list.size();
				}
				else {
					r-=gr_list[i].get_size();
				}
			}
			return p;
		}
		void group_list() {
			for (int i = 0; i < (int)gr_list.size(); i++) {
				cout << i << " " << gr_list[i].p_count << " points(" << gr_list[i].gr_center.getX() << ", " << gr_list[i].gr_center.getY() << ")" << endl;
			}
		}
		void print_all() {
			// печать всех групп поля
			ofstream print("field.txt");
			for (int i = 0; i < (int)gr_list.size(); i++) {
				cout << i << endl;
				gr_list[i].print_group(print, true);
			}
		}
		void kmeans(int k) { // алгоритм k-средних
			Cluster_search m;
			this->s = m;
			// Выбираем случайные k точек
			for(int i = 0; i < k; i++) {
				Cluster c(random_point());
				s.cl_list.push_back(c);
			}
			// обнуляем кластеры точек
			for (int i = 0; i < (int)gr_list.size();i++) {
				for (int j = 0; j < gr_list[i].get_size();j++) {
					gr_list[i].list[j].cluster = -1;
				}
			}
			bool changed = true; // поменялась ли принадлежность точки к кластеру
			while (changed == true) {
				changed = s.fill_clusters(k, gr_list);
				for (int i = 0; i < k;i++) {
					Point newp = s.cl_list[i].mCenter();
					s.cl_list[i].c = newp;
					s.cl_list[i].clear();
				}
			}
			changed = s.fill_clusters(k, gr_list);
		}
		void wave(int pp, int step) {
			// Волновой алгоритм
			// pp - посещаемая вершина, step - компонента связности(id кластера)
			visit[pp] = true;
			int z = 0;
			for (int i = 0; i < (int)gr_list.size();i++) {
				for (int j = 0; j < gr_list[i].get_size();j++) {
					if (pp == z) {
						s.cl_list[step].add_point(gr_list[i].list[j]);
						i = gr_list.size();
						j = gr_list[i].get_size();
					}
					z++;
				}
			}

			for (int j = 0; j < size;j++) {
				if (visit[j] == false && matrix[pp][j] == 1) {
					wave(j, step);
				}
			}
		}
		void porog_run(double d) {
			// d - порог
			Cluster_search m;
			this->s = m;
			// составляем матрицу
			fill_matrix();
			matrix = new char*[size];
   			 for (int i = 0; i < size; i++)
        		matrix[i] = new char[size];

			for (int i = 0; i < size;i++) {
				for (int j = 0; j < size;j++) {
					if (distances[i][j] < d)
						matrix[i][j] = true;
					else
						matrix[i][j] = false;
				}
			}

			for (int i = 0; i < size; i++) visit[i] = false;
			int step = 0, pp = 0;

			while (pp < size) { // пока не посетили все точки
				Cluster c(random_point());
				s.cl_list.push_back(c);
				wave(pp, step);
				for (int i = 0; i <= size; i++) {
					if (visit[i] == false) {
						pp = i;
						i = size;
					}
				}
				step++;
			}
			cout << step << " clusters found" << endl;

		}

		void spanning_tree() {
			ofstream graph("graph.txt");
			ofstream histogram("h.txt");
			fill_matrix(); // заполняем матрицу расстояний

			matrix = new char*[size];
			for (int i = 0; i < size;i++) {
				matrix[i] = new char[size];
				visit[i] = 0;
				for (int j = 0; j < size;j++)
					matrix[i][j] = 0;
			}
			a.clear();
			b.clear();
			// min_e[i] - минимальное расстояние из вершины i
			// sel_e[i] - конец наименьшего ребра из i
			vector<double> min_e (size, 9999);
			vector <int> sel_e (size, -1);
			min_e[0] = 0;
			for (int i = 0; i < size; i++) {
				int v = -1;
				// Ищем непосещенную вершину, расстояние до которой наименьшее
				// до тех вершин, которые прошли
				for (int j = 0; j < size; ++j)
					if (!visit[j] && (v == -1 || min_e[j] < min_e[v]))
						v = j;
				visit[v] = true;
				if (sel_e[v] != -1) {
					Point p1 = get_p(v), p2 = get_p(sel_e[v]);
					histogram << distances[v][sel_e[v]] << endl;
					graph << p1.getX() << " " << p1.getY()  << endl;
					graph << p2.getX() << " " << p2.getY()  << endl << endl;
					a.push_back(v);
					b.push_back(sel_e[v]);
					matrix[v][sel_e[v]] = matrix[sel_e[v]][v] = 1;
				}
 				// Находим наименьшее ребра для вершины v
				for (int to = 0; to < size; ++to)
					if (distances[v][to] < min_e[to]) {
						min_e[to] = distances[v][to];
						sel_e[to] = v;
					}
			}
			cout << "recorded to 'graph.txt'" << endl << "recorded to 'h.txt'" << endl;

		}
		void clusterize_tree(int k) {
			Cluster_search m;
			this->s = m;
			for (int i = 0; i < (int)a.size();i++) {
				for (int j = i; j < (int)a.size();j++) {
					if (distances[a[i]][b[i]] < distances[a[j]][b[j]]) {
						swap(b[i], b[j]);
						swap(a[i], a[j]);
					}
				}
			}

			for (int i = 0; i < k-1; i++)
				matrix[a[i]][b[i]] = matrix[b[i]][a[i]] = 0;
			int step = 0, pp = 0;
			for (int i = 0; i < size; i++) visit[i] = false;
			while (pp < size) { // пока не посетили все точки
				Cluster c(random_point());
				s.cl_list.push_back(c);
				wave(pp, step);
				for (int i = 0; i <= size; i++) {
					if (visit[i] == false) {
						pp = i;
						i = size;
					}
				}
				step++;
			}
		}

};


class Control {
	// управляющий класс
	private:
		Field f;
	public:
		void print_group(int i) {
			// вывести все точки группы
			ofstream gnu("group.txt");
			f.gr_list[i].print_group(gnu, false);
			//system("gnuplot");
			cout << "recorded to 'group.txt'" << endl;
		}
		void print_all() {
			f.print_all();
			cout << "recorded to 'field.txt'" << endl;
		}
		void group_list() {
			f.group_list();
		}
		void genrnd(int min, int max) {
			// равномерная генерация N точек с координатами от min до max
			Group gr(0, 0, 0, 0, 0);
			for (int i = 0; i < 1000; i++) {
				Point p(rand() % (max-min) + min, rand() % (max-min) + min);
				gr.add_point(p);
			}
			f.add(gr);
			cout << "group: generated | id = " << f.gr_list.size() - 1 << endl;
		}
		void move(int id, double x, double y) {
			f.gr_list[id].move(x, y);
		}
		void rotate(int id, double alfa) {
			f.gr_list[id].rotate(alfa);
		}
		void scale(int id, double r1, double r2) {
			f.gr_list[id].scale(r1, r2);
		}
		void create_group(double x, double y, double disp1, double disp2, int N) {
			// Генерируем группу и добавляем ее в поле
			Group gr(x, y, disp1, disp2, N);
			f.add(gr);
			cout << "group: created | id = " << f.gr_list.size() - 1 << endl;
		}
		void clusterize(int k) {
			f.kmeans(k);
		}
		void porog(double d) {
			f.porog_run(d);
		}
		void spanning_tree() {
			f.spanning_tree();
		}
		void clusterize_tree(int k) {
			f.clusterize_tree(k);
		}
		void print_clusters() {
			f.s.print_all();
			cout << "recorded to 'clusters.txt'" << endl;
		}
		void load(string filename) {
			ifstream file(filename);
			f.load(file);
			cout << "field loaded" << endl;
		}
};

class My_Interface {
    private:
        Control c;
        string a, b;
    public:
        void start(string h) {
        	vector <string> tokens;
            a = h;
            if (h == "") {
            	cout << "->";
            	getline(cin, a);
        	}

			size_t pos = 0;
			while ((pos = a.find(" ")) != string::npos) {
   				 tokens.push_back(a.substr(0, pos));
   				 a.erase(0, pos + 1);
			}
			tokens.push_back(a);
            if (tokens[0] == "genrnd")
                c.genrnd((int)stod(tokens[1]), (int)stod(tokens[2]));
            else if (tokens[0] == "group")
            	c.create_group(stod(tokens[1]), stod(tokens[2]), stod(tokens[3]), stod(tokens[4]), (int)stod(tokens[5]));
            else if (tokens[0] == "print")
            	c.print_group((int)stod(tokens[1]));
            else if (tokens[0] == "gr")
            	c.print_all();
            else if (tokens[0] == "cl")
            	c.print_clusters();
            else if (tokens[0] == "gr_list")
            	c.group_list();
            else if (tokens[0] == "move")
            	c.move((int)stod(tokens[1]), stod(tokens[2]), stod(tokens[3]));
            else if (tokens[0] == "rotate")
            	c.rotate((int)stod(tokens[1]), stod(tokens[2]));
            else if (tokens[0] == "kmeans")
            	c.clusterize((int)stod(tokens[1]));
            else if (tokens[0] == "porog")
            	c.porog(stod(tokens[1]));
            else if (tokens[0] == "sp_tree")
            	c.spanning_tree();
            else if (tokens[0] == "cl_count" && tokens[1] == "=")
            	c.clusterize_tree((int)stod(tokens[2]));
            else if (tokens[0] == "load")
            	c.load(tokens[1]);
            else if (tokens[0] == "run") {
            	ifstream file (tokens[1]);
                while (!file.eof()) {
                    getline(file, b);
                    start(b);
                }
            }
            else if (tokens[0] == "help")  {
                ifstream help ("help.txt");
                while (!help.eof()) {
                    getline(help, b);
                    cout << b << endl;
                }
            }
            else if (tokens[0] != "exit")
                cout << tokens[0] << ": command not found" << endl;
            if (tokens[0] != "exit" && h == "")
                start("");
        }

};

int main() {
    My_Interface a;
    a.start("");

    return 0;
}
