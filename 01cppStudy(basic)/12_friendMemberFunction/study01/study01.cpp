#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Building;

class goodGay
{
public:
	goodGay();
	void visit();//让visit函数可以访问building中的私有成员
	void visit2();//让visit函数不可以访问building中的私有成员

	Building *building;
};

class Building
{
	//告诉编译器goodGay下的成员函数作为Building类的好朋友  可以访问私有的成员
friend void goodGay::visit();
public:
	Building();
	string m_SittingRoom;

private:
	string m_BedRoom;
};

Building::Building()
{
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}

goodGay::goodGay()
{
	building = new Building;
}

void goodGay::visit()
{
	cout << "visit函数正在访问： " << building->m_SittingRoom << endl;
	cout << "visit函数正在访问： " << building->m_BedRoom << endl;
}

void goodGay::visit2()
{
	cout << "visit2函数正在访问： " << building->m_SittingRoom << endl;
}
void test01()
{
	goodGay gg;
	gg.visit();
}
int main()
{
	test01();
	return 0;
}

