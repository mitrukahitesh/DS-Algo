#include <limits.h>

#include <iostream>
#include <queue>
using namespace std;

#define V 9

void printSolution(int dist[V]) {
    for (int i = 0; i < V; i++) {
        cout << i << "           " << dist[i] << endl;
    }
}

int minDistance(bool visited[V], int dist[V]) {
    int min = INT_MAX, min_index;
    for (int i = 0; i < V; ++i) {
        if (dist[i] <= min && !visited[i]) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(int graph[V][V], int s) {
    // Keep track of visited nodes or nodes whose shortest distace from source
    // are found
    bool* visited = new bool[V];
    for (int i = 0; i < V; ++i) {
        visited[i] = false;
    }
    // Store the minimum distance from source to the node represented by index
    // number
    int* dist = new int[V];
    for (int i = 0; i < V; ++i) {
        dist[i] = INT_MAX;
    }
    dist[s] = 0;
    for (int k = 0; k < V; ++k) {
        // Select node with minimum distance (GREEDY APPROACH)
        int v = minDistance(visited, dist);
        visited[v] = true;
        // Relaxation
        for (int i = 0; i < V; i++) {
            if (graph[v][i] && !visited[i] && graph[v][i] + dist[v] < dist[i] &&
                dist[v] != INT_MAX)
                dist[i] = graph[v][i] + dist[v];
        }
    }
    printSolution(dist);
}

int main() {
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},  {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},  {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0}, {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},  {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    dijkstra(graph, 0);

    return 0;
}