#include <bits/stdc++.h>
using namespace std;

// O(m^n) time, Checking all colors in all nodes m * m * .... m (n times)
// O(n) + O(n) for arr and stack

bool isValid(bool graph[101][101], int node, vector<int> &arr, int V, int color)
{
    for (int i = 0; i < V; ++i)
    {
        if (graph[node][i] == 1 && arr[i] == color)
            return false;
    }
    return true;
}
bool color(bool graph[101][101], int m, int V, int node, vector<int> &arr)
{
    if (node == V)
        return true;
    for (int i = 0; i < m; ++i)
    {
        if (isValid(graph, node, arr, V, i))
        {
            arr[node] = i;
            if (color(graph, m, V, node + 1, arr))
            {
                return true;
            }
            else
            {
                arr[node] = -1;
            }
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int V)
{
    vector<int> arr(V, -1);
    return color(graph, m, V, 0, arr);
}