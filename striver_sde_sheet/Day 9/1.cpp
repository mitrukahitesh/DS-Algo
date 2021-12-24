#include <bits/stdc++.h>
using namespace std;

/*
    O(2^n) time
    O(2^n) space
*/

// My approach
void find_subsets(vector<int> &ans, vector<int> &arr, int N, int k, int s)
{
    ans.push_back(s);
    for (int i = k; i < N; ++i)
    {
        find_subsets(ans, arr, N, i + 1, s + arr[i]);
    }
}
vector<int> subsetSums(vector<int> arr, int N)
{
    vector<int> ans;
    find_subsets(ans, arr, N, 0, 0);
    return ans;
}

// Tutorial
void find_subsets(vector<int> &ans, vector<int> &arr, int N, int k, int s)
{
    if (k == N)
    {
        ans.push_back(s);
        return;
    }
    // Pick current element
    find_subsets(ans, arr, N, k + 1, s + arr[k]);
    // Do not pick current element
    find_subsets(ans, arr, N, k + 1, s);
}
vector<int> subsetSums(vector<int> arr, int N)
{
    vector<int> ans;
    find_subsets(ans, arr, N, 0, 0);
    return ans;
}