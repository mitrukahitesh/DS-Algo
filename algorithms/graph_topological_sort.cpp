#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
using namespace std;

class Node {
    int vertex;
    int weight;

   public:
    Node(int, int = 0);
    bool operator==(Node);
    int getVertex();
};

Node::Node(int v, int w) {
    vertex = v;
    weight = w;
}

bool Node::operator==(Node node) {
    if (vertex == node.vertex && weight == node.weight) return true;
    return false;
}

int Node::getVertex() { return vertex; }

class Graph {
    int N;
    list<Node>* array;

   public:
    Graph();
    Graph(int);
    void addEdge(int, int, int = 0);
    void removeEdge(int, int, int = 0);
    // Topological sort
    void topologicalSort();
    void topologicalSortUtil(int, stack<int>&, bool*);
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
    list<Node>::iterator it =
        find(array[x].begin(), array[x].end(), Node(y, w));
    if (it == array[x].end()) array[x].push_back(Node(y, w));
}

void Graph::removeEdge(int x, int y, int w) {
    list<Node>::iterator it =
        find(array[x].begin(), array[x].end(), Node(y, w));
    if (it != array[x].end()) array[x].erase(it);
}

void Graph::topologicalSort() {
    bool* visited = new bool[N];
    for (int i = 0; i < N; ++i) {
        visited[i] = false;
    }
    stack<int> st;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) topologicalSortUtil(i, st, visited);
    }
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}

void Graph::topologicalSortUtil(int s, stack<int>& st, bool* visited) {
    visited[s] = true;
    for (auto it = array[s].begin(); it != array[s].end(); ++it) {
        if (!visited[(*it).getVertex()])
            topologicalSortUtil((*it).getVertex(), st, visited);
    }
    st.push(s);
}

int main() {
    // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    // g.removeEdge(2, 3);

    cout << "Following is Topological Sort"
            " (starting from vertex 2) \n";
    g.topologicalSort();
    cout << endl;

    return 0;
}