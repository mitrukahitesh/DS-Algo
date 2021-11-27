#include <bits/stdc++.h>
using namespace std;

/*
    Brute force :
    Sort and traverse
    O(nlogn) + O(n) time
    O(1) space

    Optimal :
    We only attempt to build sequences from numbers that are not already part of a longer sequence
    O(n) + O(n) + O(n) time
    O(n) space
*/

// Optimal solution
int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> s;
    for (auto it : nums)
    {
        s.insert(it);
    }
    int max = 0;
    int count = 1;
    for (auto it : nums)
    {
        if (s.find(it - 1) == s.end())
        {
            int x = it + 1;
            while (s.find(x) != s.end())
            {
                ++count;
                ++x;
            }
        }
        if (count > max)
            max = count;
        count = 1;
    }
    return max;
}
