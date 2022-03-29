#include "employee.h"

employee::employee(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void employee::showInfo()
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << getDepName()
		<< "\t岗位职责：完成经理交代的任务！" << endl;
}

string employee::getDepName()
{
	return string("员工");
}