#include "competitorManage.h"


void createCompetitor(vector<Competitor>&v)
{
	vector<string> nameVector = { "����","����","����","��Ȩ","����","�ܲ�","���","����","����","�ŷ�","����","��ا" };
	for (int i = 0; i < 12; i++)
	{
		Competitor p(nameVector[i], i + 10001, 0);
		v.push_back(p);
	} 
}

void showMenu()
{
	cout << "*************************************************" << endl;
	cout << "************** ��ӭ�μ��ݽ����� *****************" << endl;
	cout << "*************** 1����ʼ�ݽ����� *****************" << endl;
	cout << "*************** 2���鿴�����¼ *****************" << endl;
	cout << "*************** 3����ձ�����¼ *****************" << endl;
	cout << "*************** 0���˳��������� *****************" << endl;
	cout << "*************************************************" << endl;
}

void startCompetition(vector<Competitor>&v)
{

}