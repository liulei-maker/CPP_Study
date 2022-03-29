#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class Person
{
public:
	Person(int age)
	{
		//m_Age = age;
		//指针指向的是 被调用成员函数 所属的对象
		this->age = age;
	}
	//要返回本体，要以引用（&）的方式进行返回，否则返回的是拷贝构造函数的备份
	Person& PersonAddAge(Person &p)
	{
		this->age = this->age + p.age;
		//指向的是对象本体
		return *this;
	}
	int age;
};

//1、解决名称冲突
void test01()
{
	Person p1(18);
	cout << "p1的age：" << p1.age << endl;
}
//2、返回对象本身用*this
void test02()
{
	Person p1(10);
	Person p2(10);
	//链式变成思想  可以无限的追加
	p2.PersonAddAge(p1).PersonAddAge(p1);
	//链式变成思想
	cout << "p2的age：" << p2.age << endl;
}

int main()
{
	test02();
	return 0;
}

