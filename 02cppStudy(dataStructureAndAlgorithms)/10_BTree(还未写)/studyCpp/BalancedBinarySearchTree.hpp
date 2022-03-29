#pragma once

#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

/*AVL��������ƽ�������*/

/*****************************************************************
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

template <typename T>
struct BinaryTreeNode		//ƽ��������Ľڵ�
{
	BinaryTreeNode<T> *_left;	//���ڵ��������
	BinaryTreeNode<T> *_right;	//���ڵ��������

	T _data;
	int height;
	BinaryTreeNode(T data = T()) :_left(NULL), _right(NULL), _data(data) ,height(0){}//�ڵ�Ĺ��캯����T()Ϊһ����������
	//BinaryTreeNode(T data = T()) :_left(NULL), _right(NULL), _data(data), height(0) {}//�ڵ�Ĺ��캯����T()Ϊһ����������
};

//Avl  ƽ�������
template <typename T>
class BalancedBinarySearchTree
{
public:
	//BalancedBinarySearchTree�Ĳ������캯��
	BalancedBinarySearchTree(const vector<T> &numArr);
	//BalancedBinarySearchTree�Ŀ������캯��
	BalancedBinarySearchTree(const BalancedBinarySearchTree<T>& t);
	//BalancedBinarySearchTree����������
	~BalancedBinarySearchTree();
	//���ظ�ֵ���������������
	BalancedBinarySearchTree<T>& operator=(BalancedBinarySearchTree<T> t);
	//ǰ�����
	void PrevOrder();
	//�������
	void InOrder();
	//�������
	void PostOrder();
	//����ƽ��������ӽڵ�
	void addNode(const T &value);
	//��ѯ�ڵ�  ���ظýڵ�ĵ�ַ  ��û���ҵ�  �򷵻�NULL
	const BinaryTreeNode<T> *searchNode(const T &value);
	//����ƽ������ɾ���ڵ㣬���ҵ����ҳɹ�ɾ�����򷵻�true ���򷵻�false
	bool  deleteNode(const T &value);
	//������״�ṹ��ӡ����ƽ����
	void printTree();
	void printTree(BinaryTreeNode<T>* _root);
	//Ѱ�����ֵ
	T findMaxValue(BinaryTreeNode<T>* _root);
	//Ѱ����Сֵ
	T findMinValue(BinaryTreeNode<T>* _root);


	BinaryTreeNode<T> *root;	//���ĸ��ڵ�
	int nodeSize;				//���нڵ����Ŀ
private:
	//BinaryTreeNode��ֵ����
	BinaryTreeNode<T>* _CopyTree(const BinaryTreeNode<T>* t);
		//���ƽ��������ڵ�
	void _AddBinaryNode(BinaryTreeNode<T>* &root, const T value);
	//��ѯ�ڵ�
	const BinaryTreeNode<T>* _searchNode(const BinaryTreeNode<T>* _root, const T &value);
	//ɾ���ڵ�
	bool  _deleteNode(BinaryTreeNode<T>* _parentRoot, BinaryTreeNode<T>* _root, const T value);
	//ɾ�����ö���������
	void _Destroy(BinaryTreeNode<T>* t);
	//�������
	void _PrevOrder(BinaryTreeNode<T>* _root);
	//�������
	void _InOrder(BinaryTreeNode<T>* _root);
	//�������
	void _PostOrder(BinaryTreeNode<T>* _root);
	//��ȡ�ýڵ�ĸ߶�
	int _getHeight(BinaryTreeNode<T>* _root)
	{
		if (_root == NULL)
			return -1;
		else
			return _root->height;
	}
	//ƽ������������С�ڵ��ַ��������߽ڵ�
	BinaryTreeNode<T>* _minValue(BinaryTreeNode<T>* _root);
public:
	//����ӽ��֮�󣬵��½ڵ����Ҳ�ƽ�⣬����Ҫ��ת����Ϊ�����������
	void LL(BinaryTreeNode<int>* _root);
	void RR(BinaryTreeNode<int>* _root);
	void LR(BinaryTreeNode<int>* _root);
	void RL(BinaryTreeNode<int>* _root);

	//����������ؽڵ�����
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
//BalancedBinarySearchTree�Ŀ������캯��
template<class T>
BalancedBinarySearchTree<T>::BalancedBinarySearchTree(const BalancedBinarySearchTree<T>& t)
{
	this->root = _CopyTree(t.root);
}
//BalancedBinarySearchTree����������
template<class T>
BalancedBinarySearchTree<T>::~BalancedBinarySearchTree()
{
	_Destroy(this->root);
}
//���ظ�ֵ���������������
template<class T>
BalancedBinarySearchTree<T>& BalancedBinarySearchTree<T>::operator=(BalancedBinarySearchTree<T> t)
{
	if (this != &t)
	{
		std::swap(this->root, t.root);
	}

	return *this;
}
//ǰ�����
template<class T>
void BalancedBinarySearchTree<T>::PrevOrder()
{
	_PrevOrder(this->root);
	cout << endl;
}
//�������
template<class T>
void BalancedBinarySearchTree<T>::InOrder()
{
	_InOrder(this->root);
	cout << endl;
}
//�������
template<class T>
void BalancedBinarySearchTree<T>::PostOrder()
{
	_PostOrder(this->root);
	cout << endl;
}
//����ƽ��������ӽڵ�
template<class T>
void BalancedBinarySearchTree<T>::addNode(const T &value)
{
	_AddBinaryNode(this->root, value);
}
//��ѯ�ڵ�  ���ظýڵ�ĵ�ַ  ��û���ҵ�  �򷵻�NULL
template<class T>
const BinaryTreeNode<T>* BalancedBinarySearchTree<T>::searchNode(const T &value)
{
	return _searchNode(this->root, value);
}
//����ƽ������ɾ���ڵ㣬���ҵ����ҳɹ�ɾ�����򷵻�true ���򷵻�false
template<class T>
bool BalancedBinarySearchTree<T>::deleteNode(const T &value)
{
	this->nodeSize = 0;
	return _deleteNode(NULL, this->root, value);
}
//������״�ṹ��ӡ����ƽ����
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
	vector<BinaryTreeNode<T> *> intv = inorderTraversal(tmp);//��������ڵ�����
	string template_str;//ģ��string����ʾÿ�д�ӡstring�ĳ���
	int location = 0;
	unordered_map<BinaryTreeNode<int>*, int> first_locations;//�洢�ڵ��Ӧ�ڱ���string�е���λ��
	for (auto &i : intv)
	{
		location = template_str.size();
		template_str += to_string(i->_data)+ " ";
		first_locations[i] = location;
	}
	for (auto &i : template_str)i = ' ';//��ģ��ȫ����Ϊ�ո񷽱����ʹ��
	//�������
	queue<BinaryTreeNode<T> *> q;
	q.push(root);
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
			string num_str = to_string(node->_data)+":"+ to_string(node->height);
			//��ߣ�����������ӣ���ô�ڵڶ��ж�Ӧλ�ô�ӡ'/'���ڵ�һ�в���'_'
			if (node->_left) {
				q.push(node->_left);
				int first_loc = first_locations[node->_left] + 1;
				tmp_str2[first_loc++] = '/';
				while (first_loc < cur_loc)tmp_str1[first_loc++] = '_';
			}
			//�м�,��Ӧλ�ô�ӡ�ڵ�ֵ���п���Ϊ��λ����
			for (int j = 0; j < num_str.length(); ++j, ++cur_loc) {
				tmp_str1[cur_loc] = num_str[j];
			}
			//�ұߣ���������Һ��ӣ���ô�ڵڶ��ж�Ӧλ�ô�ӡ'\'���ڵ�һ�в���'_'
			if (node->_right) {
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
template<class T>
void BalancedBinarySearchTree<T>::printTree(BinaryTreeNode<T>* _root)
{
	if (!_root)return;
	auto tmp = _root;
	vector<BinaryTreeNode<T> *> intv = inorderTraversal(tmp);//��������ڵ�����
	string template_str;//ģ��string����ʾÿ�д�ӡstring�ĳ���
	int location = 0;
	unordered_map<BinaryTreeNode<int>*, int> first_locations;//�洢�ڵ��Ӧ�ڱ���string�е���λ��
	for (auto &i : intv)
	{
		location = template_str.size();
		template_str += to_string(i->_data) + " ";
		first_locations[i] = location;
	}
	for (auto &i : template_str)i = ' ';//��ģ��ȫ����Ϊ�ո񷽱����ʹ��
	//�������
	queue<BinaryTreeNode<T> *> q;
	q.push(_root);
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
			string num_str = to_string(node->_data);
			//��ߣ�����������ӣ���ô�ڵڶ��ж�Ӧλ�ô�ӡ'/'���ڵ�һ�в���'_'
			if (node->_left) {
				q.push(node->_left);
				int first_loc = first_locations[node->_left] + 1;
				tmp_str2[first_loc++] = '/';
				while (first_loc < cur_loc)tmp_str1[first_loc++] = '_';

			}
			//�м�,��Ӧλ�ô�ӡ�ڵ�ֵ���п���Ϊ��λ����
			for (int j = 0; j < num_str.length(); ++j, ++cur_loc) {
				tmp_str1[cur_loc] = num_str[j];
			}
			//�ұߣ���������Һ��ӣ���ô�ڵڶ��ж�Ӧλ�ô�ӡ'\'���ڵ�һ�в���'_'
			if (node->_right) {
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


//Ѱ�����ֵ
template<class T>
T BalancedBinarySearchTree<T>::findMaxValue(BinaryTreeNode<T>* _root)
{
	if (_root->_right == NULL)
	{
		return _root->_data;
	}
	return findMaxValue(_root->_right);
}
//Ѱ����Сֵ
template<class T>
T BalancedBinarySearchTree<T>::findMinValue(BinaryTreeNode<T>* _root)
{
	if (_root->_left == NULL)
	{
		return _root->_data;
	}
	return findMaxValue(_root->_left);
}


//BinaryTreeNode��ֵ����
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
//���ƽ��������ڵ�
template<class T>
void BalancedBinarySearchTree<T>::_AddBinaryNode(BinaryTreeNode<T>* &_root, const T value)
{
	if (_root == NULL)//�ҵ����ʵ�λ�ý��в���  �����ڵ�
	{
		nodeSize++;
		_root = new BinaryTreeNode<T>(value);
		return;
	}
	if (value < _root->_data)//����ӵ�ֵС�ڵ�ǰ�ڵ�  ������в������
	{
		_AddBinaryNode(_root->_left, value);
	}
	else if (value >= _root->_data)//����ӵ�ֵ���ڵ�ǰ�ڵ�  ���ҽ��в������
	{
		_AddBinaryNode(_root->_right, value);
	}

	//���ݣ��ж��߹��Ľڵ���Ƿ�ƽ�⡣�粻ƽ�⣬���Ե���
	if (_getHeight(_root->_left) - _getHeight(_root->_right) > 1)
		LL(_root);
	else if (_getHeight(_root->_right) - _getHeight(_root->_left) > 1)
		RR(_root);
	//�����߹��Ľڵ�ĸ߶�λ��
	_root->height = max(_getHeight(_root->_left), _getHeight(_root->_right)) + 1;
}
//��ѯ�ڵ�
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
//ɾ���ڵ�
template<class T>
bool BalancedBinarySearchTree<T>::_deleteNode(BinaryTreeNode<T>* _parentRoot, BinaryTreeNode<T>* _root, const T value)
{
	bool flag = false;
	if (_root == NULL)//_rootΪ��  δ�ҵ�Ҫɾ���Ľڵ�
		return false;
	//����ҵ�Ҫɾ���Ľڵ�
	else if (_root->_data == value)
	{
		//�ж����������Ƿ�Ϊ��  ��Ϊ��  ��ʹ�ýϴ����������ֵ����
		if (_root->_left != NULL && _root->_right != NULL)
		{
			//�жϽϴ�����
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
			//����ýڵ�ĸ�ĸ��Ϊ�գ�����Ҫ�ȵ����ڵ�ṹ����ɾ���ýڵ�
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
	else if (value < _root->_data)//Ҫɾ���Ľ������������
	{
		flag = _deleteNode(_root, _root->_left, value);
	}
	else//Ҫɾ���Ľ������������
	{
		flag = _deleteNode(_root, _root->_right, value);
	}
	//����  �����ڵ������������ƽ��
	if (_getHeight(_root->_right) - _getHeight(_root->_left) > 1)
		RR(_root);

	if (_getHeight(_root->_left) - _getHeight(_root->_right) > 1)
		LL(_root);


	_root->height = max(_getHeight(_root->_left), _getHeight(_root->_right)) + 1;

	this->root = _root;

	return flag;
}
//ɾ�����ö���������
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
//�������
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
//�������
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
//�������
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
//ƽ������������С�ڵ��ַ��������߽ڵ�
template<class T>
BinaryTreeNode<T>* BalancedBinarySearchTree<T>::_minValue(BinaryTreeNode<T>* _root)
{
	if (_root->_left == NULL)
	{
		return _root;
	}
	return _minValue(_root->_left);
}
//����ӽ��֮�󣬵��½ڵ����Ҳ�ƽ�⣬����Ҫ��ת����Ϊ�����������
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
//����������ؽڵ�����
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