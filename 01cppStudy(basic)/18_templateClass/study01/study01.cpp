#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//普通类的成员函数是一开始就创建了
//类模板的成员函数是调用时才创建

//类模板
//类模板不能够自动类型推导
//类模板在模板参数列表中可以有默认参数
template<class NameType,class AgeType = int>
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	void showPerson()
	{
		cout << "m_name:" << this->m_name << endl;
		cout << "m_age:" << this->m_age << endl;
	}
	NameType m_name;
	AgeType m_age;
};
//1、指定传入类型
void printPerson01(Person<string, int>&p)
{
	cout << "m_name:" << p.m_name << endl;
	cout << "m_age:" << p.m_age << endl;
}

//2、参数模板化
template<class T1,class T2>
void printPerson02(Person<T1, T2>&p)
{
	cout << "m_name:" << p.m_name << endl;
	cout << "m_age:" << p.m_age << endl;
}

//3、整个类模板化
template<class T>
void printPerson03(T &p)
{
	cout << "m_name:" << p.m_name << endl;
	cout << "m_age:" << p.m_age << endl;
	cout << "T:  " << typeid(T).name() << endl;
}

//类模板不能够自动类型推导
void test01()
{
	Person<string, int> p1("张三", 12);
	//p1.showPerson();
	//printPerson01(p1);
	//printPerson02<string, int>(p1);
	printPerson03<Person<string, int>>(p1);

}
//类模板在模板参数列表中可以有默认参数
void test02()
{
	Person<string> p1("李四", 19);
	p1.showPerson();
}

int main()
{
	test01();
	return 0;
}

