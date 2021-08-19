#include <bits/stdc++.h>
using namespace std;

// Know input range
// Brute force => traverse, if 0, change all value (except 0) in that row/column to -1
// (or value that is not possible in input) then change all -1 to 0
// O((n * m) * (n + m)) time, O(1) space

// Another approach
// O(2 * (n * m)) time
// O(n + m) space
void setZeroes(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> row(m, -1);
    vector<int> column(n, -1);
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 0;
                column[j] = 0;
            }
        }
    }
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (row[i] == 0 || column[j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

// Optimal
// We take dummy matrix inside 2D matrix itself
// O(2 * m * n) time
// O(1) space
void setZeroes(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    bool col = false;
    for (int i = 0; i < m; ++i)
    {
        if (matrix[i][0] == 0)
        {
            col = true;
        }
        for (int j = 1; j < n; ++j)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for (int i = m - 1; i >= 0; --i)
    {
        for (int j = n - 1; j > 0; --j)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
        if (col)
            matrix[i][0] = 0;
    }
}
