#include <bits/stdc++.h>
using namespace std;

// Count the number of subset with a given difference
// Top-Down
// O(n * sum) time and space
// https://leetcode.com/discuss/interview-question/1271034/count-no-of-subsets-with-given-difference-dp
// Perfect Sum Problem

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

int countWithGivenSum(int arr[], int n, int diff)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    int reqSum = (diff + sum) / 2;
    return perfectSum(arr, n, reqSum);
}

/*
    Let sum of subset 1 be s1 and subset 2 with s2
    s1 - s2 = diff (given)
    s1 + s2=sum of array (logical)
    Therefore adding both eq we get :
    2s1= diff + sum of array
    s1= (diff + sum of array)/2;
    Problem reduces to find no of subsets with given sum**
 */