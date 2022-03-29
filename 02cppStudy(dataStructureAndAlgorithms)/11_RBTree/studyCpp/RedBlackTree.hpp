#pragma once

#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<unordered_map>

using namespace std;

/*****************************************************************
************************      �����      ************************
(1) ÿ���ڵ�����Ǻ�ɫ�������Ǻ�ɫ��
(2) ���ڵ��Ǻ�ɫ��
(3) ÿ��Ҷ�ӽڵ��Ǻ�ɫ��[ע�⣺����Ҷ�ӽڵ㣬��ָΪ�յ�Ҷ�ӽڵ㣡]
(4) ���һ���ڵ��Ǻ�ɫ�ģ��������ӽڵ�����Ǻ�ɫ�ġ�
(5) ��һ���ڵ㵽�ýڵ������ڵ������·���ϰ�����ͬ��Ŀ�ĺڽڵ㡣

1�����캯�����ݹ飩
2���������캯�����ݹ飩
3�������������ݹ飩
4����ֵ��������أ���ͳ / �ִ���
5��ǰ�к���������ݹ� / �ǵݹ飩
6������������ǵݹ飩
7��ƽ���k����������ݹ飩
8����ȷƽ��ֵΪx�Ľ�㣬�����ص�ǰ����ָ�루�ݹ飩
9��ƽ��Ҷ�ӽ��������ݹ飩
10��ƽ�����ܸ������ݹ飩
11������������ȣ��ݹ飩
*****************************************************************/

typedef enum {BLACK, RED} COLOR;
vector<string> redBlackWorf = { "��","��" };
template <typename T>
//������Ľڵ�
struct RBTreeNode
{
	RBTreeNode<T> *_left;	//���ڵ����ڵ�
	RBTreeNode<T> *_right;	//���ڵ���ҽڵ�
	RBTreeNode<T> *_parent; //���ڵ�ĸ��ڵ�

	T _data;					//�ڵ������
	COLOR _color;				//�ڵ����ɫ

	RBTreeNode(T data) :_left(NULL), _right(NULL), _parent(NULL), _data(data) , _color(RED){}//�ڵ�Ĺ��캯����T()Ϊһ����������
	RBTreeNode(T data, RBTreeNode<T> *left, RBTreeNode<T> *right, RBTreeNode<T> *parent, COLOR color) :
		_left(left), _right(right), _parent(parent), _data(data), _color(color) {}//�ڵ�Ĺ��캯����T()Ϊһ����������
};

//RBTree �����
template <typename T>
class RedBlackTree
{
public:
	/***************   ���캯��   ***************/
	//RedBlackTree���޲ι��캯��
	RedBlackTree() {}
	//RedBlackTree�Ĳ������캯��
	RedBlackTree(const vector<T> &numArr);
	//RedBlackTree�Ŀ������캯��
	RedBlackTree(const RedBlackTree<T>& t);

	/***************   ��������   ***************/
	//RedBlackTree����������
	~RedBlackTree();

	/***************  ���������  ***************/
	//���ظ�ֵ���������������
	RedBlackTree<T>& operator=(RedBlackTree<T> tree);
	
	/***************  ���������  ***************/
	//ǰ�����
	void PrevOrder();
	//�������
	void InOrder();
	//�������
	void PostOrder();

	/***************  �������ӡ�ɾ��������  ***************/
	//���������ӽڵ�
	void addNode(const T &value);
	//�������ɾ���ڵ㣬���ҵ����ҳɹ�ɾ�����򷵻�true ���򷵻�false
	bool deleteNode(const T &value);
	//ɾ�����ú����
	void deleteTree();
	//��ѯ�ڵ�  ���ظýڵ�ĵ�ַ  ��û���ҵ�  �򷵻�NIL
	RBTreeNode<T> *searchNode(const T &value);

	/***************  �������ӡ  ***************/
	//������״�ṹ��ӡ�����
	void printTree();

	/***************  �������ֵ����  ***************/
	//Ѱ�����ֵ
	T findMaxValue(RBTreeNode<T>* _root);
	//Ѱ����Сֵ
	T findMinValue(RBTreeNode<T>* _root);
	RBTreeNode<T>* treeMaximum(RBTreeNode<T>* _root);
	RBTreeNode<T>* treeMinimum(RBTreeNode<T>* _root);

	RBTreeNode<T> *root;	//���ĸ��ڵ�
	RBTreeNode<T> *nil;		//�����ⲿ
	int nodeSize;			//���нڵ����Ŀ
private:
	//RBTreeNode��������
	void _CopyTree(const RBTreeNode<T>* _root, const RBTreeNode<T>* _nil, 
		RBTreeNode<T>* _p, RBTreeNode<T>* &_t, RBTreeNode<T>* _n);

	//��Ӻ�����ڵ�
	void _AddBinaryNode(RBTreeNode<T>* &_parent, RBTreeNode<T>* &_root, const T value);
	void _RBAddFixup(RBTreeNode<T>* _rootZ);
	//��ѯ�ڵ�
	RBTreeNode<T>* _searchNode(RBTreeNode<T>* _root, const T &value);
	//ɾ���ڵ�
	bool  _deleteNode(RBTreeNode<T>* _root, RBTreeNode<T>* _searchNodeRoot);
	void _RBDeleteFixup(RBTreeNode<T>* _rootZ);

	//ɾ�����ö���������
	void _Destroy(RBTreeNode<T>* &t);
	//�������
	void _PrevOrder(RBTreeNode<T>* _root);
	//�������
	void _InOrder(RBTreeNode<T>* _root);
	//�������
	void _PostOrder(RBTreeNode<T>* _root);

	//������ת����
	void rightRotate(RBTreeNode<int>* _root);
	void leftRotate(RBTreeNode<int>* _root);


	//ǰ�� ���
	RBTreeNode<int>* treePredecessor(RBTreeNode<int>* _root);	//ǰ��
	RBTreeNode<int>* treeSuccessor(RBTreeNode<int>* _root);		//���

	//���ؽڵ������
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
	
	
	//����������ؽڵ�����
	vector<RBTreeNode<T> *> inorderTraversal(RBTreeNode<T> *_root);
};

/***********************��Ĺ��캯��**************************/
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
//RedBlackTree�Ŀ������캯��
template<class T>
RedBlackTree<T>::RedBlackTree(const RedBlackTree<T>& tree)
{
	this->nil = new RBTreeNode<T>(0, NULL, NULL, NULL, BLACK);
	this->root = this->nil;
	_CopyTree(tree.root, (tree.root)->_parent, this->nil, this->root, this->nil);
}
//RedBlackTree����������

/***********************�����������**************************/
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

//���ظ�ֵ���������������
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
//RBTreeNode��������
template<class T>
void RedBlackTree<T>::_CopyTree(const RBTreeNode<T>* _root, const RBTreeNode<T>* _nil, RBTreeNode<T>* _p, RBTreeNode<T>* &_t, RBTreeNode<T>* _n)
{
	if (_root == _nil)
		return;

	_t = new RBTreeNode<T>(_root->_data, _n, _n, _p, _root->_color);
	_CopyTree(_root->_left, _nil, _t, _t->_left, _n);
	_CopyTree(_root->_right, _nil, _t, _t->_right, _n);
}

//ǰ�����
template<class T>
void RedBlackTree<T>::PrevOrder()
{
	_PrevOrder(this->root);
	cout << endl;
}
//�������
template<class T>
void RedBlackTree<T>::InOrder()
{
	_InOrder(this->root);
	cout << endl;
}
//�������
template<class T>
void RedBlackTree<T>::PostOrder()
{
	_PostOrder(this->root);
	cout << endl;
}
//���������ӽڵ�
template<class T>
void RedBlackTree<T>::addNode(const T &value)
{
	_AddBinaryNode(this->root, value);
}
//��ѯ�ڵ�  ���ظýڵ�ĵ�ַ  ��û���ҵ�  �򷵻�NULL
template<class T>
RBTreeNode<T>* RedBlackTree<T>::searchNode(const T &value)
{
	RBTreeNode<T>* _searchNodeRoot = _searchNode(this->root, value);
	if (_searchNodeRoot == this->nil)
		return NULL;
	else
		return _searchNodeRoot;		
}
//�������ɾ���ڵ㣬���ҵ����ҳɹ�ɾ�����򷵻�true ���򷵻�false
template<class T>
bool RedBlackTree<T>::deleteNode(const T &value)
{
	RBTreeNode<T>* _searchNodeRoot = _searchNode(this->root, value);
	if (_searchNodeRoot == this->nil)
		return false;

	this->nodeSize--;

	return _deleteNode(this->root, _searchNodeRoot);
}
//ɾ�����ú����
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

//Ѱ�����ֵ
template<class T>
T RedBlackTree<T>::findMaxValue(RBTreeNode<T>* _root)
{
	if (_root->_right == this->nil)
	{
		return _root->_data;
	}
	return findMaxValue(_root->_right);
}
//Ѱ����Сֵ
template<class T>
T RedBlackTree<T>::findMinValue(RBTreeNode<T>* _root)
{
	if (_root->_left == this->nil)
	{
		return _root->_data;
	}
	return findMinValue(_root->_left);
}
//Ѱ�����ֵ�ڵ�ĵ�ַ
template<class T>
RBTreeNode<T>* RedBlackTree<T>::treeMaximum(RBTreeNode<T>* _root)
{
	if (_root->_right == this->nil)
	{
		return _root;
	}
	return findMaxValue(_root->_right);
}
//Ѱ����Сֵ�ڵ�ĵ�ַ
template<class T>
RBTreeNode<T>* RedBlackTree<T>::treeMinimum(RBTreeNode<T>* _root)
{
	if (_root->_left == this->nil)
	{
		return _root;
	}
	return treeMinimum(_root->_left);
}

/***************************��ɾ������***************************/
//��Ӻ�����ڵ�
template<class T>
void RedBlackTree<T>::_AddBinaryNode(RBTreeNode<T>* &_parent, RBTreeNode<T>* &_root, const T value)
{
	if (_root == this->nil)//�ҵ����ʵ�λ�ý��в���  �����ڵ�
	{
		nodeSize++;
		_root = new RBTreeNode<T>(value, this->nil, this->nil, _parent, RED);
		if (_parent == this->nil)
		{//��һ���ڵ��������
			this->root = _root;
			this->root -> _parent = this->nil;
			this->nil->_left = this->root;
			this->nil->_right = this->root;
		}
		//����֮������������Ľڵ����ɫ��ʹ�䱣�ֺ����������
		_RBAddFixup(_root);
		return;
	}
	if (value < _root->_data)//����ӵ�ֵС�ڵ�ǰ�ڵ�  ������в������
	{
		_AddBinaryNode(_root, _root->_left, value);
	}
	else if (value > _root->_data)//����ӵ�ֵ���ڵ�ǰ�ڵ�  ���ҽ��в������
	{
		_AddBinaryNode(_root, _root->_right, value);
	}
}
//��ӽ��֮��   �������������ɫ
template<class T>
void RedBlackTree<T>::_RBAddFixup(RBTreeNode<T>* _rootZ)
{
	while (parent(_rootZ)->_color == RED)//��ĸΪ��ɫ�����游Ϊ��ɫ
	{
		//���Z�ڵ�ĸ������游������
		if (parent(_rootZ) == grandparent(_rootZ)->_left)
		{
			if (rightUncle(_rootZ)->_color == RED)//case1��rootZ�����常Ϊ��ɫ����rootZ�ض�Ϊ��ɫ
			{
				parent(_rootZ)->_color = BLACK;
				rightUncle(_rootZ)->_color = BLACK;
				grandparent(_rootZ)->_color = RED;
				_rootZ = grandparent(_rootZ);
			}
			else//rootZ�����常Ϊ��ɫ
			{
				//rootZ�����常Ϊ��ɫ && _rootZ�Ǹ�ĸ���Һ���
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
		else//���Z�ڵ�ĸ������游���Һ���
		{
			if (leftUncle(_rootZ)->_color == RED)//case1��rootZ�����常Ϊ��ɫ����rootZ�ض�Ϊ��ɫ
			{
				parent(_rootZ)->_color = BLACK;
				leftUncle(_rootZ)->_color = BLACK;
				grandparent(_rootZ)->_color = RED;
				_rootZ = grandparent(_rootZ);
			}
			else//rootZ�����常Ϊ��ɫ
			{
				//rootZ�����常Ϊ��ɫ && _rootZ�Ǹ�ĸ������
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


//��ѯ�ڵ�
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
//ɾ���ڵ�
/*****************************************************
�� ��ɾ���ڵ�û�ж��ӣ���ΪҶ�ڵ㡣��ô��ֱ�ӽ��ýڵ�ɾ��
�� ��ɾ���ڵ�ֻ��һ�����ӡ���ô��ֱ��ɾ���ýڵ㣬���øýڵ��Ψһ�ӽڵ㶥������λ��
�� ��ɾ���ڵ����������ӡ���ô�����ҳ����ĺ�̽ڵ㣻Ȼ��ѡ����ĺ�̽ڵ�����ݡ����Ƹ�
���ýڵ�����ݡ���֮��ɾ�������ĺ�̽ڵ㡱�����ĺ�̽ڵ㲻������˫�ӷǿ�,Ҫôֻ��һ
�����ӡ���û�ж��ӣ���"����� "���д�����ֻ��һ�����ӣ���"����� "���д���
*****************************************************/
template<class T>
bool RedBlackTree<T>::_deleteNode(RBTreeNode<T>* _root, RBTreeNode<T>* _searchNodeRoot)
{
	RBTreeNode<T>* _searchNodeRootTemp;	//_searchNodeRootTempΪȷ��Ҫɾ�Ľڵ�
	RBTreeNode<T>* _searchNodeRootNext;	//_searchNodeRootNextΪɾ�Ľڵ㲹��ȥ�Ľڵ�

	if (rightChild(_searchNodeRoot) != this->nil && leftChild(_searchNodeRoot) != this->nil)
		_searchNodeRootTemp = treeMinimum(rightChild(_searchNodeRoot));
	else
		_searchNodeRootTemp = _searchNodeRoot;

	//�ҵ�ɾ��������Ҫ����ȥ�Ľڵ�
	if (rightChild(_searchNodeRootTemp) != this->nil)
		_searchNodeRootNext = rightChild(_searchNodeRootTemp);
	else
		_searchNodeRootNext = leftChild(_searchNodeRootTemp);

	//����ȥ�Ľڵ��ҵ��丸ĸ�ڵ�
	_searchNodeRootNext->_parent = parent(_searchNodeRootTemp);

	if (parent(_searchNodeRootTemp) == this->nil)//��ɾ���Ľڵ�Ϊ���ڵ�
		this->root = _searchNodeRootNext;
	else if (_searchNodeRootTemp == parent(_searchNodeRootTemp)->_left)//��ɾ���Ľڵ�Ϊ��ĸ������
		_searchNodeRootTemp->_parent->_left = _searchNodeRootNext;
	else
		_searchNodeRootTemp->_parent->_right = _searchNodeRootNext;

	if (_searchNodeRoot != _searchNodeRootTemp)//_searchNodeRootɾ�������油������ɾ��
		_searchNodeRoot->_data = _searchNodeRootTemp->_data;

	if (_searchNodeRootTemp->_color = BLACK)
		_RBDeleteFixup(_searchNodeRootNext);

	delete _searchNodeRootTemp;
	_searchNodeRootTemp = NULL;
	return true;
}
//ɾ�����֮��   �������������ɫ
template<class T>
void RedBlackTree<T>::_RBDeleteFixup(RBTreeNode<T>* _rootX)
{
	while (_rootX != this->root && _rootX->_color == BLACK)
	{
		if (_rootX == parent(_rootX)->_left)
		{
			RBTreeNode<T>* _rootW = rightBrother(_rootX);//_rootX�����ֵ�
			if (_rootW->_color == RED) // Case 1: x���ֵ�w�Ǻ�ɫ�� 
			{
				_rootW->_color = BLACK;
				parent(_rootX)->_color = RED;
				leftRotate(parent(_rootX));
				_rootW = rightBrother(_rootX);
			}

			if (leftChild(_rootW)->_color == BLACK && rightChild(_rootW)->_color == BLACK)// Case 2: x���ֵ�w�Ǻ�ɫ����w����������Ҳ���Ǻ�ɫ��  
			{
				_rootW->_color = RED;
				_rootX = parent(_rootX);
			}
			else
			{
				if (rightChild(_rootW)->_color == BLACK)// Case 3: x���ֵ�w�Ǻ�ɫ�ģ�����w�������Ǻ�ɫ���Һ���Ϊ��ɫ��  
				{
					_rootW->_left->_color = BLACK;
					_rootW->_color = RED;
					rightRotate(_rootW);
					_rootW = rightBrother(_rootX);
				}
				// Case 4: x���ֵ�w�Ǻ�ɫ�ģ�����w���Һ����Ǻ�ɫ�ģ�����������ɫ��
				_rootW->_color = parent(_rootX)->_color;
				parent(_rootX)->_color = BLACK;
				rightChild(_rootW)->_color = BLACK;
				leftRotate(parent(_rootX));
				_rootX = this->root;	//����ѭ��
			}
		}
		else
		{
			RBTreeNode<T>* _rootW = leftBrother(_rootX);//_rootX�����ֵ�
			if (_rootW->_color == RED) // Case 1: x���ֵ�w�Ǻ�ɫ�� 
			{
				_rootW->_color = BLACK;
				parent(_rootX)->_color = RED;
				rightRotate(parent(_rootX));
				_rootW = leftBrother(_rootX);
			}

			if (leftChild(_rootW)->_color == BLACK && rightChild(_rootW)->_color == BLACK)// Case 2: x���ֵ�w�Ǻ�ɫ����w����������Ҳ���Ǻ�ɫ��  
			{
				_rootW->_color = RED;
				_rootX = parent(_rootX);
			}
			else
			{
				if (leftChild(_rootW)->_color == BLACK)// Case 3: x���ֵ�w�Ǻ�ɫ�ģ�����w�������Ǻ�ɫ���Һ���Ϊ��ɫ��  
				{
					_rootW->_right->_color = BLACK;
					_rootW->_color = RED;
					leftRotate(_rootW);
					_rootW = leftBrother(_rootX);
				}
				// Case 4: x���ֵ�w�Ǻ�ɫ�ģ�����w���Һ����Ǻ�ɫ�ģ�����������ɫ��
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


//ɾ�����ö���������
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

/***************************���������***************************/
//�������
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
//�������
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
//�������
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

/****************** ��ת�ڵ㣬���ֺ���������� ******************/
//����ӽ��֮�󣬵��½ڵ����Ҳ�ƽ�⣬����Ҫ��ת����Ϊ�����������
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

//ǰ�� ���
template<class T>
RBTreeNode<int>* RedBlackTree<T>::treePredecessor(RBTreeNode<int>* _root)	//ǰ��
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
RBTreeNode<int>* RedBlackTree<T>::treeSuccessor(RBTreeNode<int>* _root)  	//���
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

/*************************��ʾ���ú����*************************/
//����������ؽڵ�����
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
//������״�ṹ��ӡ�����
template<class T>
void RedBlackTree<T>::printTree()
{
	if (this->root == this->nil)
		return;

	auto tmp = this->root;
	vector<RBTreeNode<T> *> intv = inorderTraversal(tmp);//��������ڵ�����
	string template_str;//ģ��string����ʾÿ�д�ӡstring�ĳ���
	int location = 0;
	unordered_map<RBTreeNode<int>*, int> first_locations;//�洢�ڵ��Ӧ�ڱ���string�е���λ��
	for (auto &i : intv)
	{
		location = template_str.size();
		template_str += to_string(i->_data) + "  ";
		first_locations[i] = location;
	}
	template_str += " ";
	for (auto &i : template_str)i = ' ';//��ģ��ȫ����Ϊ�ո񷽱����ʹ��
	//�������
	queue<RBTreeNode<T> *> q;
	q.push(this->root);
	while (!q.empty())
	{
		int currentLevelSize = q.size();
		int cur_loc = 0;
		string tmp_str1 = template_str, tmp_str2 = template_str;//1Ϊ�ڵ������У�2Ϊ����һ��
		for (int i = 1; i <= currentLevelSize; ++i)
		{
			auto node = q.front();
			q.pop();
			cur_loc = first_locations[node];

			string addString = ":" + redBlackWorf[node->_color];
			string num_str = to_string(node->_data) + addString;

			//��ߣ�����������ӣ���ô�ڵڶ��ж�Ӧλ�ô�ӡ'/'���ڵ�һ�в���'_'
			if (node->_left != this->nil) {
				q.push(node->_left);
				int first_loc = first_locations[node->_left];
				tmp_str2[first_loc++ + addString.size()] = '/';
				while (first_loc < cur_loc)tmp_str1[first_loc++ + addString.size()] = '_';
			}
			//�м�,��Ӧλ�ô�ӡ�ڵ�ֵ���п���Ϊ��λ����
			for (int j = 0; j < num_str.size(); ++j, ++cur_loc) {
				tmp_str1[cur_loc] = num_str[j];
			}
			//�ұߣ���������Һ��ӣ���ô�ڵڶ��ж�Ӧλ�ô�ӡ'\'���ڵ�һ�в���'_'
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
		//��ӡ����
		cout << tmp_str1 << endl;
		cout << tmp_str2 << endl;
	}
}
