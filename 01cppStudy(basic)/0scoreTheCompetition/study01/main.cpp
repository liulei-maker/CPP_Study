#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;


class Competitor
{
public:
	Competitor(string name, double score)
	{
		this->m_name = name;
		this->m_score = score;
	}

	string m_name;
	double m_score;

};

void createCompetitor(vector<Competitor> &v)
{
	string str = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string str1 = "选手";
		string name = str1 + str[i];
		double score = 0;
		Competitor p(name, score);

		v.push_back(p);
	}
}

void printDeque(const deque<int> &d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << "\t" ;
	}
	cout << endl;
}

void setScore(vector<Competitor> &v)
{
	for (vector<Competitor>::iterator it = v.begin(); it != v.end(); it++)
	{
		deque<int> d;
		for (int i = 0; i < 10; i++)
		{
			int num = rand() % 41 + 60;
			d.push_back(num);
		}
		cout << "排序前分数情况：" << endl;
		printDeque(d);
		
		sort(d.begin(), d.end());//对打分进行排序
		cout << "排序后分数情况：" << endl;
		printDeque(d);

		d.pop_back();	//去掉最高分
		d.pop_front();	//去掉最低分

		int sum = 0;
		for (deque<int>::iterator it1 = d.begin(); it1 != d.end(); it1++)
		{
			sum = sum + (*it1);
		}
		double aver = sum / (double)d.size();

		it->m_score = aver;
	}
}
void printCompetitor(const vector<Competitor> &v)
{
	for (vector<Competitor>::const_iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "name: " << it->m_name << "\tscore: " << it->m_score << endl;
	}
	
}

int main()
{

	vector<Competitor> v;
	createCompetitor(v);
	setScore(v);
	printCompetitor(v);
	return 0;
}

