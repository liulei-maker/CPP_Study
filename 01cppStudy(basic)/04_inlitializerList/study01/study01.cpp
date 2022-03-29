#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Person
{
public:
	//Person(int a, int b, int c)
	//{
	//	m_A = a;
	//	m_B = b;
	//	m_C = c;
	//}
	//初始化列表初始化属性
	Person(int a, int b, int c) :m_A(a), m_B(b), m_C(c)
	{

	}
	int m_A;
	int m_B;
	int m_C;
};

int main()
{
	Person p(12, 23, 34);
	cout << "p.m_A:" << p.m_A << "  p.m_B:" << p.m_B << "  p.m_C:" << p.m_C << endl;

	return 0;
}

