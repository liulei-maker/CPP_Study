#pragma once

#include"worker.h"

class manager:public worker
{
public:
	manager(int id, string name, int dId);

	virtual void showInfo();

	virtual string getDepName();
};

