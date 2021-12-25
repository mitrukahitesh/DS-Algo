#include <bits/stdc++.h>
using namespace std;

/**
 * 1. Brute force
 * 
 * 2. Optimal
 *      Use hashing to avoid the inner O(n)s
 *      https://www.geeksforgeeks.org/printing-solutions-n-queen-problem/
 */

// Brute force
void find_solutions(int N, vector<vector<string>> &res, vector<string> &sol, int n, int row)
{
    if (n == 0)
    {
        res.push_back(sol);
        return;
    }
    // O(n^2)
    for (int i = 0; i < N; ++i)
    {
        int j;
        // O(n)
        for (j = row - 1; j >= 0; --j)
        {
            if (sol[j][i] == 'Q')
                break;
        }
        if (j >= 0)
            continue;
        int k;
        // O(n)
        for (j = row, k = i; j >= 0 && k >= 0; --j, --k)
        {
            if (sol[j][k] == 'Q')
                break;
        }
        if (j >= 0 && k >= 0)
            continue;
        // O(n)
        for (j = row, k = i; j >= 0 && k < N; --j, ++k)
        {
            if (sol[j][k] == 'Q')
                break;
        }
        if (j >= 0 && k < N)
            continue;
        sol[row][i] = 'Q';
        find_solutions(N, res, sol, n - 1, row + 1);
        sol[row][i] = '.';
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> res;
    string s;
    for (int i = 0; i < n; ++i)
        s += ".";
    vector<string> sol(n, s);
    find_solutions(n, res, sol, n, 0);
    return res;
}

// Optimal
void find_solutions(int N, vector<vector<string>> &res, vector<string> &sol, int n, int row, vector<bool> &colCheck, vector<bool> &leftDia, vector<bool> &rightDia)
{
    if (n == 0)
    {
        res.push_back(sol);
        return;
    }
    for (int i = 0; i < N; ++i)
    {
        if (colCheck[i] || leftDia[N + i - row] || rightDia[(2 * N - 1) - (i + row)])
            continue;
        sol[row][i] = 'Q';
        colCheck[i] = true;
        leftDia[N + i - row] = true;
        rightDia[(2 * N - 1) - (i + row)] = true;
        find_solutions(N, res, sol, n - 1, row + 1, colCheck, leftDia, rightDia);
        sol[row][i] = '.';
        colCheck[i] = false;
        leftDia[N + i - row] = false;
        rightDia[(2 * N - 1) - (i + row)] = false;
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> res;
    string s;
    for (int i = 0; i < n; ++i)
        s += ".";
    vector<string> sol(n, s);
    vector<bool> colCheck(n, false);
    vector<bool> leftDia(2 * n - 1, false);
    vector<bool> rightDia(2 * n - 1, false);
    find_solutions(n, res, sol, n, 0, colCheck, leftDia, rightDia);
    return res;
}