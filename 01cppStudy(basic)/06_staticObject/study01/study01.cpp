#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Person
{
public:
	//静态成员函数的特点：
	//1、程序共享一个函数
	//2、静态成员函数只能够访问静态成员变量

	static void func()
	{
		cout << "static void func()的调用" << endl;
		m_A = 200;
	}

	static int m_A;
	int m_B;

private:
	static void func2()
	{
		cout << "static void func2()的调用" << endl;
	}
};


int Person::m_A = 10;




void test01()
{
	//静态成员变量的两种访问方式

	//1、通过对象
	Person p1;
	p1.func();


	//2、通过类名
	Person::func();
}
int main()
{
	test01();


	return 0;
}

