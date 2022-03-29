#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template<class T>
class Base
{
public:
	T m_mem;
};
//如果父类是一个类模板，子类需要指定父类的数据类型
template<class T1,class T2>
class Son :public Base<T1>
{
public:
	Son(T1 a, T2 b);
	T2 onj;
};
template<class T1, class T2>

Son<T1, T2>::Son(T1 a, T2 b)
{
	this->m_mem = a;
	this->onj;
}

void test01()
{
	Son<int, char> p(2,'d');
	cout << "p的大小：" << sizeof(p) << endl;
}

int main()
{
	test01();
	return 0;
}

