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
    void prims();
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
    // For undirected graph
    it = find(array[y].begin(), array[y].end(), Node(x, w));
    if (it == array[y].end()) array[y].push_back(Node(x, w));
}

void Graph::removeEdge(int x, int y, int w) {
    list<Node>::iterator it =
        find(array[x].begin(), array[x].end(), Node(y, w));
    if (it != array[x].end()) array[x].erase(it);
}

class VertexDistance {
   public:
    int from, v, d;
};

class Heap {
    VertexDistance* vd;
    int N;
    int end;
    // we can also use an array to keep track of position of vertices in heap
   public:
    Heap(int, int);
    void heapify();
    void heapifyAtN(int);
    VertexDistance top();
    VertexDistance pop();
    void decrease_dist(int, int, int);
    bool empty();
    bool isinHeap(int);
};

Heap::Heap(int n, int s) {
    N = n;
    end = N - 1;
    vd = new VertexDistance[N];
    for (int i = 0; i < N; i++) {
        vd[i].v = i;
        vd[i].from = -1;
        vd[i].d = INT_MAX;
    }
    vd[s].d = 0;
    heapify();
}

void Heap::heapify() {
    int temp = (end - 1) / 2;
    while (temp >= 0) {
        heapifyAtN(temp);
        --temp;
    }
}

void Heap::heapifyAtN(int n) {
    int l = 2 * n + 1;
    int r = 2 * n + 2;
    while (l <= end) {
        if (r > end) {
            if (vd[l].d < vd[n].d) {
                VertexDistance smaller = vd[l];
                vd[l] = vd[n];
                vd[n] = smaller;
            }
            break;
        } else {
            VertexDistance smaller;
            char c;
            if (vd[l].d < vd[r].d) {
                smaller = vd[l];
                c = 'l';
            } else {
                smaller = vd[r];
                c = 'r';
            }
            if (vd[n].d > smaller.d) {
                VertexDistance v = vd[n];
                vd[n] = smaller;
                if (c == 'l') {
                    vd[l] = v;
                    n = l;
                } else {
                    vd[r] = v;
                    n = r;
                }
            } else
                break;
        }
        l = 2 * n + 1;
        r = 2 * n + 2;
    }
}

VertexDistance Heap::top() { return vd[0]; }

VertexDistance Heap::pop() {
    VertexDistance toReturn = vd[0];
    vd[0] = vd[end];
    --end;
    heapifyAtN(0);
    return toReturn;
}

void Heap::decrease_dist(int from, int ver, int dist) {
    for (int i = 0; i <= end; ++i) {
        if (vd[i].v == ver && vd[i].d > dist) {
            vd[i].from = from;
            vd[i].d = dist;
            while ((i - 1) / 2 >= 0) {
                if (vd[i].d < vd[(i - 1) / 2].d) {
                    VertexDistance v = vd[i];
                    vd[i] = vd[(i - 1) / 2];
                    vd[(i - 1) / 2] = v;
                    i = (i - 1) / 2;
                } else {
                    break;
                }
            }
            break;
        }
    }
}

bool Heap::empty() {
    if (end == -1) return true;
    return false;
}

bool Heap::isinHeap(int ver) {
    for (int i = 0; i <= end; ++i) {
        if (vd[i].v == ver) return true;
    }
    return false;
}

void Graph::prims() {
    int s;  // source (edge with minimum value)
    /*int min = INT_MAX;
    int u, v;
    for (int i = 0; i < N; ++i) {
            for (auto it = array[i].begin(); it != array[i].end(); ++it) {
                    if ((*it).getWeight() < min) {
                            min = (*it).getWeight();
                            u = i;
                            v = (*it).getVertex();
                    }
            }
    }
    s = u;*/
    Heap* heap = new Heap(N, 6);  // any other source can be taken
    std::vector<int> from;
    std::vector<int> to;
    std::vector<int> dist;
    while (!heap->empty()) {
        VertexDistance vd = heap->pop();
        int u = vd.v;
        from.push_back(vd.from);
        to.push_back(u);
        dist.push_back(vd.d);
        for (auto it = array[u].begin(); it != array[u].end(); ++it) {
            heap->decrease_dist(u, (*it).getVertex(), (*it).getWeight());
        }
    }
    for (int i = 1; i < N; ++i) {
        cout << from[i] << "\tto\t" << to[i] << "\t\t" << dist[i] << endl;
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

    cout << "Following is minimum spanning tree for weighted graph with "
            "non-negative edges\n";
    g.prims();

    return 0;
}
