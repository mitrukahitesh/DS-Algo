#include <bits/stdc++.h>
using namespace std;

/**
 * Pick the first digit of kth permutation
 * O(n^2) time
 * O(n) space 
 */

// O(n^2)
string getPermutationUtil(vector<int> arr, int k, long long int fac)
{
    if (arr.size() == 0)
        return "";
    long long int n_fac = fac / arr.size();
    int ind = k / n_fac;
    string s = to_string(arr[ind]);
    // O(n)
    arr.erase(arr.begin() + ind);
    return s + getPermutationUtil(arr, k % n_fac, n_fac);
}
string getPermutation(int n, int k)
{
    vector<int> arr;
    // O(n)
    for (int i = 0; i < n; ++i)
        arr.push_back(i + 1);
    long long int fac = 1;
    // O(n)
    for (int i = 1; i <= n; ++i)
        fac *= i;
    return getPermutationUtil(arr, --k, fac);
}