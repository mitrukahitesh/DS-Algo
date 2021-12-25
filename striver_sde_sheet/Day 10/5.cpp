#include <bits/stdc++.h>
using namespace std;

// O(4^(n ^ 2)) time
// O(n^2) + O(n^2) space for visited and stack

void findPath(vector<string> &res, string s, vector<vector<int>> &m, int n, int row, int col, vector<vector<bool>> &visited)
{
    if (!m[row][col])
        return;
    if (row == n - 1 && col == n - 1)
    {
        res.push_back(s);
        return;
    }
    visited[row][col] = true;
    if (row + 1 < n && !visited[row + 1][col])
    {
        findPath(res, s + "D", m, n, row + 1, col, visited);
    }
    if (col - 1 >= 0 && !visited[row][col - 1])
    {
        findPath(res, s + "L", m, n, row, col - 1, visited);
    }
    if (col + 1 < n && !visited[row][col + 1])
    {
        findPath(res, s + "R", m, n, row, col + 1, visited);
    }
    if (row - 1 >= 0 && !visited[row - 1][col])
    {
        findPath(res, s + "U", m, n, row - 1, col, visited);
    }
    visited[row][col] = false;
}
vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<string> res;
    string s = "";
    findPath(res, s, m, n, 0, 0, visited);
    return res;
}