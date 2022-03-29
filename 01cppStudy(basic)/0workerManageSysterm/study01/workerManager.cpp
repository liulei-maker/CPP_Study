#include "workerManager.h"

workerManager::workerManager()
{
	//文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;

		this->m_EmpNum = 0;	//初始化人数为0
		this->m_EmpArray = NULL;//初始化员工数组为NULL

		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	else//文件存在
	{
		char ch;
		ifs >> ch;//判断文件是否为空
		if (ifs.eof())//为空
		{
			cout << "文件为空" << endl;

			this->m_EmpNum = 0;	//初始化人数为0
			this->m_EmpArray = NULL;//初始化员工数组为NULL

			this->m_FileIsEmpty = true;
			ifs.close();
			return;
		}
		else//不为空
		{
			int num = this->getEmpNum();
			this->m_EmpNum = num;
			cout << "职工个数为" << num << "个" << endl;
			this->m_EmpArray = new worker*[num];
			this->initWorker();
			this->showWorkerInfo();
		}
	}




}

workerManager::~workerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] m_EmpArray;
		m_EmpArray = NULL;
	}
}


void workerManager::showMenu()
{
	cout << "*************************************************" << endl;
	cout << "************ 欢迎使用职工管理系统 ***************" << endl;
	cout << "************ 0.退出管理系统 *********************" << endl;
	cout << "************ 1.增加职工信息 *********************" << endl;
	cout << "************ 2.显示职工信息 *********************" << endl;
	cout << "************ 3.删除职工信息 *********************" << endl;
	cout << "************ 4.修改职工信息 *********************" << endl;
	cout << "************ 5.查找职工信息 *********************" << endl;
	cout << "************ 6.按照编号排序 *********************" << endl;
	cout << "************ 7.清空所有文档 *********************" << endl;
	cout << "*************************************************" << endl;
	cout << endl;
}

void workerManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void workerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this -> m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << "  "
			<< this->m_EmpArray[i]->m_Name << "  "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}

int workerManager::getEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}

	ifs.close();

	return num;
}

void workerManager::initWorker()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		worker* myWorker = NULL;
		switch (dId)
		{
		case 1:
			myWorker = new employee(id, name, 1);
			break;
		case 2:
			myWorker = new manager(id, name, 2);
			break;
		case 3:
			myWorker = new boss(id, name, 3);
			break;

		default:
			break;
		}
		this->m_EmpArray[num] = myWorker;
		num++;
	}
}


void workerManager::addEmp()
{
	cout << "请输入增加职工的数量：" << endl;

	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		int newSize = this->m_EmpNum + addNum;//计算新空间的大小
		worker** newSpace = new worker*[newSize];//开辟新空间

		if (this->m_EmpArray != NULL)
		{
			for (size_t i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		for (size_t i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "请输入" << i + 1 << "个新员工编号：" << endl;
			cin >> id;

			cout << "请输入" << i + 1 << "个新员工姓名：" << endl;
			cin >> name;

			cout << "请选择该职工的岗位：" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;

			worker* myWorker = NULL;
			switch (dSelect)
			{
			case 1:
				myWorker = new employee(id, name, 1);
				break;
			case 2:
				myWorker = new manager(id, name, 2);
				break;
			case 3:
				myWorker = new boss(id, name, 3);
				break;

			default:
				break;
			}
			newSpace[this->m_EmpNum + i] = myWorker;
		}

		delete[] this->m_EmpArray;

		this->m_EmpArray = newSpace;

		this->m_EmpNum = newSize;

		this->save();
		cout << "添加成功" << addNum << "名新员工！" << endl;
	}
	else
	{
		cout << "输入有误！" << endl;
	}
}

void workerManager::showWorkerInfo()
{
	for (size_t i = 0; i < this->m_EmpNum; i++)
	{
		this->m_EmpArray[i]->showInfo();
	}
}