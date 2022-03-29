#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*运算符重载  实现自定义数据的算术运算*/

class Person
{
friend ostream& operator<< (ostream &cout, Person p);

public:
	Person() {};
	Person(int a, int b, int age)
	{
		m_A = a;
		m_B = b;
		m_Age = new int(age);
	};
	//利用成员函数来重载运算符
	Person operator+ (Person &p)
	{
		Person pTemp;
		pTemp.m_A = this->m_A + p.m_A;   
		pTemp.m_B = this->m_B + p.m_B;
		return pTemp;
	}
	//前置递增   ++Person
	Person& operator++ ()
	{
		this->m_A++;		
		this->m_B++;
		return *this;
	}
	//后置递增   Person++
	Person operator++(int)
	{
		Person pTemp = *this;
		this->m_A++;
		this->m_B++;
		return pTemp;
	}
	//赋值运算符重载
	Person& operator=(Person &p)
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
		m_Age = new int(*p.m_Age);
		m_A = p.m_A;
		m_B = p.m_B;

		return *this;
	}
	//逻辑等于运算符重载
	bool operator==(Person &p)
	{
		if (m_A == p.m_A && m_B == p.m_B && *m_Age == *p.m_Age)
		{
			return true;
		}
		return false;
	}
	//逻辑不等于运算符重载
	bool operator!=(Person &p)
	{
		if (m_A == p.m_A && m_B == p.m_B && *m_Age == *p.m_Age)
		{
			return false;
		}
		return true;
	}
	//重载函数调用运算符，仿函数
	void operator()(string str)
	{
		cout << str << endl;
	}
	//析构函数
	~Person()
	{
		delete m_Age;
	}
private:
	int m_A;
	int m_B;
public:
	int *m_Age;
};

//全局函数做运算符重载
//Person operator+ (Person &p1,Person p2)
//{
//	Person pTemp;
//	pTemp.m_A = p1.m_A + p2.m_A;
//	pTemp.m_B = p1.m_B + p2.m_B;
//	return pTemp;
//}

ostream& operator<< (ostream &cout, Person p)
{
	cout << "m_A:" << p.m_A << "  m_B:" << p.m_B;
	return cout;
}


int main()
{
	Person p1(10, 10, 10);
	Person p2(10, 20, 30);
	Person p3(10, 20, 60);

	//p2 = p1 = p3;

	//cout << "p1的年龄为：" << *p1.m_Age << endl;
	//cout << "p2的年龄为：" << *p2.m_Age << endl;

	if (p1 != p2)
	{
		cout << "p1等于p2" << endl;
	}
	p1("hello world");
	return 0;
}

