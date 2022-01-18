#include <bits/stdc++.h>
using namespace std;

// Matrix Chain Multiplication
// Recursion + Memoization (Bottom Up)

// Format
int solveFormat(int arr[], int i, int j)
{
    // Smallest invalid input
    if (i > j) // May be different depending on que
        return 0;
    int ans = 0;
    // Range of k may differ
    for (int k = i; k < j; ++k)
    {
        // Calculate temp ans
        // Calculation differs
        int temp_ans = solveFormat(arr, i, k) + solveFormat(arr, k + 1, j);
        ans = max(temp_ans, ans); // Differs
    }
    return ans;
}

// MCM
// O(n^3) time
// O(n^2) space
int solve(int *arr, int i, int j, vector<vector<int>> &dp)
{
    // if i==j only one matrix is there so no multiplication is possible
    if (i >= j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int res = INT_MAX;
    // k = [i, j-1] because at k == j, the array is divided as (i, k (==j)) which is current problem
    // itself and (k + 1(j + 1), j) which returns 0..this causes infinite loop
    for (int k = i; k < j; k++)
    {
        int a = solve(arr, i, k, dp);
        int b = solve(arr, k + 1, j, dp);
        int c = arr[i - 1] * arr[k] * arr[j];
        res = min(res, a + b + c);
    }
    return dp[i][j] = res;
}
int matrixMultiplication(int n, int arr[])
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    // i == 1: first matrix if arr[0]xarr[1]
    // if i == 0: first matrix becomes arr[-1]xarr[0] which is invalid
    return solve(arr, 1, n - 1, dp);
}