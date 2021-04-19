#include <iostream>

using namespace std;

class queue {
   private:
    int data;
    queue* next;
    queue* head;
    queue* tail;

   public:
    queue() {
        next = NULL;
        head = NULL;
        tail = NULL;
    }
    void Enqueue(int x) {
        queue* temp = new queue;
        temp->data = x;
        temp->next = NULL;
        if (head == NULL && tail == NULL) {
            head = temp;
            tail = temp;
            return;
        }
        tail->next = temp;
        tail = temp;
    }
    void Dequeue() {
        queue* temp = head;
        if (head == tail) {
            head = NULL;
            tail = NULL;
            delete temp;
            return;
        }
        head = head->next;
        delete temp;
    }
    int peek() {
        if (head == NULL) {
            cout << "queue is empty- returned value is garbage value";
            return head->data;
        }
        return head->data;
    }
    bool isEmpty() {
        if (head == NULL && tail == NULL) return true;
        return false;
    }
    void print() {  // for checking purpose only
        queue* temp = head;
        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main() {
    queue q;
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Enqueue(5);
    q.print();  // 1 2 3 4 5
    cout << endl;
    q.Dequeue();
    q.print();  // 2 3 4 5
    cout << endl;
    q.Enqueue(6);
    q.print();  // 2 3 4 5 6
    cout << endl;
    q.Dequeue();
    q.Dequeue();
    q.print();
    cout << endl;
    cout << q.peek() << endl;
    cout << endl;
    if (!q.isEmpty()) {
        q.Dequeue();
        cout << q.peek() << endl;
        cout << endl;
        q.Dequeue();
        cout << q.peek() << endl;
        cout << endl;
        q.Dequeue();
    }
    if (q.isEmpty()) cout << "queue is empty" << endl;
    return 0;
}