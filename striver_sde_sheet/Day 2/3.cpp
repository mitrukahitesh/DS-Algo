#include <bits/stdc++.h>
using namespace std;

/*
        5
       3 4
      1   2
      2 -> 5 increasing
      5 -> 3 decreasing
      (This pattern is observd in every permutation)
    So for next permutation, we need something that makes prefix 1, 3 greater (like 1, 4 or 1, 5)
    So first we identify 3 (dipping element) and then find the smallest number greater than 3
    by travering from the end of array
    Swap the two and then reverse the array from 5(break point) to end
    
    O(n) + O(n) + O(n) time
    O(1) space 
*/

void nextPermutation(vector<int> &nums)
{
    int dip = -1;
    for (int i = nums.size() - 2; i >= 0; --i)
    {
        if (nums[i] < nums[i + 1])
        {
            dip = i;
            break;
        }
    }
    if (dip == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }
    for (int i = nums.size() - 1; i >= dip; --i)
    {
        if (nums[i] > nums[dip])
        {
            swap(nums[dip], nums[i]);
            reverse(nums.begin() + dip + 1, nums.end());
            return;
        }
    }
}
