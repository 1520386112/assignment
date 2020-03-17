#include <iostream>
using namespace std;

int mond[13] = { 0,31,0,31,30,31,30,31,31,30,31,30,31 };

void run_fix(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		mond[2] = 29;
		return;
	}
	mond[2] = 28;
}
bool time_isvalid(int h, int m, int s) {
	if (h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60) {
		return true;
	}
	return false;
}
bool date_isvalid(int y, int m, int d) {
	if (y < 0 || m <= 0 || d <= 0 || m > 12) return false;
	run_fix(y);
	if (d > mond[m])return false;
	return true;
}
class CTime {
	public:
		CTime(int a, int b, int c, int d, int e, int f);
		CTime(int a, int b, int c);
		CTime(CTime &ct);
		~CTime();
		void showTime();
		bool isvalid();
		int dayDiff(CTime t2)const;
	private:
		bool isval;
		int year, month, day, hour, minute, second;
};
CTime::CTime(int a, int b, int c) {
	bool date_valid = date_isvalid(a, b, c);
	hour = minute = second = 0;
	if (date_valid) {
		year = a;
		month = b;
		day = c;
		isval = true;
	}
	else {
		isval = false;
		year = month = day = 0;
	}
	cout << "构造函数被调用" << endl;
}
CTime::CTime(int a, int b, int c, int d, int e, int f) {
	bool date_valid = date_isvalid(a, b, c);
	bool time_valid = time_isvalid(d, e, f);
	if (date_valid && time_valid) {
		year = a;
		month = b;
		day = c;
		hour = d;
		minute = e;
		second = f;
		isval = true;
	}
	else {
		isval = false;
		year = month = day = hour = minute = second = 0;
		if (date_valid) {
			cout << "time error!" << endl;
		}
		else if(time_valid){
			cout << "date error!" << endl;
		}
		else {
			cout << "date and time error!" << endl;
		}
	}
	cout << "构造函数被调用" << endl;
}
CTime::CTime(CTime &ct) {
	year = ct.year;
	month = ct.month;
	day = ct.day;
	hour = ct.hour;
	minute = ct.minute;
	second = ct.second;
	isval = ct.isval;
	cout << "拷贝构造函数被调用" << endl;
}
CTime::~CTime(){
	cout << "析构函数被调用" << endl;
}
bool CTime::isvalid() {
	return isval;
}
void CTime::showTime() {
	cout << year << "/" << month << "/" << day << " " << hour << ":" << minute << ":" << second << endl;
}
int CTime::dayDiff(CTime t2)const {
	int d1 = 0, d2 = 0;
	int y = 0, m = 1;
	while (y < year) {
		run_fix(y++);
		d1 += 365 - 28 + mond[2];
	}
	run_fix(year);
	while (m <= month){
		d1 += mond[m++];
	}
	d1 += day;
	y = 0, m = 1;
	while (y < t2.year) {
		run_fix(y++);
		d2 += 365 - 28 + mond[2];
	}
	run_fix(t2.year);
	while (m <= t2.month) {
		d2 += mond[m++];
	}
	d2 += t2.day;
	return (d1 > d2) ? d1 - d2 : d2 - d1;
}
int main()
{	
	int  year, month, day, hour, minute, second;
	cin >> year >> month >> day >> hour >> minute >> second;
	CTime  t1(year, month, day, hour, minute, second);
	t1.showTime();
	CTime  t2(2000, 1, 1);  //利用默认形参将时间初始化为00:00:00 
	if (t1.isvalid())          //如果日期和时间合法，则计算天数 
	{
		int  days = 0;
		days = t1.dayDiff(t2);
		cout << "这两天之间相隔了" << days << "天" << endl;
		days = t2.dayDiff(t1);
		cout << "这两天之间相隔了" << days << "天" << endl;
	}
	return 0;
}