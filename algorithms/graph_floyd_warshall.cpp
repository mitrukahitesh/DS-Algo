#include <limits.h>

#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
using namespace std;

#define INF INT_MAX
#define V 4

void floyd_warshall(int graph[V][V]) {
    int dist[V][V];
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            dist[i][j] = graph[i][j];
        }
    }
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            for (int k = 0; k < V; k++) {
                if (dist[j][k] > (dist[j][i] + dist[i][k]) &&
                    (dist[j][i] != INF && dist[i][k] != INF))
                    dist[j][k] = dist[j][i] + dist[i][k];
            }
        }
    }
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INF)
                cout << "INF"
                     << "\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    /* Let us create the following weighted graph
            10
    (0)------->(3)
        |     /|\
    5 |     |
        |     | 1
    \|/     |
    (1)------->(2)
            3     */
    int graph[V][V] = {{0, 5, INF, 10},
                       {INF, 0, 3, INF},
                       {INF, INF, 0, 1},
                       {INF, INF, INF, 0}};

    // Print the solution
    floyd_warshall(graph);

    return 0;
}