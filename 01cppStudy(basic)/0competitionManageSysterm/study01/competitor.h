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

	string m_name;	//�����ߵ�����
	int m_num;		//�����ߵı��
	double m_score;
};

