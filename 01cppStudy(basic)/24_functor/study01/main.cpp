#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

//函数对象
//重载函数调用操作符的类，其对象称为函数对象
//函数对象使用重载的（）时  行为类似函数函数调用  也叫做仿函数
//函数对象时一个类  不是函数

//特点
//1、函数对象使用时，可以像普通函数那样调用，可以有参数，可以有返回值
//2、函数对象超出普通函数的概念，函数对象可以有自己的状态
//3、函数对象可以作为参数传递

//仿函数返回值是bool类型的时候   称为谓词
//一个参数称为一元谓词

class MyAdd
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}

	int count;
};
class MyPrint
{
public:
	MyPrint()
	{
		this->count = 0;
	}

	void operator()(string str)
	{
		cout << str << endl;
		this->count++;
	}
	int count;
};
void printStr(MyPrint &mp, string str)
{
	mp(str);
}

void test01()
{
	MyAdd myAdd;
	cout << myAdd(1, 4) << endl;

	MyPrint myPrint;
	printStr(myPrint, "hello world!");//类似于函数作为参数，进行参数传递


	cout << "myPrint调用次数：" << myPrint.count << endl;
}

class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};

class vectorSortDecrease
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};
void test02()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//查找容器是否有大于5的数字
	//GreaterFive（）匿名函数对象
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
	if (it != v.end())
	{
		cout << "找到了数字：" << *it << endl;
	}
}

void printf(const vector<bool>&v)
{
	for (vector<bool>::const_iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl;
}
void test03()
{
	vector<bool> v;

	v.push_back(3);
	v.push_back(0);
	v.push_back(7);
	v.push_back(3);
	v.push_back(5);
	v.push_back(0);

	//sort(v.begin(), v.end(), vectorSortDecrease());
	//sort(v.begin(), v.end(), greater<int>());

	transform(v.begin(), v.end(), v.begin(), logical_not<bool>());

	printf(v);

}
int main()
{
	test03();

	return 0;
}

