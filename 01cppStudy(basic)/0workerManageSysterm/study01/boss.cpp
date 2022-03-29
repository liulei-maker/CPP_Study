#include "boss.h"

boss::boss(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void boss::showInfo()
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << getDepName()
		<< "\t岗位职责：管理公司所有事务！" << endl;
}

string boss::getDepName()
{
	return string("总裁");
}