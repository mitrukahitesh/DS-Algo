#include <bits/stdc++.h>
using namespace std;

// Perfect Sum Problem
// Top-Down
// O(n * sum) time and space

int perfectSum(int arr[], int n, int sum)
{
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    for (int i = 0; i <= n; ++i)
        dp[i][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= sum; ++j)
        {
            if (arr[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - arr[i - 1]]) % 1000000007;
        }
    }
    /**
     * Handles test case:
     * arr = [0 0 0 0 0 0 0 0 1], n = 9, sum = 1
     * Here number of zeroes affect ans so we need to add 2^#zeroes - 1 to final ans
     * nC1 + nC2 + .... + nCn = 2^n - 1
     */
    int zeroes = 0;
    for (int i = 0; i < n; ++i)
    {
        arr[i] == 0 ? ++zeroes : zeroes;
    }
    return (dp[n][sum] + ((long long)pow(2, zeroes) - 1) % 1000000007) % 1000000007;
}