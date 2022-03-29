#include <iostream>
#include <fstream>
#include <string>

using namespace std;
/****************************************************************************************	
	编译器将使用C++的动态绑定 （dynamic binding） 特性， 确定图形指针具体指向哪一个对象，
	调用合适虚方法，只有将方法声明为虚方法，才能够通过指针或者引用访问才能够使用动态绑定
****************************************************************************************/
class CFigure
{
public:
	CFigure() {};
	~CFigure() {};
	virtual string figureType() = 0;//纯虚函数，含有纯虚函数的类叫做抽象类  不能够使用抽象类创建对象
	virtual double circumference() = 0;
	virtual double area() = 0;
private:

};

class CTriangle : public CFigure
{
public:
	CTriangle()
	{
		a = 0; b = 0; c = 0;
	}
	CTriangle(double a, double b, double c) :a(a), b(b), c(c) {}
	virtual string figureType()
	{
		return "Triangle";
	}
	virtual double circumference()
	{
		return a + b + c;
	}
	virtual double area()
	{
		double S = circumference() / 2;
		return sqrt(S*(S - a)*(S - b)*(S - c));
	}

private:
	double a, b, c;
};

class CCircle : public CFigure
{
public:
	CCircle()
	{
		r = 0;
	}
	CCircle(double r) :r(r) {}
	virtual string figureType()
	{
		return "Circle";
	}
	virtual double circumference()
	{
		return 2 * 3.14159 * r;
	}
	virtual double area()
	{
		return 3.14159 * r * r;
	}

private:
	double r;
};
int main()
{
	CFigure* myFigure[2];
	myFigure[0] = new CTriangle(1, 2, 3);
	myFigure[1] = new CCircle(2);
	for (size_t i = 0; i < 2; i++)
	{
		cout << myFigure[i]->figureType() << "  " << myFigure[i]->area() << "  " << myFigure[i]->circumference() << endl;
	}
	
	return 0;
}

