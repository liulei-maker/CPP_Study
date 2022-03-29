#pragma once

#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<unordered_map>

using namespace std;

/*****************************************************************
************************      红黑树      ************************
(1) 每个节点或者是黑色，或者是红色。
(2) 根节点是黑色。
(3) 每个叶子节点是黑色。[注意：这里叶子节点，是指为空的叶子节点！]
(4) 如果一个节点是红色的，则它的子节点必须是黑色的。
(5) 从一个节点到该节点的子孙节点的所有路径上包含相同数目的黑节点。

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

typedef enum {BLACK, RED} COLOR;
vector<string> redBlackWorf = { "黑","红" };
template <typename T>
//红黑树的节点
struct RBTreeNode
{
	RBTreeNode<T> *_left;	//根节点的左节点
	RBTreeNode<T> *_right;	//根节点的右节点
	RBTreeNode<T> *_parent; //根节点的父节点

	T _data;					//节点的数据
	COLOR _color;				//节点的颜色

	RBTreeNode(T data) :_left(NULL), _right(NULL), _parent(NULL), _data(data) , _color(RED){}//节点的构造函数，T()为一个匿名对象
	RBTreeNode(T data, RBTreeNode<T> *left, RBTreeNode<T> *right, RBTreeNode<T> *parent, COLOR color) :
		_left(left), _right(right), _parent(parent), _data(data), _color(color) {}//节点的构造函数，T()为一个匿名对象
};

//RBTree 红黑树
template <typename T>
class RedBlackTree
{
public:
	/***************   构造函数   ***************/
	//RedBlackTree的无参构造函数
	RedBlackTree() {}
	//RedBlackTree的参数构造函数
	RedBlackTree(const vector<T> &numArr);
	//RedBlackTree的拷贝构造函数
	RedBlackTree(const RedBlackTree<T>& t);

	/***************   析构函数   ***************/
	//RedBlackTree的析构函数
	~RedBlackTree();

	/***************  运算符重载  ***************/
	//重载赋值操作符，进行深拷贝
	RedBlackTree<T>& operator=(RedBlackTree<T> tree);
	
	/***************  红黑树遍历  ***************/
	//前序遍历
	void PrevOrder();
	//中序遍历
	void InOrder();
	//后序遍历
	void PostOrder();

	/***************  红黑树添加、删除、查找  ***************/
	//红黑树中添加节点
	void addNode(const T &value);
	//红黑树中删除节点，若找到并且成功删除，则返回true 否则返回false
	bool deleteNode(const T &value);
	//删除整棵红黑树
	void deleteTree();
	//查询节点  返回该节点的地址  若没有找到  则返回NIL
	RBTreeNode<T> *searchNode(const T &value);

	/***************  红黑树打印  ***************/
	//按照树状结构打印红黑树
	void printTree();

	/***************  红黑树最值查找  ***************/
	//寻找最大值
	T findMaxValue(RBTreeNode<T>* _root);
	//寻找最小值
	T findMinValue(RBTreeNode<T>* _root);
	RBTreeNode<T>* treeMaximum(RBTreeNode<T>* _root);
	RBTreeNode<T>* treeMinimum(RBTreeNode<T>* _root);

	RBTreeNode<T> *root;	//树的根节点
	RBTreeNode<T> *nil;		//树的外部
	int nodeSize;			//树中节点的数目
private:
	//RBTreeNode拷贝函数
	void _CopyTree(const RBTreeNode<T>* _root, const RBTreeNode<T>* _nil, 
		RBTreeNode<T>* _p, RBTreeNode<T>* &_t, RBTreeNode<T>* _n);

	//添加红黑树节点
	void _AddBinaryNode(RBTreeNode<T>* &_parent, RBTreeNode<T>* &_root, const T value);
	void _RBAddFixup(RBTreeNode<T>* _rootZ);
	//查询节点
	RBTreeNode<T>* _searchNode(RBTreeNode<T>* _root, const T &value);
	//删除节点
	bool  _deleteNode(RBTreeNode<T>* _root, RBTreeNode<T>* _searchNodeRoot);
	void _RBDeleteFixup(RBTreeNode<T>* _rootZ);

	//删除整棵二叉排序树
	void _Destroy(RBTreeNode<T>* &t);
	//先序遍历
	void _PrevOrder(RBTreeNode<T>* _root);
	//中序遍历
	void _InOrder(RBTreeNode<T>* _root);
	//后序遍历
	void _PostOrder(RBTreeNode<T>* _root);

	//左右旋转操作
	void rightRotate(RBTreeNode<int>* _root);
	void leftRotate(RBTreeNode<int>* _root);


	//前驱 后继
	RBTreeNode<int>* treePredecessor(RBTreeNode<int>* _root);	//前驱
	RBTreeNode<int>* treeSuccessor(RBTreeNode<int>* _root);		//后继

	//返回节点的亲戚
	RBTreeNode<int>* grandparent(RBTreeNode<int>* _root)
	{
		return _root->_parent->_parent;
	}	
	RBTreeNode<int>* parent(RBTreeNode<int>* _root)
	{
		return _root->_parent;
	}	
	RBTreeNode<int>* rightUncle(RBTreeNode<int>* _root)
	{
		return _root->_parent->_parent->_right;
	}	
	RBTreeNode<int>* leftUncle(RBTreeNode<int>* _root)
	{
		return _root->_parent->_parent->_left;
	}
	RBTreeNode<int>* leftChild(RBTreeNode<int>* _root)
	{
		return _root->_left;
	}
	RBTreeNode<int>* rightChild(RBTreeNode<int>* _root)
	{
		return _root->_right;
	}
	RBTreeNode<int>* leftBrother(RBTreeNode<int>* _root)
	{
		return _root->_parent->_left;
	}
	RBTreeNode<int>* rightBrother(RBTreeNode<int>* _root)
	{
		return _root->_parent->_right;
	}
	
	
	//中序遍历返回节点数组
	vector<RBTreeNode<T> *> inorderTraversal(RBTreeNode<T> *_root);
};

/***********************类的构造函数**************************/
template<class T>
RedBlackTree<T>::RedBlackTree(const vector<T> &numArr)
{
	this->nil = new RBTreeNode<T>(0, NULL, NULL, NULL, BLACK);
	this->root = this->nil;

	for (int i = 0; i < numArr.size(); i++)
	{
		_AddBinaryNode(this->nil, this->root, numArr[i]);
	}
}
//RedBlackTree的拷贝构造函数
template<class T>
RedBlackTree<T>::RedBlackTree(const RedBlackTree<T>& tree)
{
	this->nil = new RBTreeNode<T>(0, NULL, NULL, NULL, BLACK);
	this->root = this->nil;
	_CopyTree(tree.root, (tree.root)->_parent, this->nil, this->root, this->nil);
}
//RedBlackTree的析构函数

/***********************类的析构函数**************************/
template<class T>
RedBlackTree<T>::~RedBlackTree()
{
	_Destroy(this->root);
	if (!this->nil)
	{
		delete this->nil;
		this->nil = NULL;
	}	
	nodeSize = 0;
}

//重载赋值操作符，进行深拷贝
template<class T>
RedBlackTree<T>& RedBlackTree<T>::operator=(RedBlackTree<T> tree)
{
	if (this != &tree)
	{
		deleteTree();
		this->nil = new RBTreeNode<T>(0, NULL, NULL, NULL, BLACK);
		this->root = this->nil;
		_CopyTree(tree.root, (tree.root)->_parent, this->nil, this->root, this->nil);
	}

	return *this;
}
//RBTreeNode拷贝函数
template<class T>
void RedBlackTree<T>::_CopyTree(const RBTreeNode<T>* _root, const RBTreeNode<T>* _nil, RBTreeNode<T>* _p, RBTreeNode<T>* &_t, RBTreeNode<T>* _n)
{
	if (_root == _nil)
		return;

	_t = new RBTreeNode<T>(_root->_data, _n, _n, _p, _root->_color);
	_CopyTree(_root->_left, _nil, _t, _t->_left, _n);
	_CopyTree(_root->_right, _nil, _t, _t->_right, _n);
}

//前序遍历
template<class T>
void RedBlackTree<T>::PrevOrder()
{
	_PrevOrder(this->root);
	cout << endl;
}
//中序遍历
template<class T>
void RedBlackTree<T>::InOrder()
{
	_InOrder(this->root);
	cout << endl;
}
//后序遍历
template<class T>
void RedBlackTree<T>::PostOrder()
{
	_PostOrder(this->root);
	cout << endl;
}
//红黑树中添加节点
template<class T>
void RedBlackTree<T>::addNode(const T &value)
{
	_AddBinaryNode(this->root, value);
}
//查询节点  返回该节点的地址  若没有找到  则返回NULL
template<class T>
RBTreeNode<T>* RedBlackTree<T>::searchNode(const T &value)
{
	RBTreeNode<T>* _searchNodeRoot = _searchNode(this->root, value);
	if (_searchNodeRoot == this->nil)
		return NULL;
	else
		return _searchNodeRoot;		
}
//红黑树中删除节点，若找到并且成功删除，则返回true 否则返回false
template<class T>
bool RedBlackTree<T>::deleteNode(const T &value)
{
	RBTreeNode<T>* _searchNodeRoot = _searchNode(this->root, value);
	if (_searchNodeRoot == this->nil)
		return false;

	this->nodeSize--;

	return _deleteNode(this->root, _searchNodeRoot);
}
//删除整棵红黑树
template<class T>
void RedBlackTree<T>::deleteTree()
{
	_Destroy(this->root);
	if (!this->nil)
	{
		delete this->nil;
		this->nil = NULL;
	}
	nodeSize = 0;
}

//寻找最大值
template<class T>
T RedBlackTree<T>::findMaxValue(RBTreeNode<T>* _root)
{
	if (_root->_right == this->nil)
	{
		return _root->_data;
	}
	return findMaxValue(_root->_right);
}
//寻找最小值
template<class T>
T RedBlackTree<T>::findMinValue(RBTreeNode<T>* _root)
{
	if (_root->_left == this->nil)
	{
		return _root->_data;
	}
	return findMinValue(_root->_left);
}
//寻找最大值节点的地址
template<class T>
RBTreeNode<T>* RedBlackTree<T>::treeMaximum(RBTreeNode<T>* _root)
{
	if (_root->_right == this->nil)
	{
		return _root;
	}
	return findMaxValue(_root->_right);
}
//寻找最小值节点的地址
template<class T>
RBTreeNode<T>* RedBlackTree<T>::treeMinimum(RBTreeNode<T>* _root)
{
	if (_root->_left == this->nil)
	{
		return _root;
	}
	return treeMinimum(_root->_left);
}

/***************************增删查红黑树***************************/
//添加红黑树节点
template<class T>
void RedBlackTree<T>::_AddBinaryNode(RBTreeNode<T>* &_parent, RBTreeNode<T>* &_root, const T value)
{
	if (_root == this->nil)//找到合适的位置进行插入  创建节点
	{
		nodeSize++;
		_root = new RBTreeNode<T>(value, this->nil, this->nil, _parent, RED);
		if (_parent == this->nil)
		{//第一个节点相关配置
			this->root = _root;
			this->root -> _parent = this->nil;
			this->nil->_left = this->root;
			this->nil->_right = this->root;
		}
		//插入之后，修正红黑树的节点的颜色，使其保持红黑树的性质
		_RBAddFixup(_root);
		return;
	}
	if (value < _root->_data)//当添加的值小于当前节点  向左进行插入操作
	{
		_AddBinaryNode(_root, _root->_left, value);
	}
	else if (value > _root->_data)//当添加的值大于当前节点  向右进行插入操作
	{
		_AddBinaryNode(_root, _root->_right, value);
	}
}
//添加结点之后   修正红黑树的颜色
template<class T>
void RedBlackTree<T>::_RBAddFixup(RBTreeNode<T>* _rootZ)
{
	while (parent(_rootZ)->_color == RED)//父母为红色，则祖父为黑色
	{
		//如果Z节点的父亲是祖父的左孩子
		if (parent(_rootZ) == grandparent(_rootZ)->_left)
		{
			if (rightUncle(_rootZ)->_color == RED)//case1：rootZ的右叔父为红色，则rootZ必定为黑色
			{
				parent(_rootZ)->_color = BLACK;
				rightUncle(_rootZ)->_color = BLACK;
				grandparent(_rootZ)->_color = RED;
				_rootZ = grandparent(_rootZ);
			}
			else//rootZ的右叔父为黑色
			{
				//rootZ的右叔父为黑色 && _rootZ是父母的右孩子
				if (_rootZ == parent(_rootZ)->_right)
				{
					//_rootZ = parent(_rootZ);
					leftRotate(parent(_rootZ));
					//_rootZ = _rootZ->_left;
				}
				parent(_rootZ)->_color = BLACK;
				grandparent(_rootZ)->_color = RED;
				rightRotate(grandparent(_rootZ));
			}
		}
		else//如果Z节点的父亲是祖父的右孩子
		{
			if (leftUncle(_rootZ)->_color == RED)//case1：rootZ的右叔父为红色，则rootZ必定为黑色
			{
				parent(_rootZ)->_color = BLACK;
				leftUncle(_rootZ)->_color = BLACK;
				grandparent(_rootZ)->_color = RED;
				_rootZ = grandparent(_rootZ);
			}
			else//rootZ的左叔父为黑色
			{
				//rootZ的左叔父为黑色 && _rootZ是父母的左孩子
				if (_rootZ == parent(_rootZ)->_left)
				{
					rightRotate(parent(_rootZ));
				}
				parent(_rootZ)->_color = BLACK;
				grandparent(_rootZ)->_color = RED;
				leftRotate(grandparent(_rootZ));
			}
		}
	}
	this->root->_color = BLACK;
}


//查询节点
template<class T>
RBTreeNode<T>* RedBlackTree<T>::_searchNode(RBTreeNode<T>* _root, const T &value)
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
/*****************************************************
① 被删除节点没有儿子，即为叶节点。那么，直接将该节点删除
② 被删除节点只有一个儿子。那么，直接删除该节点，并用该节点的唯一子节点顶替它的位置
③ 被删除节点有两个儿子。那么，先找出它的后继节点；然后把“它的后继节点的内容”复制给
“该节点的内容”；之后，删除“它的后继节点”。它的后继节点不可能是双子非空,要么只有一
个儿子。若没有儿子，则按"情况① "进行处理；若只有一个儿子，则按"情况② "进行处理。
*****************************************************/
template<class T>
bool RedBlackTree<T>::_deleteNode(RBTreeNode<T>* _root, RBTreeNode<T>* _searchNodeRoot)
{
	RBTreeNode<T>* _searchNodeRootTemp;	//_searchNodeRootTemp为确定要删的节点
	RBTreeNode<T>* _searchNodeRootNext;	//_searchNodeRootNext为删的节点补上去的节点

	if (rightChild(_searchNodeRoot) != this->nil && leftChild(_searchNodeRoot) != this->nil)
		_searchNodeRootTemp = treeMinimum(rightChild(_searchNodeRoot));
	else
		_searchNodeRootTemp = _searchNodeRoot;

	//找到删除结点的需要补上去的节点
	if (rightChild(_searchNodeRootTemp) != this->nil)
		_searchNodeRootNext = rightChild(_searchNodeRootTemp);
	else
		_searchNodeRootNext = leftChild(_searchNodeRootTemp);

	//补上去的节点找到其父母节点
	_searchNodeRootNext->_parent = parent(_searchNodeRootTemp);

	if (parent(_searchNodeRootTemp) == this->nil)//被删除的节点为根节点
		this->root = _searchNodeRootNext;
	else if (_searchNodeRootTemp == parent(_searchNodeRootTemp)->_left)//被删除的节点为父母的左孩子
		_searchNodeRootTemp->_parent->_left = _searchNodeRootNext;
	else
		_searchNodeRootTemp->_parent->_right = _searchNodeRootNext;

	if (_searchNodeRoot != _searchNodeRootTemp)//_searchNodeRoot删除找了替补来进行删除
		_searchNodeRoot->_data = _searchNodeRootTemp->_data;

	if (_searchNodeRootTemp->_color = BLACK)
		_RBDeleteFixup(_searchNodeRootNext);

	delete _searchNodeRootTemp;
	_searchNodeRootTemp = NULL;
	return true;
}
//删除结点之后   修正红黑树的颜色
template<class T>
void RedBlackTree<T>::_RBDeleteFixup(RBTreeNode<T>* _rootX)
{
	while (_rootX != this->root && _rootX->_color == BLACK)
	{
		if (_rootX == parent(_rootX)->_left)
		{
			RBTreeNode<T>* _rootW = rightBrother(_rootX);//_rootX的右兄弟
			if (_rootW->_color == RED) // Case 1: x的兄弟w是红色的 
			{
				_rootW->_color = BLACK;
				parent(_rootX)->_color = RED;
				leftRotate(parent(_rootX));
				_rootW = rightBrother(_rootX);
			}

			if (leftChild(_rootW)->_color == BLACK && rightChild(_rootW)->_color == BLACK)// Case 2: x的兄弟w是黑色，且w的俩个孩子也都是黑色的  
			{
				_rootW->_color = RED;
				_rootX = parent(_rootX);
			}
			else
			{
				if (rightChild(_rootW)->_color == BLACK)// Case 3: x的兄弟w是黑色的，并且w的左孩子是红色，右孩子为黑色。  
				{
					_rootW->_left->_color = BLACK;
					_rootW->_color = RED;
					rightRotate(_rootW);
					_rootW = rightBrother(_rootX);
				}
				// Case 4: x的兄弟w是黑色的；并且w的右孩子是红色的，左孩子任意颜色。
				_rootW->_color = parent(_rootX)->_color;
				parent(_rootX)->_color = BLACK;
				rightChild(_rootW)->_color = BLACK;
				leftRotate(parent(_rootX));
				_rootX = this->root;	//结束循环
			}
		}
		else
		{
			RBTreeNode<T>* _rootW = leftBrother(_rootX);//_rootX的右兄弟
			if (_rootW->_color == RED) // Case 1: x的兄弟w是红色的 
			{
				_rootW->_color = BLACK;
				parent(_rootX)->_color = RED;
				rightRotate(parent(_rootX));
				_rootW = leftBrother(_rootX);
			}

			if (leftChild(_rootW)->_color == BLACK && rightChild(_rootW)->_color == BLACK)// Case 2: x的兄弟w是黑色，且w的俩个孩子也都是黑色的  
			{
				_rootW->_color = RED;
				_rootX = parent(_rootX);
			}
			else
			{
				if (leftChild(_rootW)->_color == BLACK)// Case 3: x的兄弟w是黑色的，并且w的左孩子是红色，右孩子为黑色。  
				{
					_rootW->_right->_color = BLACK;
					_rootW->_color = RED;
					leftRotate(_rootW);
					_rootW = leftBrother(_rootX);
				}
				// Case 4: x的兄弟w是黑色的；并且w的右孩子是红色的，左孩子任意颜色。
				_rootW->_color = parent(_rootX)->_color;
				parent(_rootX)->_color = BLACK;
				leftChild(_rootW)->_color = BLACK;
				rightRotate(parent(_rootX));
				_rootX = this->root;
			}
		}
	}
	_rootX->_color = BLACK;
}


//删除整棵二叉排序树
template<class T>
void RedBlackTree<T>::_Destroy(RBTreeNode<T>* &_root)
{
	if (_root == this->nil || this->nil == NULL)
	{
		return;
	}
	
	_Destroy(_root->_left);
	_Destroy(_root->_right);

	delete _root;
	_root = this->nil;
}

/***************************遍历红黑树***************************/
//先序遍历
template<class T>
void RedBlackTree<T>::_PrevOrder(RBTreeNode<T>* _root)
{
	RBTreeNode<T> *temp = _root;
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
void RedBlackTree<T>::_InOrder(RBTreeNode<T>* _root)
{
	RBTreeNode<T> *temp = _root;
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
void RedBlackTree<T>::_PostOrder(RBTreeNode<T>* _root)
{
	RBTreeNode<T> *temp = _root;
	if (temp == NULL)
	{
		return;
	}
	_PostOrder(temp->_left);
	_PostOrder(temp->_right);
	cout << temp->_data << "  ";
}

/****************** 旋转节点，保持红黑树的性质 ******************/
//当添加结点之后，导致节点左右不平衡，则需要旋转，分为以下四种情况
template<class T>
void RedBlackTree<T>::rightRotate(RBTreeNode<int>* _root)
{
	RBTreeNode<int>* _rootLeftTemp = _root->_left;
	swap(*_root, *_rootLeftTemp);

	_rootLeftTemp->_left = _root->_right;
	_root->_right = _rootLeftTemp;

	
	_root->_left->_parent = _root;
	_root->_parent = _rootLeftTemp->_parent;
	_root->_right->_parent = _root;
	_rootLeftTemp->_left->_parent = _rootLeftTemp;
	_rootLeftTemp->_right->_parent = _rootLeftTemp;
	_rootLeftTemp->_parent = _root;
}
template<class T>
void RedBlackTree<T>::leftRotate(RBTreeNode<int>* _root)
{
	RBTreeNode<int>* _rootRightTemp = _root->_right;

	swap(*_root, *_rootRightTemp);

	_rootRightTemp->_right = _root->_left;
	_root->_left = _rootRightTemp;

	_root->_right->_parent = _root;
	_root->_parent = _rootRightTemp->_parent;
	_root->_left->_parent = _root;
	
	_rootRightTemp->_right->_parent = _rootRightTemp;
	_rootRightTemp->_left ->_parent = _rootRightTemp;
	_rootRightTemp->_parent = _root;
}

//前驱 后继
template<class T>
RBTreeNode<int>* RedBlackTree<T>::treePredecessor(RBTreeNode<int>* _root)	//前驱
{
	if (_root->_left != this->nil)
		return treeMaximum(_root);

	RBTreeNode<int>* _rootParent = parent(_root);

	while (_rootParent != this->nil && _root == _rootParent->_left)
	{
		_root = _rootParent;
		_rootParent = parent(_root);
	}
	return _rootParent;
}

template<class T>
RBTreeNode<int>* RedBlackTree<T>::treeSuccessor(RBTreeNode<int>* _root)  	//后继
{
	if (_root->_right != this->nil)
		return treeMinimum(_root);
	RBTreeNode<int>* _rootParent = parent(_root);

	while (_rootParent != this->nil && _root == _rootParent->_right)
	{
		_root = _rootParent;
		_rootParent = parent(_root);
	}
	return _rootParent;
}

/*************************显示整棵红黑树*************************/
//中序遍历返回节点数组
template<class T>
vector<RBTreeNode<T> *> RedBlackTree<T>::inorderTraversal(RBTreeNode<T> *_root) 
{
	vector<RBTreeNode<T> *> res;
	stack<RBTreeNode<T> *> stk;
	while (_root != this->nil || !stk.empty())
	{  
		while (_root != this->nil)
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
//按照树状结构打印红黑树
template<class T>
void RedBlackTree<T>::printTree()
{
	if (this->root == this->nil)
		return;

	auto tmp = this->root;
	vector<RBTreeNode<T> *> intv = inorderTraversal(tmp);//中序遍历节点数组
	string template_str;//模板string，表示每行打印string的长度
	int location = 0;
	unordered_map<RBTreeNode<int>*, int> first_locations;//存储节点对应在本行string中的首位置
	for (auto &i : intv)
	{
		location = template_str.size();
		template_str += to_string(i->_data) + "  ";
		first_locations[i] = location;
	}
	template_str += " ";
	for (auto &i : template_str)i = ' ';//把模板全部置为空格方便后续使用
	//层序遍历
	queue<RBTreeNode<T> *> q;
	q.push(this->root);
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

			string addString = ":" + redBlackWorf[node->_color];
			string num_str = to_string(node->_data) + addString;

			//左边，如果存在左孩子，那么在第二行对应位置打印'/'，在第一行补上'_'
			if (node->_left != this->nil) {
				q.push(node->_left);
				int first_loc = first_locations[node->_left];
				tmp_str2[first_loc++ + addString.size()] = '/';
				while (first_loc < cur_loc)tmp_str1[first_loc++ + addString.size()] = '_';
			}
			//中间,对应位置打印节点值（有可能为多位数）
			for (int j = 0; j < num_str.size(); ++j, ++cur_loc) {
				tmp_str1[cur_loc] = num_str[j];
			}
			//右边，如果存在右孩子，那么在第二行对应位置打印'\'，在第一行补上'_'
			if (node->_right != this->nil)
			{
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
