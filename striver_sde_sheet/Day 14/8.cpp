#include <bits/stdc++.h>
using namespace std;

// Online Stock Span
// https://leetcode.com/problems/online-stock-span/

// My approach
class StockSpanner
{
public:
    vector<int> arr;
    stack<int> s;
    StockSpanner()
    {
    }

    int next(int price)
    {
        arr.push_back(price);
        while (!s.empty() && arr[s.top()] <= price)
        {
            s.pop();
        }
        int res = arr.size();
        if (!s.empty())
        {
            res = arr.size() - s.top() - 1;
        }
        s.push(arr.size() - 1);
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

// Better
class StockSpanner
{
public:
    stack<pair<int, int>> s;
    StockSpanner()
    {
    }

    int next(int price)
    {
        int span = 1;
        while (!s.empty() && s.top().first <= price)
        {
            span += s.top().second;
            s.pop();
        }
        s.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */