#pragma once

#include"worker.h"

class boss : public worker
{
public:
	boss(int id, string name, int dId);

	virtual void showInfo();

	virtual string getDepName();
};
