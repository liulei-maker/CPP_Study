#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include"competitor.h"

using namespace std;

#define EXIT	0
#define START	1
#define QUERY	2
#define CLEAR	3


void createCompetitor(vector<Competitor>&v);//����������
void showMenu();//��ʾѡ��˵�
void startCompetition(vector<Competitor>&v);//��ʼ����
