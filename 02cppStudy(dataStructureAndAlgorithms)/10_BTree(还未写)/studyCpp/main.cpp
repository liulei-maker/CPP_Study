#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include "BalancedBinarySearchTree.hpp"

using namespace std;


int main()
{
	vector<int>  numArr= { 1,2,23,4,6,88,7,6,5,5,6,5};
	vector<int>  numArr1 = { 1,2 ,3,4,5,34,45,54,34,5,3,4,34,};
	BalancedBinarySearchTree<int> balancedBinarySearchTree(numArr);
	balancedBinarySearchTree.InOrder();
	balancedBinarySearchTree.printTree();
	for (auto it = numArr1.begin(); it != numArr1.end(); it++)
	{
		cout << "value:" << *it;
		if (balancedBinarySearchTree.deleteNode(*it))
			cout << "   success" << endl;
		else
			cout << "   error" << endl;
		balancedBinarySearchTree.printTree();
	}

	return 0;
}

