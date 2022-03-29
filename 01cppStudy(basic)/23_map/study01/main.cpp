#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

//map中的所有元素都是pair对组
//pair中的第一个元素为key（键值）起到索引的作用，第二个元素为value值（实值）
//所有的元素都会根据键值自动的排序

//map的本质都是属于关联式容器，底层都是由二叉树实现的

class Person
{
public:
	Person(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	string m_name;
	int m_age;
};

class MyCompare
{
public:
	bool operator()(const int &v1, const int &v2)
	{
		return v1 > v2;
	}
};

struct comparePerson
{
public:
	bool operator()(const Person &p1, const Person &p2)
	{
		return p1.m_age > p2.m_age;
	}
};
//map容器的排序
void test01()
{
	map<int, int, MyCompare>m;

	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));
	m.insert(make_pair(6, 50));

	for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key=" << it->first << "\tvalue=" << it->second << endl;
	}
}

void test02()
{
	map<Person, int, comparePerson>m;

	Person p1("刘备", 23);
	Person p2("孙权", 12);
	Person p3("孙策", 34);
	Person p4("周瑜", 42);
	Person p5("关羽", 17);


	m.insert(make_pair(p1, 1));
	m.insert(make_pair(p2, 2));
	m.insert(make_pair(p3, 3));
	m.insert(make_pair(p4, 4));
	m.insert(make_pair(p5, 5));

	for (map<Person, int, comparePerson>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key=" << it->second << "\tname=" << it->first.m_name << "\tage=" << it->first.m_age << endl;
	}
}
int main()
{
	test02();
	return 0;
}

