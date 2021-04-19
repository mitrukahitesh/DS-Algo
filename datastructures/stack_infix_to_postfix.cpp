#include <string.h>

#include <iostream>
#include <sstream>

using namespace std;

class stack {
   private:
    char data;
    stack* next;
    stack* top;

   public:
    stack() {
        top = NULL;
        next = NULL;
    }
    void push(char d) {
        stack* temp = new stack;
        temp->data = d;
        temp->next = NULL;
        if (top != NULL) {
            temp->next = top;
        }
        top = temp;
    }
    void print() {  // this operation is not present in stack
        stack* temp = top;
        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
    char peek() { return top->data; }
    void pop() {
        if (top == NULL) {
            cout << "Stack is empty\n";
            return;
        }
        stack* temp = top;
        top = top->next;
        delete temp;
    }
    bool isEmpty() {
        if (top == NULL) {
            return true;
        } else {
            return false;
        }
    }
};

string convert(string infix) {
    stack s;
    string postfix;
    int len = infix.size();
    for (int i = 0; i < len; i++) {
        if ((infix[i] >= 65 && infix[i] <= 90) ||
            (infix[i] >= 97 && infix[i] <= 122)) {
            postfix = postfix + infix[i];
        } else {
            if (infix[i] == '(') {
                s.push('(');
            } else if (infix[i] == '*' || infix[i] == '/' || infix[i] == '+' ||
                       infix[i] == '-') {
                if (infix[i] == '+' || infix[i] == '-') {
                    while (s.peek() != '(' && !s.isEmpty()) {
                        postfix = postfix + s.peek();
                        s.pop();
                    }
                    s.push(infix[i]);
                } else if (infix[i] == '*' || infix[i] == '/') {
                    while (s.peek() != '(' && !s.isEmpty()) {
                        postfix = postfix + s.peek();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            } else if (infix[i] == ')') {
                while (s.peek() != '(') {
                    postfix = postfix + s.peek();
                    s.pop();
                }
                s.pop();
            }
        }
    }
    while (!s.isEmpty()) {
        postfix = postfix + s.peek();
        s.pop();
    }
    return postfix;
}

int main() {
    string infix = "(((a+b)*c-d)*e)";
    cout << endl << "Postfix of " << infix << " is " << convert(infix) << endl;
    return 0;
}