#ifndef  _BINARYTREE_HPP__
#define _BINARYTREE_HPP__

#include<iostream>

using namespace std;

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
class BinarySearchTree
{
public:
	//BinarySearchTree�Ĳ������캯��
	BinarySearchTree(const vector<T> &numArr)
	{
		this->root = NULL;
		for (int i = 0; i < numArr.size(); i++)
		{
			_AddBinaryNode(this->root, numArr[i]);
		}
	}
	//BinarySearchTree�Ŀ������캯��
	BinarySearchTree(const BinarySearchTree<T>& t)
	{
		this->root = _CopyTree(t.root);
	}
	//BinarySearchTree����������
	~BinarySearchTree()
	{
		_Destroy(this->root);
	}
	//���ظ�ֵ���������������
	BinarySearchTree<T>& operator=(BinarySearchTree<T> t)
	{
		if (this != &t )
		{
			std::swap(this->root, t.root);
		}

		return *this;
	}
	//ǰ�����
	void PrevOrder()
	{
		_PrevOrder(this->root);
		cout << endl;
	}
	//�������
	void InOrder()
	{
		_InOrder(this->root);
		cout << endl;
	}
	//�������
	void PostOrder()
	{
		_PostOrder(this->root);
		cout << endl;
	}
	//�������������ӽڵ�
	void addNode(const T &value)
	{
		_AddBinaryNode(this->root, value);
	}
	//��ѯ�ڵ�  ���ظýڵ�ĵ�ַ  ��û���ҵ�  �򷵻�NULL
	BinaryTreeNode<T> *searchNode(const T &value)
	{
		return _searchNode(this->root, value);
	}
	//�����������ɾ���ڵ㣬���ҵ����ҳɹ�ɾ�����򷵻�true ���򷵻�false
	bool  deleteNode(const T &value)
	{
		this->nodeSize = 0;
		return _deleteNode(NULL, this->root, value);
	}
	BinaryTreeNode<T> *root;
	int nodeSize;
private:
	//BinaryTreeNode��ֵ����
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
	//��Ӳ��Ҷ������ڵ�
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
	//��ѯ�ڵ�
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
	//ɾ���ڵ�
	bool  _deleteNode(BinaryTreeNode<T>* _parent, BinaryTreeNode<T>* _root, const T &value)
	{
		if(_root == NULL)
			return false;
		//����ҵ�
		if (_root->_data == value)
		{
			if (_root->_left == NULL && _root->_right == NULL)//�ýڵ����Һ��Ӷ�Ϊ��
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
			if (_root->_left != NULL && _root->_right == NULL)//�ýڵ���Ϊ�գ��Һ���Ϊ��
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
			if (_root->_left == NULL && _root->_right != NULL)//�ýڵ��Ҳ�Ϊ�գ�����Ϊ��
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
			if (_root->_left != NULL && _root->_right != NULL)//�ýڵ��Ҳ�Ϊ�գ�����Ϊ��
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
		//�ݹ���в���  ��ʱΪo(lgn)
		if (value > _root->_data)
			return _deleteNode(_root, _root->_right, value);
		else
			return _deleteNode(_root, _root->_left, value);
	}
	//ɾ�����ö���������
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
	//�������
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
	//�������
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
	//�������
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
	//��������������С�ڵ��ַ��������߽ڵ�
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
