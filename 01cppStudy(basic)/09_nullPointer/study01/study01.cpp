#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//空指针访问成员函数

class Person
{
public:
	void showClassName()
	{
		cout << "this is Person class" << endl;
	}
	void showPersonAge()
	{
		cout << "age=" << m_Age << endl;
	}
	int m_Age=10;
};

void test01()
{
	Person* p = new Person();
	p->showClassName();
	p->showPersonAge();
}

int main()
{
	test01();
	return 0;
}

