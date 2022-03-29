#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include"Huffman.hpp"

using namespace std;


int main()
{
	Huffman huffman;
	string orignStr = "abbsfsdfsdsahcccsfsdbbsbabdbabdbexafsdfccddsdwfddddddd";
	huffmanTreeNode *root=huffman.buildHuffmanTree(orignStr);
	map<string, string>huffmanCodeTable = huffman.bulidHuffmanTabel(root);
	string huffmanenCode = huffman.huffmanEncode(orignStr, huffmanCodeTable);
	string huffmanDecode = huffman.huffmanDecode(huffmanenCode, root);
	cout << orignStr << endl;
	cout << huffmanDecode << endl;
	
	return 0;
}

