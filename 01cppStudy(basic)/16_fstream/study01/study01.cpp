#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main()
{
	ofstream ofs;
	ofs.open("test.txt",ios::out);

	ofs << "hello world!!!" << endl;
	ofs.close();

	return 0;
}

