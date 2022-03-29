#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

//普通函数
void print01(int val)
{
	cout << val << "  ";
}

class printf02
{
public:
	void operator()(int val)
	{
		cout << val << "  ";
	}
};
void test01()
{
	vector<int> v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), printf02());
}
int main()
{
	test01();
	fill();

	return 0;
}

