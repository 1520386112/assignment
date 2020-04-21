#include <iostream>
using namespace std;

class Complex {
public:
	Complex() :a(0), b(0) {}
	Complex(double a, double b) :a(a), b(b) {}
	void print() {
		cout << a << "+" << b << "i";
	}
	Complex operator+(Complex other) {
		Complex res;
		res.a = a + other.a;
		res.b = b + other.b;
		return res;
	}
	Complex operator-(Complex other) {
		Complex res;
		res.a = a - other.a;
		res.b = b - other.b;
		return res;
	}
	Complex operator+(double other) {
		Complex res;
		res.a = a + other;
		res.b = b;
		return res;
	}
	Complex operator-(double other) {
		Complex res;
		res.a = a - other;
		res.b = b;
		return res;
	}
private:
	double a;
	double b;
};

int  main()
{
	Complex  a(3, 4), b(1, -1), c;
	c = a + b;
	cout << "a+b=";
	c.print();
	cout << endl;
	c = a - b;
	cout << "a-b=";
	c.print();
	cout << endl;
	c = a + 100;
	cout << "a+100=";
	c.print();
	cout << endl;
	c = a - 2.5;
	cout << "a-2.5=";
	c.print();
	cout << endl;

	return  0;
}