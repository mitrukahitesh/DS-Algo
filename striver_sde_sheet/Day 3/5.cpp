#include <bits/stdc++.h>
using namespace std;

/*
    Brute force :
    Recursive solution
    O(exponential) time, since every posssibility is checked
    O(exponential) space, (Stack space)

    Dynamic Programming :
    O(m * n) time, since there is never two same recursive state
    O(m * n) space, for storing states

    Optimal solution (Combinatorics problem) :
    Obs: Number of right and bottom movements is always same for any path
         => Number of steps = m + n - 2 = N (say)
         => Number of paths = NC(m - 1) or NC(n - 1)
         => nCr = n.n-1....n-r+1 / r.r-1....1
    O(m - 1) or O(n - 1) time complexity
    O(1) space
*/

// Dynamic Programming Approach
int paths(int i, int j, int m, int n, vector<vector<int>> &matrix)
{
    if (i > m || j > n)
        return 0;
    if (matrix[i - 1][j - 1] > 0)
        return matrix[i - 1][j - 1];
    if (i == m && j == n)
        return 1;
    matrix[i - 1][j - 1] = paths(i + 1, j, m, n, matrix) + paths(i, j + 1, m, n, matrix);
    return matrix[i - 1][j - 1];
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> matrix(m);
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            matrix[i].push_back(0);
        }
    }
    return paths(1, 1, m, n, matrix);
}

// Optimal solution
long long combn(int N, int x)
{
    long long numr = 1;
    long long denm = 1;
    for (int i = 0; i < x; ++i)
    {
        numr *= (N - i);
        denm *= (i + 1);
    }
    return numr / denm;
}
int uniquePaths(int m, int n)
{
    int N = n + m - 2;
    int x = m < n ? m : n;
    return (int)combn(N, x - 1);
}
