#include "manager.h"

manager::manager(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void manager::showInfo()
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << getDepName()
		<< "\t岗位职责：完成老板交代的任务，并下发任务给员工！" << endl;
}

string manager::getDepName()
{
	return string("经理");
}