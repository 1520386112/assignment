#include <iostream>
using namespace std;

class CPoint {
public:
	CPoint(int a, int b);
	CPoint(const CPoint& a);
	friend class CRectangle;
private:
	int x, y;
};
CPoint::CPoint(int a = 0, int b = 0){
	x = a;
	y = b;
	cout << "CPoint contstructor with default value(0,0) is called." << endl;
}
CPoint::CPoint(const CPoint& a) {
	x = a.x;
	y = a.y;
	cout << "CPoint copy contstructor is called." << endl;
}
class CRectangle {
public:
	int GetArea();
	CRectangle();
	CRectangle(CPoint p1, CPoint p2);
	CRectangle(int a, int b, int c, int d);
	CRectangle(const CRectangle &a);
private:
	CPoint zs;
	CPoint yx;
};
CRectangle::CRectangle() {
	cout << "CRectangle default contstructor is called." << endl;
}
CRectangle::CRectangle(CPoint p1, CPoint p2) :zs(p1), yx(p2) {
	cout << "CRectangle contstructor with (CPoint,CPoint) is called." << endl;
}
CRectangle::CRectangle(int a, int b, int c, int d) :zs(a, b), yx(c, d){
	cout << "CRectangle contstructor with (int,int,int,int) is called." << endl;
}
CRectangle::CRectangle(const CRectangle& a) :zs(a.zs), yx(a.yx){
	cout << "CRectangle copy contstructor is called." << endl;
}
int CRectangle::GetArea() {
	int ans = (zs.y - yx.y) * (yx.x - zs.x);
	return ans > 0 ? ans : -ans;
}
int main()
{
	int a = 1, b = 1, c = 6, d = 11;

	cout << "# Define p1 ######" << endl;

	CPoint p1;

	cout << "# Define p2 ######" << endl;

	CPoint p2(10, 20);

	cout << "# Define rect1 ######" << endl;

	CRectangle rect1;

	cout << "# Define rect2 ######" << endl;

	CRectangle rect2(p1, p2);

	cout << "# Define rect3 ######" << endl;

	CRectangle rect3(a, b, c, d);

	cout << "# Define rect4 ######" << endl;

	CRectangle rect4(rect2);

	cout << "# Calculate area ######" << endl;

	cout << "rect1面积为" << rect1.GetArea() << endl;

	cout << "rect2面积为" << rect2.GetArea() << endl;

	cout << "rect3面积为" << rect3.GetArea() << endl;

	cout << "rect4面积为" << rect4.GetArea() << endl;

	system("pause");
	return 0;
}