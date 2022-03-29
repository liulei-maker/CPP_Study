/*如果有属性在堆区开辟的，一定要自己提供一个深拷贝构造函数，防止编译器自己的浅拷贝带来的问题*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//构造函数：默认构造函数（空语句）,有参构造函数，拷贝构造函数
//拷贝构造函数的调用时机
//1、使用一个已经创建完毕的对象来初始化另一个对象 
//2、值传递的方式给函数传值
//3、值方式返回局部对象
//默认构造函数、默认析构函数、默认拷贝构造函数（对属性进行拷贝）都由由编译器添加；如果有自己添加，则编译器不会再添加
class Person
{
public:
	Person()
	{
		cout << "Person 默认构造函数的调用" << endl;
	}
	~Person()
	{
		delete m_Height;
		cout << "Person 默认析构函数的调用" << endl;
	}
	Person(int age,int height)
	{
		cout << "Person调用有参构造函数" << endl;
		m_Height = new int(height);
		*m_Height = height;
		m_Age = age;
	}
	//在创建对象的时候，使用指针，在堆中开辟了空间，则使用拷贝构造函数的时候，就需要使用深拷贝，就是从新申请堆的空间
	Person(const Person &p)
	{
		cout << "Person调用拷贝构造函数" << endl;
		m_Height = new int(*p.m_Height);
		m_Age = p.m_Age;
		//m_Height = p.m_Height;
	}
	int m_Age;
	int *m_Height;

};
//拷贝构造函数的调用时机
//1、使用一个已经创建完毕的对象来初始化另一个对象
void test01()
{
	Person p1(20,160);
	Person p2(p1);
	cout << "p1的年龄：" << p1.m_Age << "   p1的身高：" << *p1.m_Height << endl;
	cout << "p2的年龄：" << p2.m_Age << "   p2的身高：" << *p2.m_Height << endl;
}
//2、值传递的方式给函数传值
void doWork(Person p)
{

}
void test02()
{
	Person p;
	doWork(p);
}
//3、值方式返回局部对象
Person dowork2()
{
	Person p1;
	//在返回p1时，做了一次拷贝构造，返回的是p1的副本
	return p1;
}
void test03()
{
	dowork2();
}
int main()
{
	test01();
	//test03();
	system("pause");
	return 0;
}