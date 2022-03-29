#include <iostream>
#include <fstream>
#include <string>

using namespace std;
/*类对象作为类成员*/
//先构造出类对象，在构造出顶层的类
//析构函数，先销毁顶层的类，再销毁成员类对象



//手机
class Phone
{
public:
	Phone(string pName)
	{
		cout << "Phone的构造函数调用" << endl;
		m_PName = pName;
	}
	string m_PName;
};
//人类
class Person
{
public:
	Person(string name, string pName):m_Name(name),m_Phone(pName)
	{
		cout << "Person的构造函数调用" << endl;
	}
	string m_Name;//人名
	Phone m_Phone;//手机
};

void test01()
{
	Person p("张三", "苹果12");
	cout << p.m_Name << "拿着" << p.m_Phone.m_PName << endl;
}
int main()
{
	test01();
	return 0;
}

