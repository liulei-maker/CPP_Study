#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>
#include "BinaryTree.hpp"

using namespace std;


int main()
{
	int arr[10] = { 4,1,3,2,16,9,10,14,8,7 };
	int len = sizeof(arr) / sizeof(arr[0]);
	BinaryTree<int> binaryTree(arr, len);

	binaryTree.PostOrder();

	return 0;
}

