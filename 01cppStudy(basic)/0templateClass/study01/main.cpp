#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "MyArray.hpp"

using namespace std;

class Person
{
public:
	Person() {};
	Person(string name, int age)
	{
		this->m_age = age;
		this->m_name = name;
	}
	string m_name;
	int m_age;
};
void test()
{
	MyArray<Person> arr(10);
	Person p1("张三", 4);
	Person p2("李四", 24);
	Person p3("王五", 44);

	arr.Push_back(p1);
	arr.Push_back(p2);
	arr.Push_back(p3);

	cout << arr[2].m_age << "  " << arr[2].m_name << endl;
}

int main()
{
	test();
	return 0;
}

