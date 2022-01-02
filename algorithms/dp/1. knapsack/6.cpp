#include <bits/stdc++.h>
using namespace std;

// Minimum Subset Sum Difference
// Top-Down
// O(n * sum) time and space

/*
We can actually reduce the space complexity by half...
One observation is: Since only half of the last line is what we need, we can omit the right half of the matrix. 
i.e. we can create matrix of size something like..             
t[ n+1 ][ ceil(sum/2) ]. And yes I have checked this approach, it works fine.
In this you just need to check the last true in the last row of t matrix
and then desired output is total_sum - 2*(col_num_of_last_true).
In this way, we can further reduce complexity( both time and space ) by not creating unnecessary vectors.
*/

int minDifference(int arr[], int n)
{
    int sum = arr[0];
    for (int i = 1; i < n; ++i)
        sum += arr[i];
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    for (int i = 0; i <= n; ++i)
        dp[i][0] = true;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= sum; ++j)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= arr[i - 1])
                dp[i][j] = dp[i][j] || dp[i - 1][j - arr[i - 1]];
        }
    }
    int min = sum;
    for (int i = sum / 2; i >= 0; --i)
    {
        if (!dp[n][i])
            continue;
        min = sum - 2 * i;
        break;
    }
    return min;
    return min;
}