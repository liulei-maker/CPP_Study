#pragma once

#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

/*AVL二叉树：平衡二叉树*/

/*****************************************************************
1、构造函数（递归）
2、拷贝构造函数（递归）
3、析构函数（递归）
4、赋值运算符重载（传统 / 现代）
5、前中后序遍历（递归 / 非递归）
6、层序遍历（非递归）
7、平衡第k层结点个数（递归）
8、精确平衡值为x的结点，并返回当前结点的指针（递归）
9、平衡叶子结点个数（递归）
10、平衡结点总个数（递归）
11、计算树的深度（递归）
*****************************************************************/

template <typename T>
struct BinaryTreeNode		//平衡二叉树的节点
{
	BinaryTreeNode<T> *_left;	//根节点的左子树
	BinaryTreeNode<T> *_right;	//根节点的右子树

	T _data;
	int height;
	BinaryTreeNode(T data = T()) :_left(NULL), _right(NULL), _data(data) ,height(0){}//节点的构造函数，T()为一个匿名对象
	//BinaryTreeNode(T data = T()) :_left(NULL), _right(NULL), _data(data), height(0) {}//节点的构造函数，T()为一个匿名对象
};

//Avl  平衡二叉树
template <typename T>
class BalancedBinarySearchTree
{
public:
	//BalancedBinarySearchTree的参数构造函数
	BalancedBinarySearchTree(const vector<T> &numArr);
	//BalancedBinarySearchTree的拷贝构造函数
	BalancedBinarySearchTree(const BalancedBinarySearchTree<T>& t);
	//BalancedBinarySearchTree的析构函数
	~BalancedBinarySearchTree();
	//重载赋值操作符，进行深拷贝
	BalancedBinarySearchTree<T>& operator=(BalancedBinarySearchTree<T> t);
	//前序遍历
	void PrevOrder();
	//中序遍历
	void InOrder();
	//后序遍历
	void PostOrder();
	//二叉平衡树中添加节点
	void addNode(const T &value);
	//查询节点  返回该节点的地址  若没有找到  则返回NULL
	const BinaryTreeNode<T> *searchNode(const T &value);
	//二叉平衡树中删除节点，若找到并且成功删除，则返回true 否则返回false
	bool  deleteNode(const T &value);
	//按照树状结构打印二叉平衡树
	void printTree();
	void printTree(BinaryTreeNode<T>* _root);
	//寻找最大值
	T findMaxValue(BinaryTreeNode<T>* _root);
	//寻找最小值
	T findMinValue(BinaryTreeNode<T>* _root);


	BinaryTreeNode<T> *root;	//树的根节点
	int nodeSize;				//树中节点的数目
private:
	//BinaryTreeNode赋值函数
	BinaryTreeNode<T>* _CopyTree(const BinaryTreeNode<T>* t);
		//添加平衡二叉树节点
	void _AddBinaryNode(BinaryTreeNode<T>* &root, const T value);
	//查询节点
	const BinaryTreeNode<T>* _searchNode(const BinaryTreeNode<T>* _root, const T &value);
	//删除节点
	bool  _deleteNode(BinaryTreeNode<T>* _parentRoot, BinaryTreeNode<T>* _root, const T value);
	//删除整棵二叉排序树
	void _Destroy(BinaryTreeNode<T>* t);
	//先序遍历
	void _PrevOrder(BinaryTreeNode<T>* _root);
	//中序遍历
	void _InOrder(BinaryTreeNode<T>* _root);
	//后序遍历
	void _PostOrder(BinaryTreeNode<T>* _root);
	//获取该节点的高度
	int _getHeight(BinaryTreeNode<T>* _root)
	{
		if (_root == NULL)
			return -1;
		else
			return _root->height;
	}
	//平衡整棵树的最小节点地址，即最左边节点
	BinaryTreeNode<T>* _minValue(BinaryTreeNode<T>* _root);
public:
	//当添加结点之后，导致节点左右不平衡，则需要旋转，分为以下四种情况
	void LL(BinaryTreeNode<int>* _root);
	void RR(BinaryTreeNode<int>* _root);
	void LR(BinaryTreeNode<int>* _root);
	void RL(BinaryTreeNode<int>* _root);

	//中序遍历返回节点数组
	vector<BinaryTreeNode<T> *> inorderTraversal(BinaryTreeNode<T> *_root);
};


template<class T>
BalancedBinarySearchTree<T>::BalancedBinarySearchTree(const vector<T> &numArr)
{
	this->root = NULL;
	for (int i = numArr.size()-1; i >=0 ; i--)
	{
		_AddBinaryNode(this->root, numArr[i]);
	}
}
//BalancedBinarySearchTree的拷贝构造函数
template<class T>
BalancedBinarySearchTree<T>::BalancedBinarySearchTree(const BalancedBinarySearchTree<T>& t)
{
	this->root = _CopyTree(t.root);
}
//BalancedBinarySearchTree的析构函数
template<class T>
BalancedBinarySearchTree<T>::~BalancedBinarySearchTree()
{
	_Destroy(this->root);
}
//重载赋值操作符，进行深拷贝
template<class T>
BalancedBinarySearchTree<T>& BalancedBinarySearchTree<T>::operator=(BalancedBinarySearchTree<T> t)
{
	if (this != &t)
	{
		std::swap(this->root, t.root);
	}

	return *this;
}
//前序遍历
template<class T>
void BalancedBinarySearchTree<T>::PrevOrder()
{
	_PrevOrder(this->root);
	cout << endl;
}
//中序遍历
template<class T>
void BalancedBinarySearchTree<T>::InOrder()
{
	_InOrder(this->root);
	cout << endl;
}
//后序遍历
template<class T>
void BalancedBinarySearchTree<T>::PostOrder()
{
	_PostOrder(this->root);
	cout << endl;
}
//二叉平衡树中添加节点
template<class T>
void BalancedBinarySearchTree<T>::addNode(const T &value)
{
	_AddBinaryNode(this->root, value);
}
//查询节点  返回该节点的地址  若没有找到  则返回NULL
template<class T>
const BinaryTreeNode<T>* BalancedBinarySearchTree<T>::searchNode(const T &value)
{
	return _searchNode(this->root, value);
}
//二叉平衡树中删除节点，若找到并且成功删除，则返回true 否则返回false
template<class T>
bool BalancedBinarySearchTree<T>::deleteNode(const T &value)
{
	this->nodeSize = 0;
	return _deleteNode(NULL, this->root, value);
}
//按照树状结构打印二叉平衡树
template<class T>
void BalancedBinarySearchTree<T>::printTree()
{
	if (!this->root)return;
	//if (this->root->_left == NULL && this->root->_right == NULL)
	//{
	//	cout << this->root->_data << ":" << this->root->height << endl;
	//	return;
	//}
	auto tmp = this->root;
	vector<BinaryTreeNode<T> *> intv = inorderTraversal(tmp);//中序遍历节点数组
	string template_str;//模板string，表示每行打印string的长度
	int location = 0;
	unordered_map<BinaryTreeNode<int>*, int> first_locations;//存储节点对应在本行string中的首位置
	for (auto &i : intv)
	{
		location = template_str.size();
		template_str += to_string(i->_data)+ " ";
		first_locations[i] = location;
	}
	for (auto &i : template_str)i = ' ';//把模板全部置为空格方便后续使用
	//层序遍历
	queue<BinaryTreeNode<T> *> q;
	q.push(root);
	while (!q.empty())
	{
		int currentLevelSize = q.size();
		int cur_loc = 0;
		string tmp_str1 = template_str, tmp_str2 = template_str;//1为节点所在行，2为其下一行
		for (int i = 1; i <= currentLevelSize; ++i)
		{
			auto node = q.front();
			q.pop();
			cur_loc = first_locations[node];
			string num_str = to_string(node->_data)+":"+ to_string(node->height);
			//左边，如果存在左孩子，那么在第二行对应位置打印'/'，在第一行补上'_'
			if (node->_left) {
				q.push(node->_left);
				int first_loc = first_locations[node->_left] + 1;
				tmp_str2[first_loc++] = '/';
				while (first_loc < cur_loc)tmp_str1[first_loc++] = '_';
			}
			//中间,对应位置打印节点值（有可能为多位数）
			for (int j = 0; j < num_str.length(); ++j, ++cur_loc) {
				tmp_str1[cur_loc] = num_str[j];
			}
			//右边，如果存在右孩子，那么在第二行对应位置打印'\'，在第一行补上'_'
			if (node->_right) {
				q.push(node->_right);
				int last_loc = first_locations[node->_right] - 1;
				tmp_str2[last_loc] = '\\';
				while (cur_loc < last_loc) {
					tmp_str1[cur_loc++] = '_';
				}
			}
		}
		//打印两行
		cout << tmp_str1 << endl;
		cout << tmp_str2 << endl;
	}
}
template<class T>
void BalancedBinarySearchTree<T>::printTree(BinaryTreeNode<T>* _root)
{
	if (!_root)return;
	auto tmp = _root;
	vector<BinaryTreeNode<T> *> intv = inorderTraversal(tmp);//中序遍历节点数组
	string template_str;//模板string，表示每行打印string的长度
	int location = 0;
	unordered_map<BinaryTreeNode<int>*, int> first_locations;//存储节点对应在本行string中的首位置
	for (auto &i : intv)
	{
		location = template_str.size();
		template_str += to_string(i->_data) + " ";
		first_locations[i] = location;
	}
	for (auto &i : template_str)i = ' ';//把模板全部置为空格方便后续使用
	//层序遍历
	queue<BinaryTreeNode<T> *> q;
	q.push(_root);
	while (!q.empty())
	{
		int currentLevelSize = q.size();
		int cur_loc = 0;
		string tmp_str1 = template_str, tmp_str2 = template_str;//1为节点所在行，2为其下一行
		for (int i = 1; i <= currentLevelSize; ++i)
		{
			auto node = q.front();
			q.pop();
			cur_loc = first_locations[node];
			string num_str = to_string(node->_data);
			//左边，如果存在左孩子，那么在第二行对应位置打印'/'，在第一行补上'_'
			if (node->_left) {
				q.push(node->_left);
				int first_loc = first_locations[node->_left] + 1;
				tmp_str2[first_loc++] = '/';
				while (first_loc < cur_loc)tmp_str1[first_loc++] = '_';

			}
			//中间,对应位置打印节点值（有可能为多位数）
			for (int j = 0; j < num_str.length(); ++j, ++cur_loc) {
				tmp_str1[cur_loc] = num_str[j];
			}
			//右边，如果存在右孩子，那么在第二行对应位置打印'\'，在第一行补上'_'
			if (node->_right) {
				q.push(node->_right);
				int last_loc = first_locations[node->_right] - 1;
				tmp_str2[last_loc] = '\\';
				while (cur_loc < last_loc) {
					tmp_str1[cur_loc++] = '_';
				}
			}
		}
		//打印两行
		cout << tmp_str1 << endl;
		cout << tmp_str2 << endl;
	}
}


//寻找最大值
template<class T>
T BalancedBinarySearchTree<T>::findMaxValue(BinaryTreeNode<T>* _root)
{
	if (_root->_right == NULL)
	{
		return _root->_data;
	}
	return findMaxValue(_root->_right);
}
//寻找最小值
template<class T>
T BalancedBinarySearchTree<T>::findMinValue(BinaryTreeNode<T>* _root)
{
	if (_root->_left == NULL)
	{
		return _root->_data;
	}
	return findMaxValue(_root->_left);
}


//BinaryTreeNode赋值函数
template<class T>
BinaryTreeNode<T>* BalancedBinarySearchTree<T>::_CopyTree(const BinaryTreeNode<T>* t)
{
	BinaryTreeNode<T>* _root = NULL;
	if (t == NULL)
	{
		return _root;
	}
	_root = new BinaryTreeNode<T>(t->_data);
	_root->_left = _CopyTree(t->_left);
	_root->_right = _CopyTree(t->_right);

	return _root;
}
//添加平衡二叉树节点
template<class T>
void BalancedBinarySearchTree<T>::_AddBinaryNode(BinaryTreeNode<T>* &_root, const T value)
{
	if (_root == NULL)//找到合适的位置进行插入  创建节点
	{
		nodeSize++;
		_root = new BinaryTreeNode<T>(value);
		return;
	}
	if (value < _root->_data)//当添加的值小于当前节点  向左进行插入操作
	{
		_AddBinaryNode(_root->_left, value);
	}
	else if (value >= _root->_data)//当添加的值大于当前节点  向右进行插入操作
	{
		_AddBinaryNode(_root->_right, value);
	}

	//回溯，判断走过的节点的是否平衡。如不平衡，加以调整
	if (_getHeight(_root->_left) - _getHeight(_root->_right) > 1)
		LL(_root);
	else if (_getHeight(_root->_right) - _getHeight(_root->_left) > 1)
		RR(_root);
	//调整走过的节点的高度位置
	_root->height = max(_getHeight(_root->_left), _getHeight(_root->_right)) + 1;
}
//查询节点
template<class T>
const BinaryTreeNode<T>* BalancedBinarySearchTree<T>::_searchNode(const BinaryTreeNode<T>* _root, const T &value)
{
	if (_root == NULL)
		return _root;
	if (_root->_data == value)
		return _root;
	else if (_root->_data > value)
		_searchNode(_root->_left, value);
	else
		_searchNode(_root->_right, value);
}
//删除节点
template<class T>
bool BalancedBinarySearchTree<T>::_deleteNode(BinaryTreeNode<T>* _parentRoot, BinaryTreeNode<T>* _root, const T value)
{
	bool flag = false;
	if (_root == NULL)//_root为空  未找到要删除的节点
		return false;
	//如果找到要删除的节点
	else if (_root->_data == value)
	{
		//判断左右子树是否为空  若为空  则使用较大子树的最大值代替
		if (_root->_left != NULL && _root->_right != NULL)
		{
			//判断较大子树
			if (_getHeight(_root->_left) > _getHeight(_root->_right))
			{
				_root->_data = findMaxValue(_root->_left);
				flag = _deleteNode(_root, _root->_left, _root->_data);
			}
			else
			{
				_root->_data = findMinValue(_root->_right);
				flag = _deleteNode(_root, _root->_right, _root->_data);
			}
		}
		else
		{
			//如果该节点的父母不为空，则需要先调整节点结构，再删除该节点
			if (_parentRoot != NULL)
			{
				if (_root == _parentRoot->_left)
					_parentRoot->_left = _root->_left ? _root->_left : _root->_right;
				else
					_parentRoot->_right = _root->_left ? _root->_left : _root->_right;
			}
			delete _root;
			this->root = NULL;
			return true;
		}
	}
	else if (value < _root->_data)//要删除的结点在左子树上
	{
		flag = _deleteNode(_root, _root->_left, value);
	}
	else//要删除的结点在右子树上
	{
		flag = _deleteNode(_root, _root->_right, value);
	}
	//回溯  调整节点的左右子树的平衡
	if (_getHeight(_root->_right) - _getHeight(_root->_left) > 1)
		RR(_root);

	if (_getHeight(_root->_left) - _getHeight(_root->_right) > 1)
		LL(_root);


	_root->height = max(_getHeight(_root->_left), _getHeight(_root->_right)) + 1;

	this->root = _root;

	return flag;
}
//删除整棵二叉排序树
template<class T>
void BalancedBinarySearchTree<T>::_Destroy(BinaryTreeNode<T>* t)
{
	BinaryTreeNode<T>* temp = t;
	if (temp == NULL)
		return;
	_Destroy(temp->_left);
	_Destroy(temp->_right);
	delete temp;
	temp = NULL;
}
//先序遍历
template<class T>
void BalancedBinarySearchTree<T>::_PrevOrder(BinaryTreeNode<T>* _root)
{
	BinaryTreeNode<T> *temp = _root;
	if (temp == NULL)
	{
		return;
	}
	cout << temp->_data << "  ";
	_PrevOrder(temp->_left);
	_PrevOrder(temp->_right);
}
//中序遍历
template<class T>
void BalancedBinarySearchTree<T>::_InOrder(BinaryTreeNode<T>* _root)
{
	BinaryTreeNode<T> *temp = _root;
	if (temp == NULL)
	{
		return;
	}
	_InOrder(temp->_left);
	cout << temp->_data << "  ";
	_InOrder(temp->_right);
}
//后序遍历
template<class T>
void BalancedBinarySearchTree<T>::_PostOrder(BinaryTreeNode<T>* _root)
{
	BinaryTreeNode<T> *temp = _root;
	if (temp == NULL)
	{
		return;
	}
	_PostOrder(temp->_left);
	_PostOrder(temp->_right);
	cout << temp->_data << "  ";
}
//平衡整棵树的最小节点地址，即最左边节点
template<class T>
BinaryTreeNode<T>* BalancedBinarySearchTree<T>::_minValue(BinaryTreeNode<T>* _root)
{
	if (_root->_left == NULL)
	{
		return _root;
	}
	return _minValue(_root->_left);
}
//当添加结点之后，导致节点左右不平衡，则需要旋转，分为以下四种情况
template<class T>
void BalancedBinarySearchTree<T>::LL(BinaryTreeNode<int>* _root)
{
	BinaryTreeNode<int>* _rootLeftTemp = _root->_left;
	swap(*_root, *_rootLeftTemp);
	_rootLeftTemp->_left = _root->_right;
	_root->_right = _rootLeftTemp;

	_rootLeftTemp->height = max(_getHeight(_rootLeftTemp->_right), _getHeight(_rootLeftTemp->_left)) + 1;
	_root->height = max(_getHeight(_root->_right), _getHeight(_root->_left)) + 1;
}
template<class T>
void BalancedBinarySearchTree<T>::RR(BinaryTreeNode<int>* _root)
{
	BinaryTreeNode<int>* _rootRightTemp = _root->_right;
	swap(*_root, *_rootRightTemp);
	_rootRightTemp->_right = _root->_left;
	_root->_left = _rootRightTemp;

	_rootRightTemp->height = max(_getHeight(_rootRightTemp->_right), _getHeight(_rootRightTemp->_left)) + 1;
	_root->height = max(_getHeight(_root->_right), _getHeight(_root->_left)) + 1;
}
template<class T>
void BalancedBinarySearchTree<T>::LR(BinaryTreeNode<int>* _root)
{
	RR(_root->_left);
	LL(_root);
}
template<class T>
void BalancedBinarySearchTree<T>::RL(BinaryTreeNode<int>* _root)
{
	LL(_root->_right);
	RR(_root);
}
//中序遍历返回节点数组
template<class T>
vector<BinaryTreeNode<T> *> BalancedBinarySearchTree<T>::inorderTraversal(BinaryTreeNode<T> *_root) 
{
	vector<BinaryTreeNode<T> *> res;
	stack<BinaryTreeNode<T> *> stk;
	while (_root != nullptr || !stk.empty())
	{  
		while (_root != nullptr)
		{
			stk.push(_root);
			_root = _root->_left;
		}
		_root = stk.top();
		stk.pop();
		res.push_back(_root);
		_root = _root->_right;
	}
	return res;
}