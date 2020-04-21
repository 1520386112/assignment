#include <iostream>
using namespace std;

class Complex {
public:
	Complex() :a(0), b(0) {}
	Complex(double a, double b) :a(a), b(b) {}
	void print() {
		cout << "(" << a << ")" << "+" << "(" << b << "i)";
	}
	friend Complex operator+(Complex a, Complex b) {
		return Complex(a.a+b.a, a.b+b.b);
	}
	friend Complex operator+(Complex a, double b) {
		return Complex(a.a + b, a.b);
	}
	friend Complex operator+(double a, Complex b) {
		return Complex(a + b.a, b.b);
	}
	friend Complex operator-(Complex a, Complex b) {
		return Complex(a.a - b.a, a.b - b.b);
	}
	friend Complex operator-(Complex a, double b) {
		return Complex(a.a - b, a.b);
	}
	friend Complex operator-(double a, Complex b) {
		return Complex(a - b.a, -b.b);
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
	c = 100 + a;
	cout << "100+a=";
	c.print();
	cout << endl;
	c = 2.5 - a;
	cout << "2.5-a=";
	c.print();
	cout << endl;
	return  0;
}