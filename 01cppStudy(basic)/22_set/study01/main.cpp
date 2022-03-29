#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

class MyCompare//仿函数  自定义仿函数的排序规则
{
public:
	bool operator()(int num1, int num2)
	{
		return num1 > num2;
	}
};
class Person;

//自定义数据 
class Person
{
public:
	Person(string name, int age)
	{
		m_age = age;
		m_name = name;
	}
	string m_name;
	int m_age;
};
class ComparePerson
{
public:
	bool operator()(const Person &p1, const Person &p2)
	{
		return p1.m_age > p2.m_age;
	}
};
void printSet(const set<int, MyCompare>&s)
{
	for (set<int, MyCompare>::const_iterator it = s.begin(); it != s.end(); it++)
	{
		cout << (*it) << "\t";
	}
	cout << endl;
}
void printPersonSet(const set<Person, ComparePerson>&s)
{
	for (set<Person, ComparePerson>::const_iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "name:" << (*it).m_name << "\tage:" << (*it).m_age << endl;
	}
	cout << endl;
}
void test01()
{
	set<int, MyCompare>s;//自定义set中的排序规则

	s.insert(2);
	s.insert(7);
	s.insert(20);
	s.insert(17);
	s.insert(23);
	s.insert(1);

	printSet(s);
}

void test02()
{
	Person p1("关羽", 23);
	Person p2("刘备", 26);
	Person p3("孙权", 7);
	Person p4("曹操", 53);
	Person p5("刘备", 49);

	set<Person, ComparePerson>s;
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	s.insert(p5);

	printPersonSet(s);
}

int main()
{
	test02();

	return 0;
}

