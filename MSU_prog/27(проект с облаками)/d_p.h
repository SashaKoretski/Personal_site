class Point
{
public:
	Point();
	int Opoint(double ox, double oy);
	double x1;
	double x2;
	double y;
private:
};

class Cloud
{
public:
	Cloud();
	Point m_Point[3000];
	void Print_Cloud();
	int setN(int N1);
	int getN() { return N_points; };
	int Opoint(double ox, double oy);

private:
	int N_points;
};

class Field
{
public:
	Field();
	Cloud* m_Cloud;
	int setN(int N1);

private:
	int N_couds;
	int N_points;
	bool Status_Work;

};

class Controller
{
public:
	Controller();
	Field* m_Field;
	Cloud* m_Cloud;
	void Print_Cloud();

private:
	bool Status_Work;
};

class Interface
{
public:
	Interface();
	Controller* m_Controller;
	void Starts();
	void read(string rule);
};
