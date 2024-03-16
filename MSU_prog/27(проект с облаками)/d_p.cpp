#include <iostream>
#include <string>
#include <fstream>
#include "d_p.h"

using namespace std;
constexpr auto M = 1000 //���������� �����;

Point::Point() {
	int i, j;
	double p1, p2, h1, h2, k1, k2;

	h1 = 0;
	h2 = 0;
	for (i = 0; i < M; i += 1)       //���������� ���������� ����� 
	{
		p1 = ((-50 + rand() % 100));
		p1 /= 50;
		h1 += p1;

		p2 = ((-50 + rand() % 100));
		p2 /= 50;
		h2 += p2;
	}
	k1 = h1 / M;
	x1 = k1;

	k2 = h2 / M;
	x2 = k2;

	y = 0;
}

void Cloud::Print_Cloud(ofstream& file) {
	int i;
	for (int i = 0; i < M; i += 1)
	{
		file << m_Point[i].x1 << " " << m_Point[i].x2 << endl;
	}
}

void Controller::Print_Cloud(ofstream& file) {
	m_Field.m_Cloud.print_cloud1(file);
	return 0;
}

void Interface::Starts() {
	string rule;
	srand(time(NULL));
	cout << "Vvedite komandu (help dlia vivoda spiska komand)\n";
	cin >> rule;
	read(rule);
}

void Interface::read(string rule)
{
	int n;
	string file;
	ofstream fout;

	if (rule.compare(0, 6, "Oblako") == 0)
	{
		cout << "\nVvedite imia faila \n";
		cin >> file;
		fout.open(file, ios_base::file);
		m_Controller.Print_Cloud(fout);
		fout.close();
	}

	if (rule.compare(0, 4, "help") == 0)
	{
		cout << "\nOblako --> vivod oblaka normalnih tochek v fail \n";
		cout << "Help --> pomosch \n";
	}
}



