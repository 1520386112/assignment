#include <iostream>
using namespace std;

int cover = 0, bottol = 0;
int tot = 0;

void buybuybuy(int cover, int bottol) {

	if (cover < 3 && bottol < 2) return;

	int newWater = cover / 3 + bottol / 2;
	cover %= 3;
	bottol %= 2;
	tot += newWater;
	cover += newWater;
	bottol += newWater;

	buybuybuy(cover, bottol);
}

int main()
{
	int money;
	cin >> money;
	tot = cover = bottol = money / 1;
	buybuybuy(cover, bottol);
	cout << tot << endl;
	return 0;
}