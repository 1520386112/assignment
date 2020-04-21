#include <iostream>
using namespace std;

class Point {
public:
	Point(int x, int y):x(x), y(y){}
	friend ostream& operator<<(ostream &os, Point p) {
		os << "(" << p.x << "," << p.y << ")" << endl;
		return os;
	}
	Point& operator++() {
		x++;
		y++;
		return *this;
	}
	Point operator++(int) {
		Point ori(0, 0);
		ori.x = x++;
		ori.y = y++;
		return ori;
	}
private:
	int x;
	int y;
};

int  main()
{
	Point  a(1, 3);
	cout << a;
	cout << a++;
	cout << ++a;
	return  0;
}