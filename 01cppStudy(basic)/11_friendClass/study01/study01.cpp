﻿#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Building;
class goodGay
{
public:
	goodGay();
	void visit();//参观函数访问Builiding类中的属性
	Building *building;

};

class Building
{
	//告诉编译器goodGay是Building类的好朋友，可以访问Building类的私有内容
friend class goodGay;
public:
	Building();
public:
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
	cout << "好基友类正在访问： " << building->m_SittingRoom << endl;
	cout << "好基友类正在访问： " << building->m_BedRoom << endl;
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

