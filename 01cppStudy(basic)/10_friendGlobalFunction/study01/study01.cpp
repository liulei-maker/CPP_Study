#include <iostream>
#include <fstream>
#include <string>

using namespace std;
/*全局函数做友元*/

//建筑物类
class Building
{
	//告诉编译器  goodGay全局函数是Building类的好朋友，可以访问类的私有内容
friend	void goodGay(Building * building);/*全局函数做友元*/
public:
	Building()
	{
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";
	}
public:
	string m_SittingRoom;
private:
	string m_BedRoom;
};

//全局函数
void goodGay(Building * building)
{
	cout << "好基友全局函数正在访问： " << building->m_SittingRoom << endl;
	cout << "好基友全局函数正在访问： " << building->m_BedRoom << endl;
}


void test01()
{
	Building building;
	goodGay(&building);
}



int main()
{
	test01();
	return 0;
}

