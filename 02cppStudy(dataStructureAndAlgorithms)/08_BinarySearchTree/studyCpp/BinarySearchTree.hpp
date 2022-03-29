#ifndef  _BINARYTREE_HPP__
#define _BINARYTREE_HPP__

#include<iostream>

using namespace std;

/*****************************************************************
1、构造函数（递归）
2、拷贝构造函数（递归）
3、析构函数（递归）
4、赋值运算符重载（传统 / 现代）
5、前中后序遍历（递归 / 非递归）
6、层序遍历（非递归）
7、查找第k层结点个数（递归）
8、精确查找值为x的结点，并返回当前结点的指针（递归）
9、查找叶子结点个数（递归）
10、查找结点总个数（递归）
11、计算树的深度（递归）
*****************************************************************/

template <typename T>
struct BinaryTreeNode		//树的节点
{
	BinaryTreeNode<T> *_left;	//根节点的左子树
	BinaryTreeNode<T> *_right;	//根节点的右子树

	T _data;

	BinaryTreeNode(T data = T()) :_left(NULL), _right(NULL), _data(data) {}//节点的构造函数，T()为一个匿名对象
};

template <typename T>
class BinarySearchTree
{
public:
	//BinarySearchTree的参数构造函数
	BinarySearchTree(const vector<T> &numArr)
	{
		this->root = NULL;
		for (int i = 0; i < numArr.size(); i++)
		{
			_AddBinaryNode(this->root, numArr[i]);
		}
	}
	//BinarySearchTree的拷贝构造函数
	BinarySearchTree(const BinarySearchTree<T>& t)
	{
		this->root = _CopyTree(t.root);
	}
	//BinarySearchTree的析构函数
	~BinarySearchTree()
	{
		_Destroy(this->root);
	}
	//重载赋值操作符，进行深拷贝
	BinarySearchTree<T>& operator=(BinarySearchTree<T> t)
	{
		if (this != &t )
		{
			std::swap(this->root, t.root);
		}

		return *this;
	}
	//前序遍历
	void PrevOrder()
	{
		_PrevOrder(this->root);
		cout << endl;
	}
	//中序遍历
	void InOrder()
	{
		_InOrder(this->root);
		cout << endl;
	}
	//后序遍历
	void PostOrder()
	{
		_PostOrder(this->root);
		cout << endl;
	}
	//二叉查找树中添加节点
	void addNode(const T &value)
	{
		_AddBinaryNode(this->root, value);
	}
	//查询节点  返回该节点的地址  若没有找到  则返回NULL
	BinaryTreeNode<T> *searchNode(const T &value)
	{
		return _searchNode(this->root, value);
	}
	//二叉查找树中删除节点，若找到并且成功删除，则返回true 否则返回false
	bool  deleteNode(const T &value)
	{
		this->nodeSize = 0;
		return _deleteNode(NULL, this->root, value);
	}
	BinaryTreeNode<T> *root;
	int nodeSize;
private:
	//BinaryTreeNode赋值函数
	BinaryTreeNode<T>* _CopyTree(const BinaryTreeNode<T>* t)
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
	//添加查找二叉树节点
	void _AddBinaryNode(BinaryTreeNode<T>* &root, const T value)
	{
		if (root == NULL)
		{
			nodeSize++;
			root = new BinaryTreeNode<T>(value);
			//return root;
		}
		else
		{
			if (value <= root->_data)
				_AddBinaryNode(root->_left, value);
			else
				_AddBinaryNode(root->_right, value);
		}
	}
	//查询节点
	const BinaryTreeNode<T>* _searchNode(const BinaryTreeNode<T>* _root, const T &value)
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
	bool  _deleteNode(BinaryTreeNode<T>* _parent, BinaryTreeNode<T>* _root, const T &value)
	{
		if(_root == NULL)
			return false;
		//如果找到
		if (_root->_data == value)
		{
			if (_root->_left == NULL && _root->_right == NULL)//该节点左右孩子都为空
			{
				if (_parent != NULL)
				{
					if (_parent->_left == _root)
						_parent->_left = NULL;
					else
						_parent->_right = NULL;
				}
				else
				{
					this->root = NULL;
				}
				delete _root;
				_root = NULL;
				this->nodeSize--;
				return true;
			}
			if (_root->_left != NULL && _root->_right == NULL)//该节点左不为空，右孩子为空
			{
				if (_parent != NULL)
				{
					if (_parent->_left == _root)
						_parent->_left = _root->_left;
					else
						_parent->_right = _root->_left;
				}
				else
				{
					this->root = _root->_left;
				}
				delete _root;
				_root = NULL;
				this->nodeSize--;
				return true;
			}
			if (_root->_left == NULL && _root->_right != NULL)//该节点右不为空，左孩子为空
			{
				if (_parent != NULL)
				{
					if (_parent->_left == _root)
						_parent->_left = _root->_right;
					else
						_parent->_right = _root->_right;
				}
				else
				{
					this->root = _root->_right;
				}
				delete _root;
				_root = NULL;
				this->nodeSize--;
				return true;
			}
			if (_root->_left != NULL && _root->_right != NULL)//该节点右不为空，左孩子为空
			{
				if (_parent != NULL)
				{
					if (_parent->_left == _root)
					{
						_parent->_left = _root->_right;
						_minValue(_root->_right)->_left = _root->_left;
					}
					else
					{
						_parent->_right = _root->_right;
						_minValue(_root->_right)->_left = _root->_left;
					}
				}
				else
				{
					this->root = _root->_right;
					_minValue(_root->_right)->_left = _root->_left;
				}
				delete _root;
				_root = NULL;
				this->nodeSize--;
				return true;
			}
		}
		//递归进行查找  耗时为o(lgn)
		if (value > _root->_data)
			return _deleteNode(_root, _root->_right, value);
		else
			return _deleteNode(_root, _root->_left, value);
	}
	//删除整棵二叉排序树
	void _Destroy(BinaryTreeNode<T>* t)
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
	void _PrevOrder(BinaryTreeNode<T>* _root)
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
	void _InOrder(BinaryTreeNode<T>* _root)
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
	void _PostOrder(BinaryTreeNode<T>* _root)
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
	//查找整棵树的最小节点地址，即最左边节点
	BinaryTreeNode<T>* _minValue(BinaryTreeNode<T>* _root)
	{
		if (_root->_left == NULL)
		{
			return _root;
		}
		return _minValue(_root->_left);
	}
};

#endif // ! _BINARYTREE_HPP__
