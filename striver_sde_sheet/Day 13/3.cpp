#include <bits/stdc++.h>
using namespace std;

// Implement stack using queue
// 1 or 2 queues

class MyStack
{
    queue<int> q;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        q.push(x);
        int size = q.size();
        size--;
        while (size--)
            q.push(q.front()), q.pop();
    }

    int pop()
    {
        int x = q.front();
        q.pop();
        return x;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};