#include <iostream>
#include <limits.h>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

class Node {
	int vertex;
	int weight;
public:
	Node(int, int = 0);
	bool operator==(Node);
	int getVertex();
	int getWeight();
};

Node::Node(int v, int w) {
	vertex = v;
	weight = w;
}

bool Node::operator==(Node node) {
	if (vertex == node.vertex && weight == node.weight)
		return true;
	return false;
}

int Node::getVertex() {
	return vertex;
}

int Node::getWeight() {
	return weight;
}

class Graph
{
	int N;
	list<Node>* array;
public:
	Graph();
	Graph(int);
	void addEdge(int, int, int = 0);
	void removeEdge(int, int, int = 0);
	void bellman_ford(int);
};

Graph::Graph() {
	N = 5;
	array = new list<Node>[N];
}

Graph::Graph(int n) {
	N = n;
	array = new list<Node>[N];
}

void Graph::addEdge(int x, int y, int w) {
	list<Node>::iterator it = find(array[x].begin(), array[x].end(), Node(y, w));
	if (it == array[x].end())
		array[x].push_back(Node(y, w));
	/*//For undirected graph
	it = find(array[y].begin(), array[y].end(), Node(x, w));
	if (it == array[y].end())
		array[y].push_back(Node(x, w));*/
}

void Graph::removeEdge(int x, int y, int w) {
	list<Node>::iterator it = find(array[x].begin(), array[x].end(), Node(y, w));
	if (it != array[x].end())
		array[x].erase(it);
}

void Graph::bellman_ford(int s) {
	int* dist = new int(N);
	for (int i = 0; i < N; ++i) {
		dist[i] = INT_MAX;
	}
	dist[s] = 0;
	for (int k = 0; k < N - 1; ++k) {
		for (int i = 0; i < N; ++i) {
			for (auto it = array[i].begin(); it != array[i].end(); ++it) {
				int j = (*it).getVertex();
				int w = (*it).getWeight();
				if (dist[i] != INT_MAX && dist[i] + w < dist[j]) {
					dist[j] = dist[i] + w;
				}
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		for (auto it = array[i].begin(); it != array[i].end(); ++it) {
			int j = (*it).getVertex();
			int w = (*it).getWeight();
			if (dist[i] != INT_MAX && dist[i] + w < dist[j]) {
				cout << "Graph contains negative cycle!!";
				return ;
			}
		}
	}
	for (int i = 0; i < N; ++i)
	{
		cout << i << "\t\t" << dist[i] << endl;
	}
}

int main() {
	// Create a graph given in the above diagram
	Graph g(5);
	g.addEdge(0, 1, -1);
	g.addEdge(0, 2, 4);
	g.addEdge(1, 2, 3);
	g.addEdge(1, 3, 2);
	g.addEdge(1, 4, 2);
	// g.addEdge(2, 0, -5); //this gives negative cycle
	g.addEdge(3, 2, 5);
	g.addEdge(3, 1, 1);
	g.addEdge(4, 3, -3);

	cout << "Following is single source all dest shortest path using bellman_ford\n";
	g.bellman_ford(4);
	cout << endl;

	return 0;
}

//INT_MAX = 2147483647 && INT_MAX + 1 = -2147483647 due to integer overflow