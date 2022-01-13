#include <bits/stdc++.h>
using namespace std;

// Implement queue using array
// Linked list implementation is easy
// Here we use circular array implementation

class Queue
{
private:
    int arr[5];
    int first;
    int last;

public:
    Queue();
    bool empty();
    int front();
    int pop();
    void push(int x);
};

// Initialization
Queue ::Queue()
{
    first = -1;
    last = -1;
}

bool Queue ::empty()
{
    return (first == -1 && last == -1);
}

int Queue ::front()
{
    if (first == -1)
        return -1;
    return arr[first];
}

int Queue ::pop()
{
    if (first == -1)
        return -1;
    // Only one element present
    if (first == last)
    {
        int temp = arr[first];
        first = last = -1;
        return temp;
    }
    int temp = arr[first];
    first = (first + 1) % 5;
    return temp;
}

void Queue ::push(int x)
{
    // Queue is empty
    if (first == -1 && last == -1)
    {
        first++, last++;
        arr[first] = x;
        return;
    }
    // Queue is full
    if ((last + 1) % 5 == first)
        return;
    last = (last + 1) % 5;
    arr[last] = x;
}

int main()
{
    Queue queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    cout << queue.pop() << endl;
    cout << queue.pop() << endl
         << endl;
    queue.push(5);
    queue.push(6);
    queue.push(7);
    while (!queue.empty())
    {
        cout << queue.pop() << endl;
    }
    return 0;
}