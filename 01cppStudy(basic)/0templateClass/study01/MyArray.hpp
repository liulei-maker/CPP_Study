#pragma once
#include<iostream>
#include<string>

using namespace std;

//模板类案例
//1、可以对内置的数据类型以及自定义数据类型的数据进行存储
//2、将数组中的数据存储到堆区
//3、构造函数中可以传入数组内容
//4、提供对应的拷贝构造函数以及防止operator=防止浅拷贝问题
//5、提供尾插法和尾删法对数组中的数据进行增加和删除
//6、可以通过下标的方式访问数组的内容
//7、可以获取数组中的当前元素的个数和数组的容量
template<class T>
class MyArray
{
public:
	//MyArray的普通构造函数
	MyArray(int capacity)
	{
		//cout << "MyArray的普通构造函数" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->m_Address = new T[this->m_Capacity];
	}
	//MyArray的拷贝构造函数
	MyArray(const MyArray &myarray)
	{
		//cout << "MyArray的拷贝构造函数" << endl;
		this->m_Capacity = myarray.m_Capacity;
		this->m_Size = myarray.m_Size; 
		this->m_Address = new T[this->m_Capacity];

		for (int i = 0; i < myarray.m_Size; i++)
		{
			this->m_Address[i] = myarray.m_Address[i];
		}
	}
	//MyArray的析构函数
	~MyArray()
	{
		//cout << "MyArray的析构函数" << endl;
		delete[] this->m_Address;
		this->m_Address = NULL;
	}
	//重载幅值=操作运算符
	MyArray& operator=(const MyArray &myarray)
	{
		if (this == &myarray)
		{
			//cout << "两个相同数据" << endl;
			return *this;
		}
		//cout << "重载幅值=操作运算符" << endl;
		if (this->m_Address != NULL)
		{
			this->m_Capacity = 0;
			this->m_Size = 0;
			delete[] this->m_Address;
		}

		this->m_Capacity = myarray.m_Capacity;
		this->m_Size = myarray.m_Size;
		this->m_Address = new T[this->m_Capacity];

		for (int i = 0; i < myarray.m_Size; i++)
		{
			this->m_Address[i] = myarray.m_Address[i];
		}
		return *this;
	}
	//尾插法
	void Push_back(T val)
	{
		if (this->m_Size == this->m_Capacity)
		{
			cout << "数组容量已满" << endl;
			return;
		}
		this->m_Address[this->m_Size] = val;
		this->m_Size++;
	}
	//尾删法
	void Pop_back()
	{
		if (this->m_Size == 0)
		{
			cout << "数组元素已满" << endl;
			return;
		}
		this->m_Address[this->m_Size - 1] = 0;
		this->m_Size--;
	}
	//通过下表的方式访问数组中的元素
	T& operator[](int index)
	{
		if (index < 0 || index >= this->m_Capacity)
		{
			cout << "访问空间出错" << endl;
		}
		else
		{
			return this->m_Address[index];
		}
	}
	//获取当前数组的元素个数
	int getSize()
	{
		return this->getSize;
	}
	//获取当前数组的容量
	int getCapacity()
	{
		return this->getCapacity;
	}

	//显示当前数组的数据
	void arrayPrint()
	{
		for (size_t i = 0; i < this->m_Size; i++)
		{
			cout << this->m_Address[i] << "  ";
		}
		cout << endl;
	}

private:
	T* m_Address;	//数组的首地址
	int m_Capacity;	//数组的容量
	int m_Size;		//数组当前元素的数量
};