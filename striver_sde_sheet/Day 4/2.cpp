#include <bits/stdc++.h>
using namespace std;

/*
    Brute force :
    Using 3 pointer ans binary Search
    - Sort the array
    - i = 0, j = 1 (i + 1 -> n - 3), k = 2 (j + 1 -> n - 2) (3 nested loops)
    - remElement = target - arr[i] - arr[j] - arr[k]
    - binary search on right half of k for remElement
    - For valid quad, push quad to a DS that stores unique quad
    O(n^3 logn + nlogn) time
    O(n) space

    Generalized solution for kSum :
    Take k-2 loops and then perform two sum on right half of array
    O(n^3) + O(nlogn) time
    O(1) space
*/

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> quads;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int target_2 = target - nums[i] - nums[j];
            int low = j + 1, high = n - 1;
            while (low < high)
            {
                int twoSum = nums[low] + nums[high];
                if (twoSum == target_2)
                {
                    vector<int> quad(4);
                    quad[0] = nums[i];
                    quad[1] = nums[j];
                    quad[2] = nums[low];
                    quad[3] = nums[high];
                    quads.push_back(quad);
                    while (low < high && nums[low] == quad[2])
                        ++low;
                    while (low < high && nums[high] == quad[3])
                        --high;
                }
                else if (twoSum < target_2)
                {
                    ++low;
                }
                else
                {
                    --high;
                }
            }
            while (j + 1 < n && nums[j] == nums[j + 1])
                ++j;
        }
        while (i + 1 < n && nums[i] == nums[i + 1])
            ++i;
    }
    return quads;
}
