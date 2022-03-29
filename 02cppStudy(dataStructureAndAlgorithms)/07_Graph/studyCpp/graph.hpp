#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
#include<queue>

using namespace std;

#define MAX_VERTEX	100		//�������Ľڵ���Ŀ
#define INF			65535	//���������  ����δ���Ӷ���֮��Ĺ�ϵ
#define NIL			-1		//��ʾ�ýڵ���˫��

enum colorType { WHITE, GRAY, BLACK };
//ͼ�ı߽ṹ��
struct EdgeNode {
	int vertexIndex;			//�����������Ϣ
	int edgeWeight;				//�ߵ�Ȩֵ��Ϣ
	EdgeNode *nextEdgeNode;		//��һ���ߵĵ�ַ
	/*�������캯��*/
	EdgeNode() {}
	EdgeNode(int _vertexIndex, int _edgeWeight) :vertexIndex(_vertexIndex), edgeWeight(_edgeWeight), nextEdgeNode(NULL) {}
};

//ͼ�Ķ���ṹ��
template<class T>
struct VertexNode {
	T vertex;					//��ǰ����ֵ
	EdgeNode *firstEdgeNode;	//��һ���ߵĵ�ַ
	/*�������캯��*/
	VertexNode() {}
	VertexNode(T _vertex) :vertex(_vertex), firstEdgeNode(NULL) {}
};

//�����������壬sort����
bool Increase(vector<int> v1, vector<int> v2)
{
	return v1[2] < v2[2];
}

template <class T>
/*����Ȩ��ͼ��*/
class Graph
{
public:
	/*�������캯��*/
	Graph() {}
	/*   vertexArr:��������   adjoinMatrix:�ڽӾ���  */
	Graph(const vector<T> vertexArr, const vector<vector<int>> adjoinMatrix);
	~Graph();		//ͼ����������

	void showGraph();				//��ʾͼ

	/*ͼ�����㷨*/
	void DFS(const Graph<T> &graph);				//�����������
	void BFS(const Graph<T> &graph, const int s);	//�����������

	/*��С�������㷨*/
	void MST_Prim(const vector<T> &vertexArr, const vector<vector<int>> &adjoinMatrix, const int stratIndex);	//prim��С������
	void MST_Kruskal(const vector<T> &vertexArr, const vector<vector<int>> &adjoinMatrix);	//kruskal��С������

	/*���·��*/
	bool  MP_BellmanFord(const vector<vector<int>> &adjoinMatrix, const int &startIndex);	//BellmanFord�㷨
	void  MP_Dijkstra(const vector<vector<int>> &adjoinMatrix, const int &startIndex);		//Dijkstra�㷨
	void  MP_Floyd(const vector<vector<int>> &adjoinMatrix, const int &startIndex);			//Floyd�㷨

	VertexNode<T> **adjoinList;		//��������pointer
	int vertexNum, edgeNum;			//ͼ�ж��������ͱߵ�����

private:
	//�����ڽ�����
	EdgeNode *createEdgeList(const vector<int> arr, int index);
	//ɾ���ڽ�����
	void deleteList(EdgeNode *Node);
	//�жϵ�ǰ�ڵ����ĸ������У����ؼ��ϵ����
	int searchSet(const vector<set<int>> &vertexSet, int vertex);
	void DFSvisit(const Graph<T> &graph, const int u);

	int findMinPath(const vector<pair<bool, int>> &distanceArr);
	//��������
	int *colorArr, *depthArr, *parentArr;
	int time;
};

/*   Graph�Ĳ������캯��   */
/*   vertexArr:��������   adjoinMatrix:�ڽӾ���  */
template<class T>
Graph<T>::Graph(const vector<T> vertexArr, const vector<vector<int>> adjoinMatrix)
{
	if (vertexArr.size() != adjoinMatrix.size() || vertexArr.size() != adjoinMatrix[0].size())
	{
		cout << "input error!" << endl;
		return;
	}
	cout << "start create graph!" << endl;
	vertexNum = vertexArr.size();
	edgeNum = 0;
	adjoinList = new VertexNode<T>*[vertexNum];
	for (int row = 0; row < vertexNum; row++)
	{
		adjoinList[row] = new VertexNode<T>(vertexArr[row]);
		adjoinList[row]->firstEdgeNode = createEdgeList(adjoinMatrix[row], 0);
	}
	edgeNum = edgeNum / 2;
}

//ͼ����������
template <class T>
Graph<T>::~Graph()
{
	cout << "start delete graph!" << endl;
	for (int i = 0; i < vertexNum; i++)
	{
		deleteList(adjoinList[i]->firstEdgeNode);
		delete[] adjoinList[i];
	}
	delete[] adjoinList;
}

//��ʾͼ
template <class T>
void Graph<T>::showGraph()
{
	for (size_t i = 0; i < vertexNum; i++)
	{
		cout << "node " << i << ": ";
		EdgeNode *currentNode = adjoinList[i]->firstEdgeNode;
		while (currentNode != NULL)
		{
			cout << "( " << adjoinList[i]->vertex << "--" << currentNode->edgeWeight << "-->" << adjoinList[currentNode->vertexIndex]->vertex << " )\t";
			currentNode = currentNode->nextEdgeNode;
		}
		cout << endl;
	}
}

//�����ڽ�����
template <class T>
EdgeNode* Graph<T>::createEdgeList(const vector<int> arr, int index)
{
	EdgeNode *firstNode = NULL;

	if (index >= arr.size())
		return firstNode;
	//Ѱ�ұߣ���arr[index]==0��ʾ�ޱ�����
	while (arr[index] == 0 || arr[index] == INF)
	{
		index++;
		if (index >= arr.size())
			return firstNode;
	}
	/*�ݹ鴴���ڵ�*/
	firstNode = new EdgeNode(index, arr[index]);
	firstNode->nextEdgeNode = createEdgeList(arr, index + 1);
	return firstNode;
}

//ɾ���ڽ�����
template <class T>
void Graph<T>::deleteList(EdgeNode *Node)
{
	if (Node == NULL)
		return;
	deleteList(Node->nextEdgeNode);
	delete Node;
}

//��������������ɻ����Ȩͼ�����·��
template <class T>
void Graph<T>::BFS(const Graph<T> &graph, const int s)
{
	int vertexNum = graph.vertexNum;
	colorArr = new int[vertexNum];
	depthArr = new int[vertexNum];
	parentArr = new int[vertexNum];

	for (int i = 0; i < vertexNum; i++)
	{
		colorArr[i] = WHITE;
		depthArr[i] = INF;
		parentArr[i] = NIL;
	}
	colorArr[s] = GRAY;
	depthArr[s] = 0;
	parentArr[s] = NIL;

	//���嵱ǰ����
	queue<int> vertexQueue;
	vertexQueue.push(s);

	while (!vertexQueue.empty())
	{
		int u = vertexQueue.front();
		vertexQueue.pop();

		for (EdgeNode *it = graph.adjoinList[u]->firstEdgeNode; it != NULL; it = it->nextEdgeNode)
		{
			int v = it->vertexIndex;
			if (colorArr[v] == WHITE)
			{
				colorArr[v] = GRAY;
				depthArr[v] = depthArr[u] + 1;
				parentArr[v] = u;

				vertexQueue.push(v);
			}
		}
		colorArr[u] = BLACK;
		cout << u << "  ";
	}
	delete[] colorArr;
	delete[] depthArr;
	delete[] parentArr;
}

//�������ͼ������
template <class T>
void Graph<T>::DFSvisit(const Graph<T> &graph, const int u)
{
	colorArr[u] = GRAY;
	depthArr[u] = ++time;
	cout << u << " ";
	for (EdgeNode *it = graph.adjoinList[u]->firstEdgeNode; it != NULL; it = it->nextEdgeNode)
	{
		int v = it->vertexIndex;
		if (colorArr[it->vertexIndex] == WHITE)
		{
			parentArr[v] = u;
			DFSvisit(graph, v);
		}
	}
	colorArr[u] = BLACK;
	time++;
}
//�����������
template <class T>
void Graph<T>::DFS(const  Graph<T> &graph)
{
	int vertexNum = graph.vertexNum;
	colorArr = new int[vertexNum];
	depthArr = new int[vertexNum];
	parentArr = new int[vertexNum];
	time = 0;
	for (int i = 0; i < vertexNum; i++)
	{
		colorArr[i] = WHITE;
		depthArr[i] = time;
		parentArr[i] = NIL;
	}
	for (int i = 0; i < vertexNum; i++)
	{
		if (colorArr[i] == WHITE)
		{
			DFSvisit(graph, i);
		}
	}
	cout << endl;
	delete[] colorArr;
	delete[] depthArr;
	delete[] parentArr;
}


//prim��С������
template <class T>
void Graph<T>::MST_Prim(const vector<T> &vertexArr, const vector<vector<int>> &adjoinMatrix, const int stratIndex)
{
	int vertexNum = adjoinMatrix.size();
	vector<int> selectedVertex(vertexNum, INF);//����ѱ�ǵĶ����±�  INF��ʾδ���

	selectedVertex[stratIndex] = stratIndex;//��startIndex�±꿪ʼ������С������
	cout << "MST_Prim:" << endl;
	//һ�����vertexNum-1������
	for (size_t it = 1; it < vertexNum; it++)
	{
		pair<int, int> minXY;	//�����СȨ�رߵĻ�ͷ�ͻ�β
		int minWeight = INF;
		for (int i = 0; i < vertexNum; i++)
		{
			if (selectedVertex[i] != INF)
			{
				for (int j = 0; j < vertexNum; j++)
				{
					if (adjoinMatrix[i][j] != 0 && adjoinMatrix[i][j] <= minWeight && selectedVertex[j] == INF)
					{
						minXY.first = i;
						minXY.second = j;
						minWeight = adjoinMatrix[i][j];
					}
				}
			}
		}
		//���δ�ӡ�Ž��������ı���Ϣ
		cout << vertexArr[minXY.first] << "  " << vertexArr[minXY.second] << endl;
		selectedVertex[minXY.second] = minXY.second;//��ǷŽ�������������
	}
}

//�жϵ�ǰ�ڵ����ĸ������У����ؼ��ϵ����
template <class T>
int Graph<T>::searchSet(const vector<set<int>> &vertexSet, int vertex)
{
	for (size_t i = 0; i < vertexSet.size(); i++)
	{
		if (vertexSet[i].find(vertex) != vertexSet[i].end())
		{
			return i;
		}
	}
}

//kruskal��С������
template <class T>
void Graph<T>::MST_Kruskal(const vector<T> &vertexArr, const vector<vector<int>> &adjoinMatrix)
{
	int vertexNum = adjoinMatrix.size();	//���������Ŀ
	vector<set<int>> vertexSet(vertexNum);	//���㻮�ֵļ���  ��ʼ��vertexNum������
	vector<vector<int>> edgeVec;			//���ͼ�����еıߵ���Ϣ

	//װ�����еı���Ϣ
	for (int row = 0; row < vertexNum; row++)
	{
		//��ʼ��  ÿһ������Ϊһ������
		vertexSet[row].insert(row);
		for (int col = row; col < vertexNum; col++)
		{
			if (adjoinMatrix[row][col] != 0 && adjoinMatrix[row][col] != INF)
			{
				vector<int> v;
				v.push_back(row);
				v.push_back(col);
				v.push_back(adjoinMatrix[row][col]);
				edgeVec.push_back(v);
			}
		}
	}
	cout << "MST_Kruskal:" << endl;
	//��ͼ�еı߼�������������
	sort(edgeVec.begin(), edgeVec.end(), Increase);
	for (int i = 0; i < edgeVec.size(); i++)
	{
		//�жϸõ�ǰ�ߵ�����ֱ�������һ������
		int setFristIndex = searchSet(vertexSet, edgeVec[i][0]);
		int setSecondIndex = searchSet(vertexSet, edgeVec[i][1]);
		//��������������ڲ�ͬ�ļ��ϣ�������ñ����ڹ������İ�ȫ��
		if (setFristIndex != setSecondIndex)
		{
			//��ӡ�ñߵ���������Ϣ
			cout << vertexArr[edgeVec[i][0]] << "  " << vertexArr[edgeVec[i][1]] << endl;
			//�ϲ�������
			vertexSet[setFristIndex].insert(vertexSet[setSecondIndex].begin(), vertexSet[setSecondIndex].end());
			vertexSet[setSecondIndex].clear();
		}
	}
}

//Dijkstra���·���㷨
template<class T>
int Graph<T>::findMinPath(const vector<pair<bool, int>> &distanceArr)
{
	int weight = INF;
	int index = -1;
	for (size_t i = 0; i < distanceArr.size(); i++)
	{
		if (distanceArr[i].first == false && distanceArr[i].second <= weight)
		{
			index = i;
			weight = distanceArr[i].second;
		}
	}
	return index;
}
//BellmanFord���·���������ڸ�Ȩ·����ͼ
template<class T>
bool  Graph<T>::MP_BellmanFord(const vector<vector<int>> &adjoinMatrix, const int &startIndex)
{
	int vertexNum = adjoinMatrix.size();
	vector<int> vertexVec(vertexNum, INF);
	vector<int> parentVec(vertexNum, INF);
	vertexVec[startIndex] = 0;
	for (size_t i = 0; i < vertexNum-1; i++)
	{
		//��ÿһ���߶������ɳڣ�һ��ѭ��vertexNum-1��
		for (int row = 0; row < vertexNum; row++)
		{
			for (int col = 0; col < vertexNum; col++)
			{
				if (vertexVec[col] > vertexVec[row] + adjoinMatrix[row][col])
				{
					vertexVec[col] = vertexVec[row] + adjoinMatrix[row][col];
					parentVec[col] = row;
				}
			}
		}
	}
	//����Ƿ���ڸ���·
	for (int row = 0; row < vertexNum; row++)
	{
		for (int col = 0; col < vertexNum; col++)
		{
			if (adjoinMatrix[row][col] != INF)
			{
				if (vertexVec[col] > vertexVec[row] + adjoinMatrix[row][col])
					return false;
			}
		}
	}
	cout << "MP_BellmanFord:" << endl;
	for (size_t i = 0; i < vertexNum; i++)
	{
		cout << vertexVec[i] << "\t";
	}
	cout << endl;
	return true;
}

template<class T>
void  Graph<T>::MP_Dijkstra(const vector<vector<int>> &adjoinMatrix, const int &startIndex)
{
	int vertexNum = adjoinMatrix.size();
	vector<pair<bool, int>> distanceArr(vertexNum);

	//��ʼ�����飬�����д�Ÿ��㵽��ʼ��ľ���͸����Ƿ񱻱��
	for (size_t i = 0; i < vertexNum; i++)
	{
		distanceArr[i].first = false;
		distanceArr[i].second = adjoinMatrix[startIndex][i];
	}
	//װ��Դ��
	distanceArr[startIndex].first = true;
	while (true)
	{
		//Ѱ�ҵ�ǰ�����е���Сֵ
		int minIndex = findMinPath(distanceArr);
		//�������-1  ���Ѱ�����
		if (minIndex == -1)
			break;
		//װ����С���뼯��
		distanceArr[minIndex].first = true;
		//�ɳ�
		for (int j = 0; j < vertexNum; j++)
		{
			if (distanceArr[j].second > distanceArr[minIndex].second + adjoinMatrix[minIndex][j])
				distanceArr[j].second = distanceArr[minIndex].second + adjoinMatrix[minIndex][j];
		}
	}
	//for (int j = 0; j < vertexNum; j++)
	//{
	//	cout << distanceArr[j].second << endl;
	//}
}

template<class T>
void  Graph<T>::MP_Floyd(const vector<vector<int>> &adjoinMatrix, const int &startIndex)
{
	int vertexNum = adjoinMatrix.size();
	vector<vector<int>> vertexVec(adjoinMatrix);

	for (int row = 0; row < vertexNum; row++)
	{
		for (int col = 0; col < vertexNum; col++)
		{
			if(row==col)
				vertexVec[row][col] = 0;
		}
	}

	for (int i = 0; i < vertexNum; i++)
	{
		//��ÿһ���߶������ɳڣ�һ��ѭ��vertexNum-1��
		for (int row = 0; row < vertexNum; row++)
		{
			for (int col = 0; col < vertexNum; col++)
			{
				if (vertexVec[row][col] > vertexVec[row][i] + vertexVec[i][col])
				{
					vertexVec[row][col] = vertexVec[row][i] + vertexVec[i][col];
				}
			}
		}
	}
	cout << "MP_Floyd:" << endl;
	for (int i = 0; i < vertexNum; i++)
	{
		for (int j = 0; j < vertexNum; j++)
		{
			cout << vertexVec[i][j] << "\t";
		}
		cout << endl;
	}
}