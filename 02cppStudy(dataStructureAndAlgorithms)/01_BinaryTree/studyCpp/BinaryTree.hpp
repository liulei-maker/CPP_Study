#ifndef  _BINARYTREE_HPP__
#define _BINARYTREE_HPP__

#include<iostream>

using namespace std;

#define INVALIDCHAR  '#'
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
class BinaryTree
{
public:
	BinaryTree(const T *array, size_t size, const T& invalid = INVALIDCHAR)//BinaryTree的参数构造函数
	{
		int index = 0;
		_root = _MakeTree(array, size, index, invalid);
	}

	BinaryTree(const BinaryTree<T>& t)//BinaryTree的拷贝构造函数
	{
		_root = _CopyTree(t._root);
	}

	~BinaryTree()//BinaryTree的析构函数
	{
		_Destroy(_root);
	}

	BinaryTree<T>& operator=(BinaryTree<T> t)
	{
		if (this != &t )
		{
			std::swap(_root, t._root);
		}

		return *this;
	}

	void PrevOrder()
	{
		_PrevOrder(_root);
		cout << endl;
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	void PostOrder()
	{
		_PostOrder(_root);
		cout << endl;
	}

private:
	//BinaryTreeNode赋值函数
	BinaryTreeNode<T>* _CopyTree(const BinaryTreeNode<T>* t)
	{
		BinaryTreeNode<T>* root = NULL;
		if (t == NULL)
		{
			return root;
		}

		root = new BinaryTreeNode<T>(t->_data);
		root->_left = _CopyTree(t->_left);
		root->_right = _CopyTree(t->_right);

		return root;
	}
	//创建二叉树
	BinaryTreeNode<T>* _MakeTree(const T *array, size_t size, int& index, const T& invalid)
	{
		BinaryTreeNode<T> *root = NULL;

		if (index < size && array[index] != invalid)
		{
			root = new BinaryTreeNode<T>(invalid);
			root->_data = array[index];
			root->_left = _MakeTree(array, size, ++index, invalid);
			root->_right = _MakeTree(array, size, ++index, invalid);
		}
		return root;
	}
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
	BinaryTreeNode<T> *_root;
};

#endif // ! _BINARYTREE_HPP__
