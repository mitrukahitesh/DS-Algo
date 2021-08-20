#include <bits/stdc++.h>
using namespace std;

/*
    Brute force :
    O(n^2) time
    O(1) space

    Optimal :
    Merge type
    O(nlogn) + O(n) + O(nlogn) time
    O(n) space
*/

int findPairs(vector<int> &nums, int low, int high)
{
    if (low >= high)
        return 0;
    int mid = low + (high - low) / 2;
    int leftPairs = findPairs(nums, low, mid);
    int rightPairs = findPairs(nums, mid + 1, high);
    int pairs = 0;
    int i = low, j = mid + 1;
    int k = 0;
    while (i <= mid)
    {
        while (j <= high && (double)nums[i] > 2 * (double)nums[j])
        {
            ++j;
        }
        pairs += (j - mid - 1);
        ++i;
    }
    sort(nums.begin() + low, nums.begin() + high + 1);
    return leftPairs + rightPairs + pairs;
}
int reversePairs(vector<int> &nums)
{
    return findPairs(nums, 0, nums.size() - 1);
}