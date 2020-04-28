#include <iostream>
#include <fstream>
using namespace std;

struct node {
	short id, score;
};

int main()
{
	int n;
	cin >> n;

	node* a = new node[n];
	node* b = new node[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i].id >> a[i].score;
	}

	ofstream ofs("out.txt", ios::binary | ios::out);
	ofs.write((char*)a, sizeof(a));
	ofs.close();

	ifstream ifs("out.txt", ios::binary | ios::in);

	node* p = b;
	for (int i = 0; i < n; ++i) {
		ifs.read((char*)(p++), sizeof(node));
	}
	ifs.close();

	ofstream os("out.txt", ios::app);

	os.write((char*)b, sizeof(b));
	os.close();

	return 0;
}