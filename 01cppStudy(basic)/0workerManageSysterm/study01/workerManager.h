#pragma once//��ֹͷ�ļ��ظ�����

#include<iostream>
#include<string>
#include<vector>
#include<fstream>

#include"boss.h"
#include"manager.h"
#include"employee.h"

using namespace std;

# define FILENAME "emFile.txt"

class workerManager
{
public:
	workerManager();
	~workerManager();
	
	void showMenu();
	void exitSystem();
	void save();
	int getEmpNum();
	void initWorker();


	void addEmp();
	void showWorkerInfo();

private:
	bool m_FileIsEmpty;		//�ж��ļ��Ƿ�Ϊ��

	int m_EmpNum;			//��ǰְ������
	worker** m_EmpArray;	//���Ա����Ϣ�Ķ���ָ��

};
