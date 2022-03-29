#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "graph.hpp"

using namespace std;

int main()
{
	//图的顶点数组
	vector<char> vertexArr = { 'a', 'b', 'c', 'd', 'e', 'f'};
	//图的邻接矩阵
	vector<vector<int>> adjoinMatrix1 = {
		{  0,    4,  INF,  INF,  INF,  INF,  INF,    8,  INF},
		{  4,    0,    8,  INF,  INF,  INF,  INF,   11,  INF},
		{INF,    8,    0,    7,  INF,    4,  INF,  INF,    2},
		{INF,  INF,    7,    0,    9,   14,  INF,  INF,  INF},
		{INF,  INF,  INF,    9,    0,   10,  INF,  INF,  INF},
		{INF,  INF,    4,   14,   10,    0,    2,  INF,  INF},
		{INF,  INF,  INF,  INF,  INF,    2,    0,    1,    6},
		{  8,   11,  INF,  INF,  INF,  INF,    8,    0,    7},
		{INF,  INF,    2,  INF,  INF,  INF,    6,    7,    0}
	};
	vector<vector<int>> adjoinMatrix2 = {
		{  0,  INF,   10,  INF,   30,  100},
		{INF,    0,    5,  INF,  INF,  INF},
		{INF,  INF,    0,   50,  INF,  INF},
		{INF,  INF,  INF,    0,  INF,   10},
		{INF,  INF,   INF,  20,    0,   60},
		{INF,  INF,  INF,  INF,  INF,    0}
	};

	vector<vector<int>> adjoinMatrix = adjoinMatrix2;
	//创建图
	Graph<char> graph(vertexArr, adjoinMatrix);
	//显示图
	graph.showGraph();

	////Prim算法创建最小生成树
	//graph.MST_Prim(vertexArr, adjoinMatrix, 0);

	////Kruskal算法创建最小生成树
	//graph.MST_Kruskal(vertexArr, adjoinMatrix);


	//MP_Dijkstra运用了广度优先
	graph.MP_Dijkstra(adjoinMatrix, 0);

	//MP_BellmanFord循环vertexNum-1次松弛
	graph.MP_BellmanFord(adjoinMatrix, 0);

	//MP_Floyd引入了其他点松弛  求解所有点之间的相互最短距离
	graph.MP_Floyd(adjoinMatrix, 0);

	return 0;
}

