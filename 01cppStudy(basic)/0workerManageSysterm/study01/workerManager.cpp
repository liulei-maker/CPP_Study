#include "workerManager.h"

workerManager::workerManager()
{
	//�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;

		this->m_EmpNum = 0;	//��ʼ������Ϊ0
		this->m_EmpArray = NULL;//��ʼ��Ա������ΪNULL

		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	else//�ļ�����
	{
		char ch;
		ifs >> ch;//�ж��ļ��Ƿ�Ϊ��
		if (ifs.eof())//Ϊ��
		{
			cout << "�ļ�Ϊ��" << endl;

			this->m_EmpNum = 0;	//��ʼ������Ϊ0
			this->m_EmpArray = NULL;//��ʼ��Ա������ΪNULL

			this->m_FileIsEmpty = true;
			ifs.close();
			return;
		}
		else//��Ϊ��
		{
			int num = this->getEmpNum();
			this->m_EmpNum = num;
			cout << "ְ������Ϊ" << num << "��" << endl;
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
	cout << "************ ��ӭʹ��ְ������ϵͳ ***************" << endl;
	cout << "************ 0.�˳�����ϵͳ *********************" << endl;
	cout << "************ 1.����ְ����Ϣ *********************" << endl;
	cout << "************ 2.��ʾְ����Ϣ *********************" << endl;
	cout << "************ 3.ɾ��ְ����Ϣ *********************" << endl;
	cout << "************ 4.�޸�ְ����Ϣ *********************" << endl;
	cout << "************ 5.����ְ����Ϣ *********************" << endl;
	cout << "************ 6.���ձ������ *********************" << endl;
	cout << "************ 7.��������ĵ� *********************" << endl;
	cout << "*************************************************" << endl;
	cout << endl;
}

void workerManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
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
	cout << "����������ְ����������" << endl;

	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		int newSize = this->m_EmpNum + addNum;//�����¿ռ�Ĵ�С
		worker** newSpace = new worker*[newSize];//�����¿ռ�

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

			cout << "������" << i + 1 << "����Ա����ţ�" << endl;
			cin >> id;

			cout << "������" << i + 1 << "����Ա��������" << endl;
			cin >> name;

			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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
		cout << "��ӳɹ�" << addNum << "����Ա����" << endl;
	}
	else
	{
		cout << "��������" << endl;
	}
}

void workerManager::showWorkerInfo()
{
	for (size_t i = 0; i < this->m_EmpNum; i++)
	{
		this->m_EmpArray[i]->showInfo();
	}
}