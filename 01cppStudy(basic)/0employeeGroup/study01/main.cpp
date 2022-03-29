#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <ctime>

using namespace std;

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

//创建员工类
class Employee
{
public:
	Employee() {};
	Employee(string name, int salary)
	{
		this->m_name = name;
		this->m_salary = salary;
	}
	string m_name;
	int m_salary;
};

//创建员工
void createEmployee(vector<Employee>&v)
{
	string nameSeed = "ABCDEFGHIJ";
	int i = 0;
	for (int i=0;i<10;i++)
	{
		Employee worker;
		worker.m_name = "员工";
		worker.m_name += nameSeed[i];
		worker.m_salary = rand() % 10000 + 10000;

		v.push_back(worker);
	}
}

void setEmployeeGroup(vector<Employee>&v, multimap<int, Employee>&s)
{
	for (vector<Employee>::iterator it = v.begin(); it != v.end(); it++)
	{
		int depID = rand() % 3;
		s.insert(make_pair(depID, *it));
	}
}

void showEmployeeGroup(multimap<int, Employee>&s)
{
	cout << "策划部门：" << endl;
	multimap<int, Employee>::iterator pos = s.find(CEHUA);
	int count = s.count(CEHUA);
	int index = 0;
	for (; pos != s.end() && index<count; pos++)
	{
		cout << "name:" << pos->second.m_name << "\tsalary:" << pos->second.m_salary << "\tgroup:" << pos->first << endl;
		index++;
	}

	cout << "美术部门：" << endl;
	pos = s.find(MEISHU);
	count = s.count(MEISHU);
	index = 0;
	for (; pos != s.end() && index < count; pos++)
	{
		cout << "name:" << pos->second.m_name << "\tsalary:" << pos->second.m_salary << "\tgroup:" << pos->first << endl;
		index++;
	}

	cout << "研发部门：" << endl;
	pos = s.find(YANFA);
	count = s.count(YANFA);
	index = 0;
	for (; pos != s.end() && index < count; pos++)
	{
		cout << "name:" << pos->second.m_name << "\tsalary:" << pos->second.m_salary << "\tgroup:" << pos->first << endl;
		index++;
	}
}

int main()
{
	srand((unsigned char)time(NULL));//每一次的随机数不相同
	vector<Employee>vWorker;
	multimap<int, Employee>mWorker;

	createEmployee(vWorker);

	setEmployeeGroup(vWorker, mWorker);

	showEmployeeGroup(mWorker);

	return 0;
}

