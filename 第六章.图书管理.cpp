#include <iostream>
using namespace std;

class Book {
public:
	void SetID(unsigned int id);
	void SetName(string name);
	void SetAuthor(string author);
	void SetIntroduction(string introduciton);
	void SetDate(string date);
	void SetPage(unsigned int page);
	unsigned int GetID();
	string GetName();
	string GetAuthor();
	string GetDate();
	unsigned int GetPage();
private:
	unsigned int m_ID;//编号
	string m_Name;//书名
	string m_Introduction;//简介
	string m_Author;//作者
	string m_Date;//日期
	unsigned int m_Page;//页数
};
void Book::SetID(unsigned int id) {
	m_ID = id;
}
void Book::SetName(string name) {
	m_Name = name;
}
void Book::SetIntroduction(string introduction) {
	m_Introduction = introduction;
}
void Book::SetAuthor(string author) {
	m_Author = author;
}
void Book::SetDate(string date) {
	m_Date = date;
}
void Book::SetPage(unsigned int page) {
	m_Page = page;
}
unsigned int Book::GetID() {
	return m_ID;
}
string Book::GetName() {
	return m_Name;
}
string Book::GetAuthor() {
	return m_Author;
}
string Book::GetDate() {
	return m_Date;
}
unsigned int Book::GetPage() {
	return m_Page;
}
class Store {
public:
	Store() {
		m_Count = 0;
		m_pBook = NULL;
		cout << "Store default constructor called!" << endl;
	}
	Store(int n) {
		m_Count = n;
		m_pBook = new Book[n];
		cout << "Store constructor with (int n) called!" << endl;
	}
	virtual ~Store() {
		m_Count = 0;
		if (m_pBook != NULL) {
			delete[] m_pBook;
		}
		cout << "Store destructor called!" << endl;
	}
	Store(const Store& other);
	void in(Book &book);
	void out(string name);
	unsigned int GetCount();
	Book findbyName(string name);
	Book findbyID(unsigned int id);
	void printList();
private:
	Book* m_pBook;
	unsigned int m_Count;
};
Store::Store(const Store& other) {
	m_Count = other.m_Count;
	m_pBook = new Book[m_Count];
	for (int i = 0; i < m_Count; ++i) {
		m_pBook[i] = other.m_pBook[i];
	}
}
void Store::in(Book& book) {
	m_Count++;
	Book* temp = new Book[m_Count];
	for (int i = 0; i < m_Count - 1; ++i) {
		temp[i] = m_pBook[i];
	}
	temp[m_Count - 1] = book;
	delete[] m_pBook;
	m_pBook = temp;
}
void Store::out(string name) {
	Book* temp = new Book[m_Count - 1];
	int ind = 0;
	for (int i = 0; i < m_Count; ++i) {
		if (m_pBook[i].GetName() == name) continue;
		temp[ind++] = m_pBook[i];
	}
	delete[] m_pBook;
	m_pBook = temp;
	m_Count--;
}
unsigned int Store::GetCount() {
	return m_Count;
}
Book Store::findbyID(unsigned int id) {
	for (int i = 0; i < m_Count; ++i) {
		if (m_pBook[i].GetID() == id) {
			return m_pBook[i];
		}
	}
	return *new Book();
}
Book Store::findbyName(string name) {
	for (int i = 0; i < m_Count; ++i) {
		if (m_pBook[i].GetName() == name) {
			return m_pBook[i];
		}
	}
	return *new Book();
}
void Store::printList() {
	cout << "There are totally " << m_Count << " Books:" << endl;
	for (int i = 0; i < m_Count; ++i) {
		cout << "ID=" << m_pBook[i].GetID()<< ";  ";
		cout << "Name:" << m_pBook[i].GetName() << ";  ";
		cout << "Author:" << m_pBook[i].GetAuthor() << ";  ";
		cout << "Date:" << m_pBook[i].GetDate() << ";" << endl;
	}
}
int  main()
{
	Store  s;
	Book  b1, b2, b3;
	b1.SetID(1);
	b1.SetName("C++  语言程序设计(第4版)");
	b1.SetAuthor("郑莉");
	b1.SetIntroduction("介绍C++及面向对象的知识");
	b1.SetDate("201007");
	b1.SetPage(529);
	b2.SetID(2);
	b2.SetName("离散数学");
	b2.SetAuthor("左孝凌");
	b2.SetIntroduction("介绍命题逻辑、谓词逻辑、集合论、代数系统和图论");
	b2.SetDate("198209");
	b2.SetPage(305);
	b3.SetID(3);
	b3.SetName("c程序设计");
	b3.SetAuthor("谭浩强");
	b3.SetIntroduction("介绍C程序设计中的基本知识，如语句格式、语法等");
	b3.SetDate("201006");
	b3.SetPage(355);

	cout << "第一本书入库" << endl;
	s.in(b1);
	cout << "第二本书入库" << endl;
	s.in(b2);
	cout << "第三本书入库" << endl;
	s.in(b3);
	cout << "现有库存书籍数量：" << s.GetCount() << endl;
	cout << "查找并出库图书：离散数学" << endl;
	Book  tmpbook = s.findbyName("离散数学");
	if (tmpbook.GetID() != 0)
	{
		s.out("离散数学");
		cout << "离散数学  已成功出库" << endl;
	}
	else
		cout << "没有找到name为离散数学的书" << endl;
	cout << "现有库存书籍数量：" << s.GetCount() << endl;

	cout << "查找图书  ID：3" << endl;
	tmpbook = s.findbyID(3);
	if (tmpbook.GetID() != 0)
		cout << "找到ID为" << 3 << "的书，书名：" << tmpbook.GetName() << endl;
	else
		cout << "没有找到ID为" << 3 << "的书" << endl;

	cout << "查找图书  name：离散数学" << endl;
	tmpbook = s.findbyName("离散数学");
	if (tmpbook.GetID() != 0)
		cout << "找到name为离散数学的书，ID：" << tmpbook.GetID() << endl;
	else
		cout << "没有找到name为离散数学的书" << endl;

	cout << "输出所有库存图书的信息" << endl;
	s.printList();
	cout << "程序运行结束" << endl;
	return  0;
}