#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
#include<queue>

using namespace std;

#define MAX_VERTEX	100		//定义最多的节点数目
#define INF			65535	//定义无穷大  边是未连接顶点之间的关系
#define NIL			-1		//表示该节点无双亲

enum colorType { WHITE, GRAY, BLACK };
//图的边结构体
struct EdgeNode {
	int vertexIndex;			//顶点的坐标信息
	int edgeWeight;				//边的权值信息
	EdgeNode *nextEdgeNode;		//下一条边的地址
	/*两个构造函数*/
	EdgeNode() {}
	EdgeNode(int _vertexIndex, int _edgeWeight) :vertexIndex(_vertexIndex), edgeWeight(_edgeWeight), nextEdgeNode(NULL) {}
};

//图的顶点结构体
template<class T>
struct VertexNode {
	T vertex;					//当前顶点值
	EdgeNode *firstEdgeNode;	//第一条边的地址
	/*两个构造函数*/
	VertexNode() {}
	VertexNode(T _vertex) :vertex(_vertex), firstEdgeNode(NULL) {}
};

//排序函数规则定义，sort调用
bool Increase(vector<int> v1, vector<int> v2)
{
	return v1[2] < v2[2];
}

template <class T>
/*无向权重图类*/
class Graph
{
public:
	/*两个构造函数*/
	Graph() {}
	/*   vertexArr:顶点数组   adjoinMatrix:邻接矩阵  */
	Graph(const vector<T> vertexArr, const vector<vector<int>> adjoinMatrix);
	~Graph();		//图的析构函数

	void showGraph();				//显示图

	/*图搜索算法*/
	void DFS(const Graph<T> &graph);				//深度优先搜索
	void BFS(const Graph<T> &graph, const int s);	//广度优先搜索

	/*最小生成树算法*/
	void MST_Prim(const vector<T> &vertexArr, const vector<vector<int>> &adjoinMatrix, const int stratIndex);	//prim最小生成树
	void MST_Kruskal(const vector<T> &vertexArr, const vector<vector<int>> &adjoinMatrix);	//kruskal最小生成树

	/*最短路径*/
	bool  MP_BellmanFord(const vector<vector<int>> &adjoinMatrix, const int &startIndex);	//BellmanFord算法
	void  MP_Dijkstra(const vector<vector<int>> &adjoinMatrix, const int &startIndex);		//Dijkstra算法
	void  MP_Floyd(const vector<vector<int>> &adjoinMatrix, const int &startIndex);			//Floyd算法

	VertexNode<T> **adjoinList;		//顶点数组pointer
	int vertexNum, edgeNum;			//图中顶点总数和边的总数

private:
	//创建邻接链表
	EdgeNode *createEdgeList(const vector<int> arr, int index);
	//删除邻接链表
	void deleteList(EdgeNode *Node);
	//判断当前节点在哪个集合中，返回集合的序号
	int searchSet(const vector<set<int>> &vertexSet, int vertex);
	void DFSvisit(const Graph<T> &graph, const int u);

	int findMinPath(const vector<pair<bool, int>> &distanceArr);
	//用于搜索
	int *colorArr, *depthArr, *parentArr;
	int time;
};

/*   Graph的参数构造函数   */
/*   vertexArr:顶点数组   adjoinMatrix:邻接矩阵  */
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

//图的析构函数
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

//显示图
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

//创建邻接链表
template <class T>
EdgeNode* Graph<T>::createEdgeList(const vector<int> arr, int index)
{
	EdgeNode *firstNode = NULL;

	if (index >= arr.size())
		return firstNode;
	//寻找边，当arr[index]==0表示无边连接
	while (arr[index] == 0 || arr[index] == INF)
	{
		index++;
		if (index >= arr.size())
			return firstNode;
	}
	/*递归创建节点*/
	firstNode = new EdgeNode(index, arr[index]);
	firstNode->nextEdgeNode = createEdgeList(arr, index + 1);
	return firstNode;
}

//删除邻接链表
template <class T>
void Graph<T>::deleteList(EdgeNode *Node)
{
	if (Node == NULL)
		return;
	deleteList(Node->nextEdgeNode);
	delete Node;
}

//广度优先搜索，可获得无权图的最短路径
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

	//定义当前队列
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

//深度优先图的搜索
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
//深度优先搜索
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


//prim最小生成树
template <class T>
void Graph<T>::MST_Prim(const vector<T> &vertexArr, const vector<vector<int>> &adjoinMatrix, const int stratIndex)
{
	int vertexNum = adjoinMatrix.size();
	vector<int> selectedVertex(vertexNum, INF);//存放已标记的顶点下标  INF表示未标记

	selectedVertex[stratIndex] = stratIndex;//从startIndex下标开始生成最小生成树
	cout << "MST_Prim:" << endl;
	//一次添加vertexNum-1个顶点
	for (size_t it = 1; it < vertexNum; it++)
	{
		pair<int, int> minXY;	//存放最小权重边的弧头和弧尾
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
		//依次打印放进生成树的边信息
		cout << vertexArr[minXY.first] << "  " << vertexArr[minXY.second] << endl;
		selectedVertex[minXY.second] = minXY.second;//标记放进生成树的坐标
	}
}

//判断当前节点在哪个集合中，返回集合的序号
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

//kruskal最小生成树
template <class T>
void Graph<T>::MST_Kruskal(const vector<T> &vertexArr, const vector<vector<int>> &adjoinMatrix)
{
	int vertexNum = adjoinMatrix.size();	//顶点的总数目
	vector<set<int>> vertexSet(vertexNum);	//顶点划分的集合  初始化vertexNum个集合
	vector<vector<int>> edgeVec;			//存放图中所有的边的信息

	//装载所有的边信息
	for (int row = 0; row < vertexNum; row++)
	{
		//初始化  每一个顶点为一个集合
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
	//对图中的边集进行升序排序
	sort(edgeVec.begin(), edgeVec.end(), Increase);
	for (int i = 0; i < edgeVec.size(); i++)
	{
		//判断该当前边的两点分别属于哪一个集合
		int setFristIndex = searchSet(vertexSet, edgeVec[i][0]);
		int setSecondIndex = searchSet(vertexSet, edgeVec[i][1]);
		//如果两个顶点属于不同的集合，则表明该边属于构成树的安全边
		if (setFristIndex != setSecondIndex)
		{
			//打印该边的两顶点信息
			cout << vertexArr[edgeVec[i][0]] << "  " << vertexArr[edgeVec[i][1]] << endl;
			//合并两集合
			vertexSet[setFristIndex].insert(vertexSet[setSecondIndex].begin(), vertexSet[setSecondIndex].end());
			vertexSet[setSecondIndex].clear();
		}
	}
}

//Dijkstra最短路径算法
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
//BellmanFord最短路径，适用于负权路径的图
template<class T>
bool  Graph<T>::MP_BellmanFord(const vector<vector<int>> &adjoinMatrix, const int &startIndex)
{
	int vertexNum = adjoinMatrix.size();
	vector<int> vertexVec(vertexNum, INF);
	vector<int> parentVec(vertexNum, INF);
	vertexVec[startIndex] = 0;
	for (size_t i = 0; i < vertexNum-1; i++)
	{
		//对每一条边都进行松弛，一共循环vertexNum-1次
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
	//检查是否存在负回路
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

	//初始化数组，数组中存放各点到起始点的距离和各点是否被标记
	for (size_t i = 0; i < vertexNum; i++)
	{
		distanceArr[i].first = false;
		distanceArr[i].second = adjoinMatrix[startIndex][i];
	}
	//装载源点
	distanceArr[startIndex].first = true;
	while (true)
	{
		//寻找当前距离中的最小值
		int minIndex = findMinPath(distanceArr);
		//如果返回-1  则点寻找完成
		if (minIndex == -1)
			break;
		//装载最小点入集合
		distanceArr[minIndex].first = true;
		//松弛
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
		//对每一条边都进行松弛，一共循环vertexNum-1次
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