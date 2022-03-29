#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}

	string m_name;
	int m_age;
};
void printDeque(const deque<int> &d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << (*it) << "\t";
	}
	cout << endl;
}

void test()
{
	deque<int> d1;
	d1.push_back(1);
	d1.push_back(-1);
	d1.push_back(3);
	d1.push_back(2);
	d1.push_back(7);
	d1.push_back(3);

	sort(d1.begin(), d1.end());

	printDeque(d1);
}



int main()
{
	test();

	return 0;
}

