#pragma once//防止头文件重复包含

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
	bool m_FileIsEmpty;		//判断文件是否为空

	int m_EmpNum;			//当前职工数量
	worker** m_EmpArray;	//存放员工信息的二级指针

};
