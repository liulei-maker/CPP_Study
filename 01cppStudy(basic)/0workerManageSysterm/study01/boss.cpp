#include "boss.h"

boss::boss(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void boss::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << getDepName()
		<< "\t��λְ�𣺹���˾��������" << endl;
}

string boss::getDepName()
{
	return string("�ܲ�");
}