#include "manager.h"

manager::manager(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void manager::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << getDepName()
		<< "\t��λְ������ϰ彻�������񣬲��·������Ա����" << endl;
}

string manager::getDepName()
{
	return string("����");
}