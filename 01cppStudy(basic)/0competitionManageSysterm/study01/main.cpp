#include"competitorManage.h"


int main()
{
	vector<Competitor> vCompetitor;	//创建装载比赛者的容器

	createCompetitor(vCompetitor);//创建比赛者的信息
	while (true)
	{
		showMenu();//显示菜单
		int select;
		cout << "请输入选择：" << endl;
		cin >> select;

		switch (select)
		{
		case EXIT:cout << "比赛结束" << endl;
			break;
		case START:startCompetition(vCompetitor);
		}

	}
	


	return 0;
}

