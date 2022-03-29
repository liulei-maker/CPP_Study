#pragma once

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<queue>
#include<map>
#include<set>
#include<algorithm>

using namespace std;

//定义huffman树的节点
typedef struct _TreeNode
{
	int _freq;
	string _value;
	_TreeNode *_leftChild, *_rightChild;
	_TreeNode(int freq = 0, string value = " ", _TreeNode *leftChild = NULL, _TreeNode *rightChild = NULL) :
		_freq(freq), _value(value), _leftChild(leftChild), _rightChild(rightChild) {};
}huffmanTreeNode, *pHuffmanTreeNode;

class SortIncrease
{
public:
	bool operator()(huffmanTreeNode* htTree1, huffmanTreeNode* htTree2)
	{
		return htTree1->_freq > htTree2->_freq;
	}
};

class Huffman
{
public:
	huffmanTreeNode* buildHuffmanTree(const string &str);
	map<string, string>  bulidHuffmanTabel(huffmanTreeNode *root);
	string huffmanEncode(string msgStr, map<string, string> huffmanCodeTable);
	string huffmanDecode(string huffmanCode, huffmanTreeNode *root);

private:
	void readStringToTable(string str, unordered_map<string, int> &_strHashTable);
	pair<string, int> returnMinPair(unordered_map<string, int> &_strHashTable);
	void _bulidHuffmanTabel(huffmanTreeNode *root, string codeLast);
	unordered_map<string, int> strHashTable;
	vector<huffmanTreeNode*> huffmanNodeVec;
	map<string, string> huffmanCodeTable;
};


huffmanTreeNode* Huffman::buildHuffmanTree(const string &str)
{
	huffmanTreeNode *root = NULL;
	readStringToTable(str, strHashTable);
	
	auto it1 = strHashTable.begin();
	while (it1 != strHashTable.end())
	{
		huffmanTreeNode *pt = new huffmanTreeNode(it1->second, it1->first);
		huffmanNodeVec.push_back(pt);

		//cout << "pt->_value:" << pt->_value << "  pt->_freq:" << pt->_freq << "\t" << pt << endl;
		it1++;
	}
	
	//显示容器中的内容
	sort(huffmanNodeVec.begin(), huffmanNodeVec.end(), SortIncrease());
	auto it2 = huffmanNodeVec.begin();
	while (it2 != huffmanNodeVec.end())
	{
		cout << "value:" << (*it2)->_value << "  freq:" << (*it2)->_freq << endl;
		it2++;
	}

	while (huffmanNodeVec.size() >= 2)
	{
		sort(huffmanNodeVec.begin(), huffmanNodeVec.end(), SortIncrease());
		auto it2 = huffmanNodeVec.end();
		huffmanTreeNode* leftNode = *(it2-1);
		huffmanTreeNode* rightNode = *(it2-2);
		huffmanNodeVec.pop_back();
		huffmanNodeVec.pop_back();
		huffmanTreeNode* parentNode = new huffmanTreeNode(leftNode->_freq + rightNode->_freq, leftNode->_value + rightNode->_value, leftNode, rightNode);
		huffmanNodeVec.push_back(parentNode);
	}
	root = huffmanNodeVec[0];
	return root;
}

void Huffman::_bulidHuffmanTabel(huffmanTreeNode *root, string codeLast)
{
	if (root == NULL)
		return;
	_bulidHuffmanTabel(root->_leftChild, codeLast + "0");
	if (root->_leftChild == NULL && root->_rightChild == NULL)
		huffmanCodeTable.insert(pair<string, string>(root->_value, codeLast));
	_bulidHuffmanTabel(root->_rightChild, codeLast + "1");
}
map<string, string> Huffman::bulidHuffmanTabel(huffmanTreeNode *root)
{
	_bulidHuffmanTabel(root, "");
	return huffmanCodeTable;
}

string Huffman::huffmanEncode(string msgStr, map<string, string> huffmanCodeTable)
{
	string huffmanCode = "";
	for (size_t i = 0; i < msgStr.length(); i++)
	{
		string strTemp = msgStr.substr(i, 1);
		huffmanCode = huffmanCode + (*huffmanCodeTable.find(strTemp)).second;
	}
	cout << huffmanCode << endl;

	return huffmanCode;
}
string Huffman::huffmanDecode(string huffmanCode, huffmanTreeNode *root)
{
	string orignStr;
	huffmanTreeNode *huffmanNode = root;
	for (int i = 0; i < huffmanCode.size(); i++)
	{
		if (huffmanCode[i] == '1')
			huffmanNode = huffmanNode->_rightChild;
		else
			huffmanNode = huffmanNode->_leftChild;
		if (huffmanNode->_rightChild == NULL && huffmanNode->_leftChild == NULL)
		{
			orignStr = orignStr + huffmanNode->_value;
			huffmanNode = root;
		}

	}
	return orignStr;
}

void Huffman::readStringToTable(string str, unordered_map<string, int> &_strHashTable)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		string strTemp = str.substr(i, 1);
		if (_strHashTable.find(strTemp) == _strHashTable.end())
			_strHashTable[strTemp] = 1;
		else
			_strHashTable[strTemp]++;
	}
	//for (unordered_map<char, int>::iterator it = _strHashTable.begin(); it != _strHashTable.end(); it++)
	//{
	//	cout << it->first << ":" << it->second << endl;
	//}
}

pair<string, int> Huffman::returnMinPair(unordered_map<string, int> &_strHashTable)
{
	string minFirst = _strHashTable.begin() ->first;
	int minSecond = _strHashTable.begin()->second;
	for (unordered_map<string, int>::iterator it = _strHashTable.begin(); it != _strHashTable.end(); it++)
	{
		if (it->second < minSecond)
		{
			minFirst = it->first;
			minSecond = it->second;
		}
	}
	_strHashTable.erase(minFirst);
	return pair<string, int>(minFirst, minSecond);
}