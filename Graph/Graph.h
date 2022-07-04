#ifndef _GRAPH_H
#define _GRAPH_H

#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

class Graph {
private:
	int vertexes;
	vector<list<int>> adj;
public:
	Graph(int V) : vertexes(V) {
		adj.resize(vertexes);
	}

	Graph(const Graph& second) : vertexes(second.vertexes) {
		adj.resize(vertexes);
		adj = second.adj;
	}

	void addEdge(int v, int u);
	void BFS(int vertex);
	void DFS(int vertex);
	void PathBFS(int from, int to);
	void PathDFS(int from, int to);
	friend ostream& operator << (ostream& output, const Graph& graph);
};

#endif _GRAPH_H
