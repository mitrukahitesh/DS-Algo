#include <bits/stdc++.h>
using namespace std;

// Rotting Oranges
// https://leetcode.com/problems/rotting-oranges/

// BFS

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == 0)
                    dist[i][j] = 0;
                else if (grid[i][j] == 2)
                {
                    dist[i][j] = 0;
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        while (!q.empty())
        {
            pair<int, int> p = q.front();
            int i = p.first;
            int j = p.second;
            q.pop();
            if (i + 1 < n && !visited[i + 1][j] && dist[i + 1][j] == INT_MAX)
            {
                visited[i + 1][j] = true;
                dist[i + 1][j] = 1 + dist[i][j];
                q.push({i + 1, j});
            }
            if (i - 1 >= 0 && !visited[i - 1][j] && dist[i - 1][j] == INT_MAX)
            {
                visited[i - 1][j] = true;
                dist[i - 1][j] = 1 + dist[i][j];
                q.push({i - 1, j});
            }
            if (j + 1 < m && !visited[i][j + 1] && dist[i][j + 1] == INT_MAX)
            {
                visited[i][j + 1] = true;
                dist[i][j + 1] = 1 + dist[i][j];
                q.push({i, j + 1});
            }
            if (j - 1 >= 0 && !visited[i][j - 1] && dist[i][j - 1] == INT_MAX)
            {
                visited[i][j - 1] = true;
                dist[i][j - 1] = 1 + dist[i][j];
                q.push({i, j - 1});
            }
        }
        int res = INT_MIN;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                res = max(res, dist[i][j]);
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};

// Faster/Cleaner/Memory_efficient approach
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int total = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                    ++total;
                }
                else if (grid[i][j] == 1)
                    ++total;
            }
        }
        int count = 0;
        int time = 0;
        while (!q.empty())
        {
            int k = q.size();
            count += k;
            while (k--)
            {
                pair<int, int> p = q.front();
                int i = p.first;
                int j = p.second;
                q.pop();
                if (i + 1 < n && grid[i + 1][j] == 1)
                {
                    grid[i + 1][j] = 2;
                    q.push({i + 1, j});
                }
                if (i - 1 >= 0 && grid[i - 1][j] == 1)
                {
                    grid[i - 1][j] = 2;
                    q.push({i - 1, j});
                }
                if (j + 1 < m && grid[i][j + 1] == 1)
                {
                    grid[i][j + 1] = 2;
                    q.push({i, j + 1});
                }
                if (j - 1 >= 0 && grid[i][j - 1] == 1)
                {
                    grid[i][j - 1] = 2;
                    q.push({i, j - 1});
                }
            }
            if (!q.empty())
                time++;
        }
        return total == count ? time : -1;
    }
};