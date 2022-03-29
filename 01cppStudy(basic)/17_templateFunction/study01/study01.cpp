#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//函数模板，将类型参数化

//函数注意事项
//1、自动类型推导，必须要推导出一致的数据类型T才能够确定
//2、模板必须确定T的类型数据，才可以使用
template<typename T> //声明一个函数模板，告诉编译器后面的代码中紧跟的T不要报错，T是一个通用的数据类型
//两个数据交换的函数
void mySwap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}


template<class T>
void sortFunc(T arr[], int len)
{
	for (int i = 0; i < len-1; i++)
	{
		for (int j = 0; j < len-i-1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				mySwap<char>(arr[j], arr[j + 1]);
			}
		}
	}
}

template<class T>
void printArr(T arr[], int len)
{
	for (size_t i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//普通函数与函数模板的区别
//1、普通函数调用可以发生隐式类型转换
//2、函数模板 用自动类型推导，不可以发生隐式类型转换
//3、函数模板 用显示指定类型，可以发生隐式类型转换
//普通函数
int myAdd01(int a, int b)
{
	return a + b;
}

//函数模板  用自动类型推导，不可以发生隐式类型转换
template<class T>
T myAdd02(T a, T b)
{
	return a + b;
}


void test01()
{
	char charArr[] = "asfhusdgfui";
	sortFunc<char>(charArr, sizeof(charArr));
	printArr<char>(charArr, sizeof(charArr));
}
int main()
{
	test01();
	return 0;
}

