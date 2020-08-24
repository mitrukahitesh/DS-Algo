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
	void oneSource_allDest(int);
	int* oneSource_allDest_copy(int, int);
	void sourceDest(int, int);
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

void Graph::oneSource_allDest(int s){
	int* distance = new int[N];
	int* prev = new int[N];
	for (int i = 0; i < N; ++i){
		distance[i] = -1;
	}
	for (int i = 0; i < N; ++i){
		prev[i] = -1;
	}
	distance[s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for (auto it = array[v].begin(); it != array[v].end(); ++it){
			if (distance[(*it).getVertex()] == -1){
				distance[(*it).getVertex()] = distance[v] + 1;
				prev[(*it).getVertex()] = v;
				q.push((*it).getVertex());
			}
		}
	}
	for (int i = 0; i < N; ++i){
		cout << distance[i] << " ";
	}
}

int* Graph::oneSource_allDest_copy(int s, int d){
	int* distance = new int[N];
	int* prev = new int[N];
	for (int i = 0; i < N; ++i){
		distance[i] = -1;
	}
	for (int i = 0; i < N; ++i){
		prev[i] = -1;
	}
	distance[s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for (auto it = array[v].begin(); it != array[v].end(); ++it){
			if (distance[(*it).getVertex()] == -1){
				distance[(*it).getVertex()] = distance[v] + 1;
				prev[(*it).getVertex()] = v;
				q.push((*it).getVertex());
				if ((*it).getVertex() == d)
					return prev;
			}
		}
	}
	return NULL;
}

void Graph::sourceDest(int s, int d){
	int* prev = oneSource_allDest_copy(s, d);
	if (prev == NULL){
		cout << "Path does not exist";
		return ;
	}
	stack<int> st;
	st.push(d);
	while (prev[d] != -1){
		st.push(prev[d]);
		d = prev[d];
	}
	while (!st.empty()){
		cout << st.top() << " ";
		st.pop();
	}
}

int main(){
	// Create a graph given in the above diagram 
    Graph g(8); 
	g.addEdge(0, 1); 
	g.addEdge(0, 3); 
	g.addEdge(1, 2); 
	g.addEdge(3, 4); 
	g.addEdge(3, 7); 
	g.addEdge(4, 5);
	g.addEdge(4, 6);
	g.addEdge(4, 7);
	g.addEdge(5, 6);
	g.addEdge(6, 7); 
    g.removeEdge(2, 3);

    cout << "Following is Single source shortest path"
            " (starting from vertex 2) \n";
    g.oneSource_allDest(0);
    cout << endl;

    cout << "Following is Single source single destination shortest path"
            " (starting from vertex 0 to vertex 6) \n";
    g.sourceDest(0, 6);
    cout << endl;

	return 0;
}