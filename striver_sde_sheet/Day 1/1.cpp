#include <bits/stdc++.h>
using namespace std;

// Dutch National Flag Algorithm
// Three pointers -> low, mid, high
// [0,..low-1] = 0 and [high+1,...] = 2
// low mid initially points to 0 and high to n-1
// move mid until it crosses high
// O(n) time -> just one pass
// O(1) space

void sortColors(vector<int> &nums)
{
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            nums[mid] = nums[low];
            nums[low] = 0;
            ++low;
            ++mid;
        }
        else if (nums[mid] == 2)
        {
            nums[mid] = nums[high];
            nums[high] = 2;
            --high;
        }
        else
        {
            ++mid;
        }
    }
}