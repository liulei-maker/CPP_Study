#ifndef  _BINARYTREE_HPP__
#define _BINARYTREE_HPP__

#include<iostream>

using namespace std;

#define INVALIDCHAR  '#'
/*****************************************************************
1�����캯�����ݹ飩
2���������캯�����ݹ飩
3�������������ݹ飩
4����ֵ��������أ���ͳ / �ִ���
5��ǰ�к���������ݹ� / �ǵݹ飩
6������������ǵݹ飩
7�����ҵ�k����������ݹ飩
8����ȷ����ֵΪx�Ľ�㣬�����ص�ǰ����ָ�루�ݹ飩
9������Ҷ�ӽ��������ݹ飩
10�����ҽ���ܸ������ݹ飩
11������������ȣ��ݹ飩
*****************************************************************/

template <typename T>
struct BinaryTreeNode		//���Ľڵ�
{
	BinaryTreeNode<T> *_left;	//���ڵ��������
	BinaryTreeNode<T> *_right;	//���ڵ��������

	T _data;

	BinaryTreeNode(T data = T()) :_left(NULL), _right(NULL), _data(data) {}//�ڵ�Ĺ��캯����T()Ϊһ����������
};

template <typename T>
class BinaryTree
{
public:
	BinaryTree(const T *array, size_t size, const T& invalid = INVALIDCHAR)//BinaryTree�Ĳ������캯��
	{
		int index = 0;
		_root = _MakeTree(array, size, index, invalid);
	}

	BinaryTree(const BinaryTree<T>& t)//BinaryTree�Ŀ������캯��
	{
		_root = _CopyTree(t._root);
	}

	~BinaryTree()//BinaryTree����������
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
	//BinaryTreeNode��ֵ����
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
	//����������
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
