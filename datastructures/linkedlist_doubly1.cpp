#include <iostream>

using namespace std;

struct node {
    int data;
    node* prev;
    node* next;
};

node* head = NULL;

void insert(int pos, int val) {
    if (pos == 0) {
        node* temp = new node;
        temp->prev = NULL;
        temp->data = val;
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
            return;
        }
        head->prev = temp;  // prev field adjusted when there is a node after
                            // the inserted node
        temp->next = head;
        head = temp;
    } else if (head == NULL && pos != 0) {
        cout << "Invalid Position!\n";
        return;
    } else {
        node* temp1 = head;
        for (int i = 0; i < pos - 1; i++) {
            temp1 = temp1->next;
            if (temp1 == NULL) {
                cout << "Invalid Position!\n";
                return;
            }
        }
        node* temp2 = new node;
        temp2->data = val;
        temp2->prev = temp1;
        temp2->next = temp1->next;
        temp1->next = temp2;
        if (temp2->next != NULL) {  // prev field to be adjusted if there is a
                                    // node after inserted node
            node* temp3 = temp2->next;
            temp3->prev = temp2;
        }
    }
}

void print() {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void reverse_print() {
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
}

void delete_node(int pos) {
    if (pos == 0) {
        node* temp = head;
        head = temp->next;
        head->prev = NULL;
        delete temp;
    } else {
        node* temp1 = head;
        for (int i = 0; i < pos - 1; i++) {
            temp1 = temp1->next;
            if (temp1 == NULL) {
                cout << "Invalid Position!\n";
                return;
            }
        }
        if (temp1->next == NULL) {
            cout << "Invalid Position!\n";
            return;
        }
        node* temp2 = new node;
        temp2 = temp1->next;
        temp1->next = temp2->next;
        if (temp2->next != NULL) temp2->next->prev = temp1;
        delete temp2;
    }
}

int main() {
    insert(0, 0);
    print();
    cout << endl;
    reverse_print();
    cout << endl;
    cout << endl;
    insert(1, 1);
    print();
    cout << endl;
    reverse_print();
    cout << endl;
    cout << endl;
    insert(2, 2);
    print();
    cout << endl;
    reverse_print();
    cout << endl;
    cout << endl;
    insert(3, 3);
    print();
    cout << endl;
    reverse_print();
    cout << endl;
    cout << endl;
    insert(4, 4);
    print();
    cout << endl;
    reverse_print();
    cout << endl;
    cout << endl;
    insert(5, 5);
    print();
    cout << endl;
    reverse_print();
    cout << endl;
    cout << endl;
    insert(0, -1);
    print();
    cout << endl;
    reverse_print();
    cout << endl;
    cout << endl;
    insert(2, 10);
    print();
    cout << endl;
    reverse_print();
    cout << endl;
    cout << endl;
    insert(8, 8);
    print();
    cout << endl;
    reverse_print();
    cout << endl;
    cout << endl;
    print();
    cout << endl;
    reverse_print();
    cout << endl;
    cout << endl;

    delete_node(8);
    print();
    cout << endl;
    reverse_print();
    cout << endl;
    cout << endl;
    delete_node(4);
    print();
    cout << endl;
    reverse_print();
    cout << endl;
    cout << endl;
    delete_node(0);
    print();
    cout << endl;
    reverse_print();
    cout << endl;
    cout << endl;

    return 0;
}