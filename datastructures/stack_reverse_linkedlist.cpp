#include <iostream>

using namespace std;

class linkedlist;

class stack {
   private:
    linkedlist* data;
    stack* next;
    stack* top;

   public:
    stack() {
        top = NULL;
        next = NULL;
    }
    void push(linkedlist* d) {
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
    linkedlist* peek() { return top->data; }
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

class linkedlist {
   private:
    int data;
    linkedlist* next;
    linkedlist* head;

   public:
    linkedlist() {
        head = NULL;
        next = NULL;
    }
    void insert(int d) {
        linkedlist* temp = new linkedlist;
        temp->data = d;
        if (head != NULL) {
            temp->next = head;
        }
        head = temp;
    }
    void reverse() {
        stack s;
        linkedlist* temp = head;
        while (temp != NULL) {
            s.push(temp);
            temp = temp->next;
        }
        head = s.peek();
        s.pop();
        temp = head;
        while (!s.isEmpty()) {
            temp->next = s.peek();
            s.pop();
            temp = temp->next;
        }
        temp->next = NULL;
    }
    void print() {
        linkedlist* temp = head;
        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main() {
    linkedlist l;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);
    l.print();
    l.reverse();
    cout << "\n\n##################################\n\n";
    l.print();
    return 0;
}