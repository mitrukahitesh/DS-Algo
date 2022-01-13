#include <bits/stdc++.h>
using namespace std;

// Implement stack using array

class Stack
{
private:
    int arr[1000];
    int last;

public:
    Stack();
    bool empty();
    int top();
    int pop();
    void push(int x);
};

Stack ::Stack()
{
    last = -1;
}

bool Stack ::empty()
{
    return last == -1;
}

int Stack ::top()
{
    if (last == -1)
        return -1;
    return arr[last];
}

int Stack ::pop()
{
    if (last == -1)
        return -1;
    return arr[last--];
}

void Stack ::push(int x)
{
    arr[++last] = x;
}

int main()
{
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    while (!stack.empty())
    {
        cout << stack.pop() << endl;
    }
    return 0;
}