#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

class worker
{
public:
	virtual void showInfo() = 0;//��ʾ������Ϣ
	virtual string getDepName() = 0;//��ȡ��λ��Ϣ

	int m_Id;//ְ�����
	string m_Name;//ְ������
	int m_DeptId;//��λ���
};

