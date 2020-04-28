#include <iostream>
#include <string>
#include "FileOpe.h"
using namespace std;

int main()
{
	FileOpe* fileOpe = FileOpe::GetInstance();
	fileOpe->copy("a.txt", "b.txt");
	return 0;
}