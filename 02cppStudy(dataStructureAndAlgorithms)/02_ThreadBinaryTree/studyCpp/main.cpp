#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>

using namespace std;
//abc  d  e f  
//线索存储标志位
//Link(0)：表示指向左右孩子的指针
//Thread(1)：表示指向前驱后继的线索
typedef enum{ Link,Thread } PointTag;

struct BinaryNode
{
	BinaryNode *_leftChild;
	BinaryNode *_rightChild;
	PointTag _leftTag, _rightTag;
	BinaryNode() {};
	BinaryNode(char data) :_data(data), _leftChild(NULL), _rightChild(NULL) {}
	char _data;
};

BinaryNode* createBinaryTree()
{
	char c;
	BinaryNode* root = NULL;
	scanf("%c", &c);
	if (c != ' ')
	{
		root = new BinaryNode(c);
		root->_leftTag = Link;
		root->_rightTag = Link;
		root->_leftChild = createBinaryTree();
		root->_rightChild = createBinaryTree();
	}
	return root;
}

void perOrderSearch(BinaryNode *root)
{
	if (root != NULL)
	{
		cout << root->_data << " ";
		perOrderSearch(root->_leftChild);
		perOrderSearch(root->_rightChild);
	}
}
//使用中序遍历，使得二叉树索引化
BinaryNode* preNode;
BinaryNode* preTemp;

void inOrderSearch(BinaryNode *root)
{
	if (root != NULL)
	{
		inOrderSearch(root->_leftChild);

		cout << root->_data << " ";

		cout << "root:" << root << "    " << "*preTemp:" << preTemp << endl;
		if (root->_leftChild == NULL)
		{
			root->_leftTag = Thread;
			root->_leftChild = preTemp;
		}
		if (preTemp->_rightChild == NULL)
		{
			preTemp->_rightTag = Thread;
			preTemp->_rightChild = root;
		}
		preTemp = root;
		inOrderSearch(root->_rightChild);
	}
}
//abc  d  e f  
void inOrderThreading(BinaryNode *root)
{
	preTemp = new BinaryNode;
	preTemp->_leftTag = Link;
	preTemp->_rightTag = Thread;
	preTemp->_rightChild = NULL;

	if (root == NULL)
	{
		preTemp->_leftChild = preTemp;
	}
	else
	{
		preTemp->_leftChild = root;
		preNode = preTemp;

		cout << "*preTemp:" << preTemp << endl;
		cout << "preNode:" << preNode << endl << endl;

		inOrderSearch(root);
		preTemp->_rightTag = Thread;
		preTemp->_rightChild = preNode;
	}
}

void inOrderTarverse(BinaryNode *_preNodeRightChild)
{
	if (_preNodeRightChild == preNode)
		return;
	cout << _preNodeRightChild->_data << "  ";
	inOrderTarverse(_preNodeRightChild->_rightChild);
}


void postOrderSearch(BinaryNode *root)
{
	if (root != NULL)
	{
		postOrderSearch(root->_leftChild);
		postOrderSearch(root->_rightChild);
		cout << root->_data << " ";
	}
}

int main()
{
	BinaryNode* root = createBinaryTree();
	cout << "created sucessful" << endl;
	//cout << "先序遍历：" << endl;
	//perOrderSearch(root);
	//cout << endl;
	//pre = root;
	//cout << "中序遍历：" << endl;
	//inOrderSearch(root);
	//cout << endl;
	//cout << "后序遍历：" << endl;
	//postOrderSearch(root);
	//cout << endl;


	inOrderThreading(root);
	inOrderTarverse(preNode->_rightChild);

	//inOrderTarverse(preNode);

	return 0;
}

