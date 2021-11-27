#include <bits/stdc++.h>
using namespace std;

/*
    Brute force :
    Count number of each elements
    O(n2) time
    O(1) space

    Another:
    Traverse and keep count in map
    For any instance if count exceeds n/2, that's the ans
    O(n) time
    O(n) space

    Another :
    Sort and count
    O(nlogn) time
    O(1) space

    Optimal :
    Boyer-Moore Voting Algorithm
    Select element and keep increasing count whenever we found that element and 
    decrease when we found other element
    O(n) time
    O(1) space
*/

int majorityElement(vector<int> &nums)
{
    int count = 0;
    int el = 0;
    for (auto it : nums)
    {
        if (count == 0)
        {
            el = it;
        }
        if (el == it)
        {
            ++count;
        }
        else
        {
            --count;
        }
    }
    return el;
}