#include <iostream>
#include <iomanip>
using namespace std;

void Cha(double a, double b, double c, double d) {

	cout << setiosflags(ios::fixed) << setprecision(2) << a - c << " " << b - d << endl;
}
int main()
{
	double a, b, c, d;
	cin >> a >> b >> c >> d;
	Cha(a, b, c, d);
	return 0;
}