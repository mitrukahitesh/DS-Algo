#include <iostream>

using namespace std;

class stack {
   private:
    int size;
    int* arr = new int[5];
    int top;

   public:
    stack() {
        size = 5;
        top = -1;
    }
    void push(int x) {
        if (top == size - 1) {
            int temp_arr[2 * size];
            for (int i = 0; i < size; i++) {
                temp_arr[i] = arr[i];
            }
            size = 2 * size;
            delete[] arr;
            arr = temp_arr;
        }
        top = top + 1;
        arr[top] = x;
    }
    void pop() { top = top - 1; }
    int peek() { return arr[top]; }
    bool isEmpty() {
        if (top == -1) return true;
        return false;
    }
};

int main() {
    stack s1;
    s1.push(1);
    s1.push(2);
    s1.pop();
    cout << s1.peek() << endl;
    s1.pop();
    if (s1.isEmpty()) {
        cout << "Stack is empty\n";
    }
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.push(6);
    s1.push(7);
    s1.push(8);
    s1.push(9);
    s1.push(10);
    s1.push(11);
    s1.push(12);
    s1.push(13);
    s1.push(14);
    s1.push(15);
    s1.push(16);
    cout << s1.peek() << endl;
    return 0;
}