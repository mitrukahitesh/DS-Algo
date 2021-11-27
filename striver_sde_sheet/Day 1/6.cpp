#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-the-duplicate-number/solution/
// See explanation from leetcode (C = cycle length, entrance to entrance)
// a = nC - F => after restart, hare is at nC - F + F = nC i.e. at entrance of cycle

int findDuplicate(vector<int> &nums)
{
    int tortoise = nums[0];
    int hare = nums[0];
    do
    {
        tortoise = nums[tortoise];
        hare = nums[nums[hare]];
    } while (tortoise != hare);
    tortoise = nums[0];
    while (tortoise != hare)
    {
        tortoise = nums[tortoise];
        hare = nums[hare];
    }
    return hare;
}