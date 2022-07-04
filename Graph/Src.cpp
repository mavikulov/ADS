#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include "Graph.h"


using namespace std;


int main() {
	setlocale(LC_ALL, "Russian");
	Graph example(8);
	example.addEdge(0, 1);
	example.addEdge(0, 2);
	example.addEdge(1, 3);
	example.addEdge(1, 4);
	example.addEdge(2, 5);
	example.addEdge(2, 6);
	example.addEdge(3, 7);
	
	cout << example;
	Graph copy(example);
	cout << "Копия" << endl;
	cout << example;
	cout << endl << endl;

	example.BFS(0);
	cout << endl;
	example.DFS(0);
	cout << endl;

	cout << "Найдем путь от вершины 1 до вершины 7 с помощью поиска в ширину" << endl;
	example.PathBFS(1, 7);
	cout << endl;

	cout << "Найдем путь от вершины 2 до вершины 7 с помощью поиска в ширину" << endl;
	example.PathBFS(2, 7);
	return 0;
}