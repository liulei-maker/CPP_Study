#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>
#include "BinarySearchTree.hpp"

using namespace std;


int main()
{
	vector<int>  numArr= { 4,1,3,2,16,9,10,14,8,7 };

	BinarySearchTree<int> binarySearchTree(numArr);
	binarySearchTree.InOrder();

	for (int i = 0; i < numArr.size(); i++)
	{
		if (binarySearchTree.deleteNode(numArr[i]))
			cout << "ok" << endl;
		else
			cout << "err" << endl;
		binarySearchTree.InOrder();

	}


	return 0;
}

