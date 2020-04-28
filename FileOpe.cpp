#include "FileOpe.h"
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void FileOpe::copy(string fromFileName, string toFileName) {
	vector<double> a;
	double temp;

	ifstream ifs(fromFileName);

	if (ifs) {
		while (ifs >> temp) {
			a.push_back(temp);
		}
		ifs.close();

		sort(a.begin(), a.end());

		ofstream ofs(toFileName);

		for (int i = 0; i < a.size(); ++i) {
			ofs << a[i] << " ";
		}
		ofs.close();
	}
}