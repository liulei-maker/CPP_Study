#include <iostream>
#include <fstream>
#include <string>



int main()
{
	std::ofstream myfile("test.txt");
	for (int i = 0; i < 10; i++)
	{
		myfile << i << std::endl;
	}
	myfile.close();

	std::ifstream myInFile("test.txt");
	for (size_t i = 0; i < 10; i++)
	{
		char buffer[64] = { 0 };
		myInFile.getline(buffer, 64);
		std::cout << buffer << std::endl;
	}

	return 0;
}

