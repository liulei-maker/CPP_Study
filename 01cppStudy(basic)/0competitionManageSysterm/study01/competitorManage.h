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


void createCompetitor(vector<Competitor>&v);//创建比赛者
void showMenu();//显示选择菜单
void startCompetition(vector<Competitor>&v);//开始比赛
