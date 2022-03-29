#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class Animal
{
public:
	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}
};

class Cat : public Animal
{
public:
	void speak()
	{
		cout << "小猫在说话" << endl;
	}
};

class Dog : public Animal
{
public:
	void speak()
	{
		cout << "小狗在说话" << endl;
	}
};

void animalSpeak(Animal &animal)
{
	animal.speak();
}

void test01()
{
	Cat c;
	animalSpeak(c);

	Dog d;
	animalSpeak(d);
}

int main()
{
	Animal* cat = new Cat;
	cat->speak();
	return 0;
}

