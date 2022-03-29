#pragma once
#include<iostream>
#include<string>

using namespace std;

//ģ���స��
//1�����Զ����õ����������Լ��Զ����������͵����ݽ��д洢
//2���������е����ݴ洢������
//3�����캯���п��Դ�����������
//4���ṩ��Ӧ�Ŀ������캯���Լ���ֹoperator=��ֹǳ��������
//5���ṩβ�巨��βɾ���������е����ݽ������Ӻ�ɾ��
//6������ͨ���±�ķ�ʽ�������������
//7�����Ի�ȡ�����еĵ�ǰԪ�صĸ��������������
template<class T>
class MyArray
{
public:
	//MyArray����ͨ���캯��
	MyArray(int capacity)
	{
		//cout << "MyArray����ͨ���캯��" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->m_Address = new T[this->m_Capacity];
	}
	//MyArray�Ŀ������캯��
	MyArray(const MyArray &myarray)
	{
		//cout << "MyArray�Ŀ������캯��" << endl;
		this->m_Capacity = myarray.m_Capacity;
		this->m_Size = myarray.m_Size; 
		this->m_Address = new T[this->m_Capacity];

		for (int i = 0; i < myarray.m_Size; i++)
		{
			this->m_Address[i] = myarray.m_Address[i];
		}
	}
	//MyArray����������
	~MyArray()
	{
		//cout << "MyArray����������" << endl;
		delete[] this->m_Address;
		this->m_Address = NULL;
	}
	//���ط�ֵ=���������
	MyArray& operator=(const MyArray &myarray)
	{
		if (this == &myarray)
		{
			//cout << "������ͬ����" << endl;
			return *this;
		}
		//cout << "���ط�ֵ=���������" << endl;
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
	//β�巨
	void Push_back(T val)
	{
		if (this->m_Size == this->m_Capacity)
		{
			cout << "������������" << endl;
			return;
		}
		this->m_Address[this->m_Size] = val;
		this->m_Size++;
	}
	//βɾ��
	void Pop_back()
	{
		if (this->m_Size == 0)
		{
			cout << "����Ԫ������" << endl;
			return;
		}
		this->m_Address[this->m_Size - 1] = 0;
		this->m_Size--;
	}
	//ͨ���±�ķ�ʽ���������е�Ԫ��
	T& operator[](int index)
	{
		if (index < 0 || index >= this->m_Capacity)
		{
			cout << "���ʿռ����" << endl;
		}
		else
		{
			return this->m_Address[index];
		}
	}
	//��ȡ��ǰ�����Ԫ�ظ���
	int getSize()
	{
		return this->getSize;
	}
	//��ȡ��ǰ���������
	int getCapacity()
	{
		return this->getCapacity;
	}

	//��ʾ��ǰ���������
	void arrayPrint()
	{
		for (size_t i = 0; i < this->m_Size; i++)
		{
			cout << this->m_Address[i] << "  ";
		}
		cout << endl;
	}

private:
	T* m_Address;	//������׵�ַ
	int m_Capacity;	//���������
	int m_Size;		//���鵱ǰԪ�ص�����
};