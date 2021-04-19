#include <string.h>

#include <iostream>

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

int main() {
    stack st;
    string s;
    cout << "Enter string:\n";
    getline(cin, s);
    int len = s.size();
    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        }
        if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (st.peek() == '(' && s[i] == ')')
                st.pop();
            else if (st.peek() == '{' && s[i] == '}')
                st.pop();
            else if (st.peek() == '[' && s[i] == ']')
                st.pop();
            else
                break;
        }
    }
    if (st.isEmpty()) {
        cout << "Parentheses are balanced.\n";
    } else {
        cout << "Parantheses are not balanced.\n";
    }
    return 0;
}