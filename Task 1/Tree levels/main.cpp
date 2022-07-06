#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <locale.h>


using namespace std;


class Graph {
private:
	int vertexes;
	vector<list<int>> adj;
public:
	Graph(int v) : vertexes(v) {
		adj.resize(v);
	}
	void addEdge(int v, int u) {
		adj[v].push_back(u);
		adj[u].push_back(v);
		adj[v].unique();
		adj[u].unique();
	}

	unsigned int BFS(int start, int l) {
		vector<bool> visited(vertexes, false);
		int *level = new int[vertexes, 0];
		queue<int> q;

		visited[start] = true;
		q.push(start);
		level[start] = 0;

		while (!q.empty()) {
			start = q.front();
			q.pop();
			for (auto i = adj[start].begin(); i != adj[start].end(); ++i) {
				if (!visited[*i]) {
					level[*i] = level[start] + 1;
					visited[*i] = true;
					q.push(*i);
				}
			}
		}

		unsigned int count = 0;
		for (int i = 0; i < vertexes; i++) {
			if (level[i] == l)
				count++;
		}
		return count;
	}

	friend ostream& operator << (ostream& output, const Graph& graph) {
		for (int i = 0; i < graph.vertexes; i++) {
			output << i << ": ";
			for (auto elem : graph.adj[i])
				output << elem << " ";
			output << endl;
		}
		return output;
	}
};


int main() {
	setlocale(LC_ALL, "Russian");
	Graph g(6);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 4);
	g.addEdge(2, 5);
	cout << g;

	cout << " ол-во вершин на уровне 2, начина€ от вершины 0 = ";
	cout << g.BFS(0, 2) << endl;
	return 0;
}