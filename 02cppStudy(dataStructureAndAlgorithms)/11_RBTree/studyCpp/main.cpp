#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include "RedBlackTree.hpp"

using namespace std;


int main()
{
	vector<int>  numArr = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29};
	vector<int>  numArr1 = { 1,2 ,3,4,5,6};
	RedBlackTree<int> redBlackTree(numArr);
	redBlackTree.printTree();
	for (int i = 0; i < numArr1.size(); i++)
	{
		if (redBlackTree.deleteNode(numArr1[i]))
			cout << "sucessful" << endl;
		else
			cout << "faile" << endl;
	}


	redBlackTree.printTree();


	


	//for (auto it = numArr1.begin(); it != numArr1.end(); it++)
	//{
	//	cout << "value:" << *it;
	//	if (redBlackTree.deleteNode(*it))
	//		cout << "   success" << endl;
	//	else
	//		cout << "   error" << endl;
	//	redBlackTree.printTree();
	//}

	return 0;
}

