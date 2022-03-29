#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//成员变量和成员函数是分开存储的
class Person
{
	int m_A;//非静态成员变量   属于类的对象上
	static int m_B;//静态成员变量  不属于类的对象上
	void func()//非静态成员函数  不属于类的对象上
	{

	}
};
int Person::m_B = 0;//静态的成员变量需要类外初始化
void test01()
{
	Person p;
	//空的对象占用的内存空间是：1byte
	//C++编译器会给每一个空对象分配一个字节的空间，是为了区分空对象占内存的位置
	//每一个空对象也应该一个独一无二的的内存空间
	cout << "size of p:" << sizeof(p) << endl;
	
}
void test02()
{

}
int main()
{
	test01();
	return 0;
}

