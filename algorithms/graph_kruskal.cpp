#include <limits.h>

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
    int getWeight();
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

int Node::getWeight() { return weight; }

class Graph {
    int N;
    list<Node>* array;

   public:
    Graph();
    Graph(int);
    void addEdge(int, int, int = 0);
    void removeEdge(int, int, int = 0);
    void kruskal();
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
    /*//For undirected graph
    it = find(array[y].begin(), array[y].end(), Node(x, w));
    if (it == array[y].end())
            array[y].push_back(Node(x, w));*/
}

void Graph::removeEdge(int x, int y, int w) {
    list<Node>::iterator it =
        find(array[x].begin(), array[x].end(), Node(y, w));
    if (it != array[x].end()) array[x].erase(it);
}

class VertexDistance {
   public:
    int from, to, d;
    VertexDistance(int, int, int);
    bool operator<(VertexDistance);
};

VertexDistance::VertexDistance(int from, int to, int d) {
    this->from = from;
    this->to = to;
    this->d = d;
}

bool VertexDistance::operator<(VertexDistance v) {
    if (this->d < v.d) return true;
    return false;
}

int FIND(int* arr, int v) {
    int parent = v;
    while (arr[parent] >= 0) {
        parent = arr[parent];
    }
    return parent;
}

bool UNION(int* arr, int v1, int v2) {
    int p_of_v1 = FIND(arr, v1);
    int p_of_v2 = FIND(arr, v2);
    if (p_of_v1 != p_of_v2) {
        if (arr[p_of_v1] <= arr[p_of_v2]) {
            arr[p_of_v1] = arr[p_of_v1] + arr[p_of_v2];
            arr[p_of_v2] = p_of_v1;
        } else {
            arr[p_of_v2] = arr[p_of_v2] + arr[p_of_v1];
            arr[p_of_v1] = p_of_v2;
        }
        return true;
    }
    return false;
}

void Graph::kruskal() {
    vector<VertexDistance> vec;
    for (int i = 0; i < N; ++i) {
        for (auto it = array[i].begin(); it != array[i].end(); ++it) {
            vec.push_back(
                VertexDistance(i, (*it).getVertex(), (*it).getWeight()));
        }
    }
    sort(vec.begin(), vec.end());
    int* arr = new int[N];
    for (int i = 0; i < N; ++i) {
        arr[i] = -1;
    }
    std::vector<int> from, to, dist;
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        VertexDistance v = (*it);
        int v1 = v.from;
        int v2 = v.to;
        int d = v.d;
        /*cout << v1 << "\t\t" << v2 << "\t\t" << endl;*/
        if (UNION(arr, v1, v2)) {
            from.push_back(v1);
            to.push_back(v2);
            dist.push_back(d);
        }
    }
    for (int i = 0; i < N - 1; ++i) {
        cout << from[i] << "\t\t"
             << "to"
             << "\t\t" << to[i] << "\t\t" << dist[i] << endl;
    }
}

int main() {
    // Create a graph given in the above diagram
    Graph g(9);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    cout << "Following is minimum spanning tree for weighted graph with non - "
            "negative edges\n";
    g.kruskal();

    return 0;
}