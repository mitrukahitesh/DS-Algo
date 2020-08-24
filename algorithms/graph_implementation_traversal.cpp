#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

class Node{
	int vertex;
	int weight;
public:
	Node(int, int = 0);
	bool operator==(Node);
	int getVertex();
};

Node::Node(int v, int w){
	vertex = v;
	weight = w;
}

bool Node::operator==(Node node){
	if(vertex == node.vertex && weight == node.weight)
		return true;
	return false;
}

int Node::getVertex(){
	return vertex;
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
	//BFS from a given source
	void BFS(int);
	//DFS from a given source
	void DFS(int, bool* = NULL);
};

Graph::Graph(){
	N = 5;
	array = new list<Node>[N];
}

Graph::Graph(int n){
	N = n;
	array = new list<Node>[N];
}

void Graph::addEdge(int x, int y, int w){
	list<Node>::iterator it = find(array[x].begin(), array[x].end(), Node(y, w));
	if(it == array[x].end())
		array[x].push_back(Node(y, w));
}

void Graph::removeEdge(int x, int y, int w){
	list<Node>::iterator it = find(array[x].begin(), array[x].end(), Node(y, w));
	if(it != array[x].end())
		array[x].erase(it);
}

void Graph::BFS(int s){
	bool* b = new bool[N];
	for (int i = 0; i < N; ++i){
		b[i] = false;
	}
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		cout << q.front() << " ";
		b[q.front()] = true;
		for (auto it = array[q.front()].begin(); it != array[q.front()].end(); ++it){
			if (!b[(*it).getVertex()]){
				q.push((*it).getVertex());
			}
		}
		q.pop();
	}
}

void Graph::DFS(int s, bool* b){
	if (b == NULL){
		b = new bool[N];
		for (int i = 0; i < N; ++i){
			b[i] = false;
		}
	}
	cout << s << " ";
	b[s] = true;
	for (auto it = array[s].begin(); it != array[s].end(); ++it){
		if (!b[(*it).getVertex()]){
			DFS((*it).getVertex(), b);
		}
	}
}

int main(){
	// Create a graph given in the above diagram 
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
    // g.removeEdge(2, 3);
  
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n"; 
    g.BFS(2);
    cout << endl;

    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n"; 
    g.DFS(2);
    cout << endl;

	return 0;
}