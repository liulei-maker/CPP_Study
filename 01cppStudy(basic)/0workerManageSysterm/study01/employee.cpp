#include "employee.h"

employee::employee(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void employee::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << getDepName()
		<< "\t��λְ����ɾ�����������" << endl;
}

string employee::getDepName()
{
	return string("Ա��");
}