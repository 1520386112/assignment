#include <iostream>
#include <cctype>
#include <string>
#include <cmath>
using namespace std;

int minPath(string a, string b){
	int minCha = 100000;
	for (int i = 0; i < a.length(); ++i) {
		for (int j = 0; j < b.length(); ++j) {
			int cha = abs(a[i] - b[j]);

			if (cha < minCha) minCha = cha;
		}
	}
	return minCha;
}
int main()
{
	string a, b;
	
	cin >> a >> b;

	for (int i = 0; i < a.length(); ++i) {
		a[i] = tolower(a[i]);
	}
	for (int i = 0; i < b.length(); ++i) {
		b[i] = tolower(b[i]);
	}

	cout << minPath(a, b) << endl;

	return 0;
}