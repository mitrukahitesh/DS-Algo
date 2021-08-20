#include <bits/stdc++.h>
using namespace std;

/*
    Brute force :
    O(n2) time
    O(1) space

    Better :
    Hashmap
    O(nlogn) time (using ordered hashmap)
    O(n) space

    Optimal :
    Boyer Moore Voting Algorithm
    At max we can have 2 majority elements and 0 minimum
    O(n) + O(n) time
    O(1) space
*/

vector<int> majorityElement(vector<int> &nums)
{
    int num1 = -1, num2 = -1;
    int count1 = 0, count2 = 0;
    for (auto it : nums)
    {
        if (it == num1)
        {
            ++count1;
        }
        else if (it == num2)
        {
            ++count2;
        }
        else if (count1 == 0)
        {
            num1 = it;
            ++count1;
        }
        else if (count2 == 0)
        {
            num2 = it;
            ++count2;
        }
        else
        {
            --count1;
            --count2;
        }
    }
    vector<int> ans;
    count1 = 0;
    count2 = 0;
    for (auto it : nums)
    {
        if (it == num1)
            ++count1;
        else if (it == num2)
            ++count2;
    }
    if (count1 > nums.size() / 3)
        ans.push_back(num1);
    if (count2 > nums.size() / 3)
        ans.push_back(num2);
    return ans;
}
