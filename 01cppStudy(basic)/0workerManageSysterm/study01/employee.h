#pragma once
#include"worker.h"

class employee : public worker
{
public:
	employee(int id, string name, int dId);

	virtual void showInfo();

	virtual string getDepName();
};

