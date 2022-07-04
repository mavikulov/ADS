#include "Graph.h"

void Graph::addEdge(int v, int u){
	adj[v].push_back(u);
	adj[v].unique();
}

void Graph::BFS(int vertex) {
	queue<int> q;
	vector<bool> visited(vertexes, false);
	visited[vertex] = true;
	q.push(vertex);

	while (!q.empty()) {
		vertex = q.front();
		cout << vertex << " ";
		q.pop();
		for (auto elem : adj[vertex]) {
			if (!visited[elem]) {
				visited[elem] = true;
				q.push(elem);
			}
		}
	}
}

void Graph::DFS(int vertex) {
	vector<bool> visited(vertexes, false);
	stack<int> st;
	st.push(vertex);
	while (!st.empty()) {
		vertex = st.top();
		st.pop();
		if (visited[vertex])
			continue;

		visited[vertex] = true;
		cout << vertex << " ";
		for (auto neighbour : adj[vertex]) {
			if (!visited[neighbour])
				st.push(neighbour);
		}
	}
}

void Graph::PathBFS(int from, int to) {
	queue<int> q;
	vector<bool> visited(vertexes, false);
	if (from == to) {
		cout << from;
		return;
	}

	visited[from] = true;
	q.push(from);

	while (!q.empty()) {
		from = q.front();
		if (from == to) {
			cout << from << " ";
			return;
		}
		cout << from << " ";
		q.pop();
		for (auto elem : adj[from]) {
			if (!visited[elem]) {
				visited[elem] = true;
				q.push(elem);
			}
		}
	}
}

void Graph::PathDFS(int from, int to) {
	vector<bool> visited(vertexes, false);
	stack<int> st;

	if (from == to) {
		cout << from;
		return;
	}

	st.push(from);
	while (!st.empty()) {
		from = st.top();
		st.pop();
		if (visited[from])
			continue;

		visited[from] = true;
		cout << from << " ";
		for (auto neighbour : adj[from]) {
			if (!visited[neighbour])
				st.push(neighbour);
		}
	}
}

ostream& operator << (ostream& output, const Graph& graph) {
	for (int i = 0; i < graph.adj.size(); i++) {
		output << i << " : ";
		for (auto elem : graph.adj[i])
			output << elem << " ";
		output << endl;
	}
	return output;
}