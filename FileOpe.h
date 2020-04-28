#pragma once
#ifndef FILE_OPE
#define FILE_OPE
#include <string>
using namespace std;

class FileOpe
{
public:
	static FileOpe* GetInstance() {
		return new FileOpe();
	}
	void copy(string fromFileName, string ToFileName);
private:
	FileOpe() {};
};
#endif

