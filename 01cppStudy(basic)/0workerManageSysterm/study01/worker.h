#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

class worker
{
public:
	virtual void showInfo() = 0;//显示个人信息
	virtual string getDepName() = 0;//获取岗位信息

	int m_Id;//职工编号
	string m_Name;//职工姓名
	int m_DeptId;//岗位编号
};

