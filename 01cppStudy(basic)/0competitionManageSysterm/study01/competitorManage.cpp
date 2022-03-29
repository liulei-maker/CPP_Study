#include "competitorManage.h"


void createCompetitor(vector<Competitor>&v)
{
	vector<string> nameVector = { "张三","李四","王五","孙权","刘备","曹操","周瑜","关羽","张良","张飞","赵云","曹丕" };
	for (int i = 0; i < 12; i++)
	{
		Competitor p(nameVector[i], i + 10001, 0);
		v.push_back(p);
	} 
}

void showMenu()
{
	cout << "*************************************************" << endl;
	cout << "************** 欢迎参加演讲比赛 *****************" << endl;
	cout << "*************** 1、开始演讲比赛 *****************" << endl;
	cout << "*************** 2、查看往届记录 *****************" << endl;
	cout << "*************** 3、清空比赛记录 *****************" << endl;
	cout << "*************** 0、退出比赛程序 *****************" << endl;
	cout << "*************************************************" << endl;
}

void startCompetition(vector<Competitor>&v)
{

}