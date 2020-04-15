#include  <iostream> 
using  namespace  std;
const  int  pi = 3.14159;

class Shape {
public:
	Shape(int id) {
		m_ID = id;
		cout << "Shape constructor called:" << m_ID << endl;
	}
	~Shape() {
		cout << "Shape destructor called:" << m_ID << endl;
	}
	void SetID(int id) {
		m_ID = id;
	}
	int GetID() {
		return m_ID;
	}
	int getArea() {
		return 0;
	}
private:
	int m_ID;
};

class Circle : protected Shape {
public:
	Circle(int r, int id) :Shape(id){
		m_r = r;
		cout << "Circle constructor called:" << Shape::GetID() << endl;
	}
	~Circle() {
		cout << "Circle destructor called:" << Shape::GetID() << endl;
	}
	void SetR(int r) {
		m_r = r;
	}
	void SetID(int id) {
		Shape::SetID(id);
	}
	int GetR() {
		return m_r;
	}
	int GetID() {
		return Shape::GetID();
	}
	int getArea() {
		return pi * m_r * m_r;
	}
private:
	int  m_r;
};

class Rectangle :protected Shape {
public:
	Rectangle(int w, int h, int id):Shape(id) {
		m_w = w;
		m_h = h;
		cout << "Rectangle constructor called:" << Shape::GetID() << endl;
	}
	~Rectangle() {
		cout << "Rectangle destructor called:" << Shape::GetID() << endl;
	}
	int getArea() {
		return m_w * m_h;
	}
	void SetW(int w) {
		m_w = w;
	}
	void SetH(int h) {
		m_h = h;
	}
	void SetID(int id) {
		Shape::SetID(id);
	}
	int GetW() {
		return m_w;
	}
	int GetH() {
		return m_h;
	}
	int GetID() {
		return Shape::GetID();
	}
private:
	int m_w;
	int m_h;
};
int  main()
{
	Shape  s(1);//1表示ID 
	Circle  c(4, 2);//4表示半径，2表示ID 
	Rectangle  r(4, 5, 3);//4和5表示长和宽，3表示ID 
	cout << "Shape的面积" << s.getArea() << endl;
	cout << "Circle的面积" << c.getArea() << endl;
	cout << "Rectangle的面积" << r.getArea() << endl;
}