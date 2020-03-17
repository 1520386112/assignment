#include <iostream>
#include <iomanip>
using namespace std;
#define PI 3.1415926

class cylinder {
	public:
		cylinder(double ih, double ir);
		double getvolumn();
		double getarea();
		~cylinder();
	private:
		double r, h;
};
cylinder::cylinder(double ih, double ir) {
	h = ih;
	r = ir;
	cout << "构造函数被调用" << endl;
}
cylinder::~cylinder() {
	cout << "析构函数被调用" << endl;
}
double cylinder::getarea() {
	return 2 * PI * r * r + 2 * PI * r * h;
}
double cylinder::getvolumn(){
	return PI * r * r * h;
}
int main(){

	double d, h;
	cin >> d >> h;
	cylinder can(h, d / 2);
	cout << fixed << setprecision(6);
	cout << "油桶的容积是" << can.getvolumn() << " " << endl;
	cout << "铁皮的面积是" << can.getarea() << endl;
	return 0;
}