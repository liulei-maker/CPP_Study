#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Competitor
{
public:
	Competitor(string name, int num, double score)
	{
		this->m_name = name;
		this->m_num = num;
		this->m_score = score;
	}

	string m_name;	//参赛者的姓名
	int m_num;		//参赛者的编号
	double m_score;
};

