#include <bits/stdc++.h>
using namespace std;

// Target Sum
// Top-Down
// O(n * sum) time and space

/*
    x - (SUM - x) = target
    x = (SUM + target) / 2
    Similar to QUES 7
*/

int findWays(vector<int> &arr, int n, int sum)
{
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    for (int i = 0; i <= n; ++i)
        dp[i][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= sum; ++j)
        {
            if (arr[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}
int findTargetSumWays(vector<int> &A, int target)
{
    int sum = 0;
    for (int i = 0; i < A.size(); ++i)
        sum += A[i];
    if ((sum + target) % 2)
        return 0;
    return findWays(A, A.size(), (sum + target) / 2);
}