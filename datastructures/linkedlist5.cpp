#include <iostream>

using namespace std;

struct node;

node* head = NULL;

struct node {
    int data;
    node* next;
};

void insert(int pos, int val) {
    if (pos == 0) {
        node* temp = new node;
        temp->data = val;
        temp->next = head;
        head = temp;
    } else if (head == NULL && pos != 0) {
        cout << "Invalid position!\n";
    } else {
        node* temp1 = head;
        for (int i = 0; i < pos - 1; i++) {
            temp1 = temp1->next;
            if (temp1 == NULL) {
                cout << "Invalid position!\n";
                return;
            }
        }
        node* temp2 = new node;
        temp2->data = val;
        temp2->next = temp1->next;
        temp1->next = temp2;
    }
}

void delete_node(int pos) {
    if (pos == 0) {
        node* temp = head;
        head = temp->next;
        delete temp;
    } else {
        node* temp1 = head;
        for (int i = 0; i < pos - 1; i++) {
            temp1 = temp1->next;
            if (temp1 == NULL) {
                cout << "Invalid position!\n";
                return;
            }
        }
        if (temp1->next == NULL) {
            cout << "Invalid position!\n";
            return;
        }
        node* temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
    }
}

void print() {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void recursive_print(node* p) {
    if (p == NULL) {
        return;
    }
    cout << p->data << " ";
    recursive_print(p->next);
}

void reverse_print(node* p) {
    if (p == NULL) {
        return;
    }
    reverse_print(p->next);
    cout << p->data << " ";
}

void reverse_iterative() {
    node* curr = head;
    node* prev = NULL;
    node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void reverse_recursive(node* p) {
    if (p->next == NULL) {
        head = p;
        return;
    }
    reverse_recursive(p->next);
    p->next->next = p;
    p->next = NULL;
}

int main() {
    insert(0, 0);
    insert(1, 1);
    insert(2, 2);
    insert(3, 3);
    insert(4, 4);
    insert(5, 6);
    insert(6, 7);
    insert(0, -1);
    insert(5, 5);
    insert(7, 8);

    print();  //-1 0 1 2 3 5 4 8 6 7
    cout << "\n";
    node* for_recursion = head;
    recursive_print(for_recursion);  //-1 0 1 2 3 5 4 8 6 7
    cout << "\n";
    reverse_print(for_recursion);  // 7 6 8 4 5 3 2 1 0 -1
    cout << "\n";

    delete_node(0);  // 0 1 2 3 5 4 8 6 7
    delete_node(5);  // 0 1 2 3 5 8 6 7
    delete_node(7);  // 0 1 2 3 5 8 6

    reverse_iterative();
    print();  // 6 8 5 3 2 1 0
    cout << "\n";
    for_recursion = head;
    reverse_recursive(for_recursion);  // 0 1 2 3 5 8 6
    print();

    return 0;
}