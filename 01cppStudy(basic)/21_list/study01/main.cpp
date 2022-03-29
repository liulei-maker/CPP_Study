#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>

using namespace std;

//STL中的链表是一个双向循环链表
//链表list的迭代器只支持前移和后移，属于双向迭代器
//list优点：1、采用动态存储分配，不会造成内存浪费和溢出   
//			2、链表执行插入和删除十分方便，只需要修改指针即可，不需要大量的移动
//list缺点：空间（指针域）和时间（遍历）额外耗费较大
class Person
{
public:
	Person(string name, int age, int height)
	{
		this->m_name = name;
		this->m_age = age;
		this->m_height = height;
	}

	string m_name;
	int m_age;
	int m_height;
};


void printList(const list<Person> &L)
{
	for (list<Person>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "name:" << it->m_name << "\tage:" << it->m_age << "\theight:" << it->m_height << endl;
	}
}

//回调函数，编辑排序规则
bool comparePerson(Person &p1, Person &p2)
{
	if (p1.m_age == p2.m_age)
	{
		return p1.m_height > p2.m_height;
	}
	else
	{
		return p1.m_age < p2.m_age;
	}
}
void test()
{
	list<Person>L;
	
	Person p1("关羽", 23, 167);
	Person p2("张飞", 21, 162);
	Person p3("刘备", 45, 170);
	Person p4("曹操", 35, 168);
	Person p5("孙权", 23, 180);
	Person p6("周瑜", 35, 190);
	Person p7("赵云", 23, 180);
	Person p8("黄盖", 35, 168);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);
	L.push_back(p7);
	L.push_back(p8);

	printList(L);
	cout << endl;

	L.sort(comparePerson);

	printList(L);
}

int main()
{
	test();
	return 0;
}

