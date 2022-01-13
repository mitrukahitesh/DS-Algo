#include <bits/stdc++.h>
using namespace std;

// Sort a stack

// Editorial
void sortedInsert(stack<int> &s, int x)
{
    if (s.empty() || s.top() <= x)
    {
        s.push(x);
        return;
    }
    int temp = s.top();
    s.pop();
    sortedInsert(s, x);
    s.push(temp);
}

void sortStack(stack<int> &s)
{
    if (!s.empty())
    {
        int x = s.top();
        s.pop();
        sortStack(s);
        sortedInsert(s, x);
    }
}

// My approach
void sortUtil(stack<int> &s)
{
    if (s.size() < 2)
        return;
    int x = s.top();
    s.pop();
    sortUtil(s);
    if (s.top() > x)
    {
        int temp = s.top();
        s.pop();
        s.push(x);
        s.push(temp);
    }
    else
    {
        s.push(x);
    }
}

void sort(stack<int> &s)
{
    stack<int> res;
    while (!s.empty())
    {
        sortUtil(s);
        res.push(s.top());
        s.pop();
    }
    while (!res.empty())
    {
        s.push(res.top());
        res.pop();
    }
}