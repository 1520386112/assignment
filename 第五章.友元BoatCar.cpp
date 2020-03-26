#include <iostream>
using namespace std;

class Car;
class Boat {
public:
	Boat(int w) { weight = w; }
private:
	int weight;
	friend int totalweight(Boat& b, Car&c);
};
class Car {
public :
	Car(int w) { weight = w; }
private :
	int weight;
	friend int totalweight(Boat& b, Car&c);
};
int totalweight(Boat&b,Car &c) {
	return b.weight + c.weight;
}
int main()
{
	Boat b(100);
	Car c(200);
	cout << totalweight(b, c) << endl;
	return 0;
}