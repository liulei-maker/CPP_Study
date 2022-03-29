#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//创建配件的抽象类
//CPU抽象类
class CPU
{
public:
	virtual void calculate() = 0;
};
//显卡抽象类
class VideoCard
{
public:
	virtual void display() = 0;
};
//内存条抽象类
class Memory
{
public:
	virtual void storage() = 0;
};

//厂商实际的零配件
//IntelCPU
class IntelCPU : public CPU
{
	virtual void calculate()
	{
		cout << "IntelCPU开始计算" << endl;
	}
};
//Intel显卡
class IntelVideoCard : public VideoCard
{
	virtual void display()
	{
		cout << "Intel显卡开始显示" << endl;
	}
};

//Intel内存条
class IntelMemory : public Memory
{
	virtual void storage()
	{
		cout << "Intel内存条开始存储" << endl;
	}
};

//LenovoCPU
class LenovoCPU : public CPU
{
	virtual void calculate()
	{
		cout << "LenovoCPU开始计算" << endl;
	}
};
//Lenovo显卡
class LenovoVideoCard : public VideoCard
{
	virtual void display()
	{
		cout << "Lenovo显卡开始显示" << endl;
	}
};

//Lenovo内存条
class LenovoMemory : public Memory
{
	virtual void storage()
	{
		cout << "Lenovo内存条开始存储" << endl;
	}
};


class Computer
{
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem)
	{
		this->m_cpu = cpu;
		this->m_vc = vc;
		this->m_mem = mem;
	}
	void doWork()
	{
		this->m_cpu->calculate();
		this->m_vc->display();
		this->m_mem->storage();
	}
	~Computer()
	{
		delete m_cpu;
		delete m_vc;
		delete m_mem;
	}
private:
	CPU* m_cpu;
	VideoCard* m_vc;
	Memory* m_mem;
};
void test01()
{
	CPU* cpu = new IntelCPU;
	Memory* mem = new LenovoMemory;
	VideoCard* vc = new LenovoVideoCard;

	Computer* myComputer= new Computer(cpu, vc, mem);
	myComputer->doWork();

	delete myComputer;
}


int main()
{
	test01();

	return 0;
}

