#include <iostream>

using namespace std;

struct node {
    int data;
    node* next;
};

node* head;

void insert(int val, int pos) {
    node* temp = new node;
    if (pos == 0) {
        temp->data = val;
        temp->next = head;
        head = temp;
    } else {
        node* temp1 = new node;
        temp = head;
        if (temp == NULL && pos != 0) {
            cout << "Invalid position..\n";
            return;
        }
        int i;
        for (i = 0; i < pos - 1; i++) {
            temp = temp->next;
            if (temp == NULL && i < pos - 2) {
                cout << "Invalid position..\n";
                return;
            }
        }
        temp1->data = val;
        temp1->next = temp->next;
        temp->next = temp1;
    }
}

void print() {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void dlt_val(int pos) {
    if (pos == 0) {
        if (head == NULL) {
            cout << "Invalid position...\n";
            return;
        } else {
            node* temp1 = new node;
            temp1 = head;
            head = temp1->next;
            delete temp1;
        }
    } else {
        node* temp1 = new node;
        temp1 = head;
        if (head == NULL) {
            cout << "Invalid position...\n";
            return;
        }
        int i;
        for (i = 0; i < pos - 1; i++) {
            temp1 = temp1->next;
            if (temp1 == NULL && i < pos - 2) {
                cout << "Invalid position...\n";
                return;
            }
        }
        node* temp = temp1->next;
        temp1->next = temp->next;
        delete temp;
    }
}

void reverse_node() {
    node* temp1 = head;  // current node
    node* prev = NULL;   // previous node
    node* temp3 = NULL;  // used to transverse to next node
    while (temp1 != NULL) {
        temp3 = temp1->next;  // stores address to next node
        temp1->next = prev;   // updates the (next) value of current node
        prev = temp1;  // sets current node to previous for which is stores in
                       // (next) of next node
        temp1 = temp3;  // transverse to next node
    }
    head = prev;
}

void print_recursive(node* p) {
    if (p == NULL) {
        cout << "\n";
        return;
    } else {
        cout
            << p->data
            << " ";  // first print then recursive call to print in normal order
        print_recursive(p->next);
    }
}

void print_reverse_recursive(node* p) {
    if (p == NULL) {
        return;
    } else {
        print_reverse_recursive(
            p->next);  // first call then print to print in reverse order
        cout << p->data << " ";
    }
}

int main() {
    head = NULL;

    insert(0, 0);  // 0
    print();
    cout << "\n";

    insert(1, 1);  // 0 1
    print();
    cout << "\n";

    insert(2, 2);  // 0 1 2
    print();
    cout << "\n";

    insert(4, 3);  // 0 1 2 4
    print();
    cout << "\n";

    insert(5, 4);  // 0 1 2 4 5
    print();
    cout << "\n";

    insert(6, 5);  // 0 1 2 4 5 6
    print();
    cout << "\n";

    insert(3, 3);  // 0 1 2 3 4 5 6
    print();
    cout << "\n";

    insert(-1, 0);  //-1 0 1 2 3 4 5 6
    print();
    cout << "\n";

    dlt_val(0);  // 0 1 2 3 4 5 6
    print();
    cout << "\n";

    dlt_val(3);  // 0 1 2 4 5 6
    print();
    cout << "\n";

    dlt_val(5);  // 0 1 2 4 5
    print();
    cout << "\n";

    reverse_node();  // 5 4 2 1 0
    print();
    cout << "\n";

    node* for_recursion = head;

    print_recursive(for_recursion);  // 5 4 2 1 0

    print_reverse_recursive(for_recursion);  // 0 1 2 4 5

    return 0;
}