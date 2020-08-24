#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Node {
public:
	char value;
	int freq;
	Node* left;
	Node* right;
	Node(char, int);
};

Node::Node(char v, int f) {
	value = v;
	freq = f;
	left = right = NULL;
}

class comparator {
public:
	bool operator()(Node* l, Node* r) {    //return true if we want l to be placed before r
		return l->freq > r->freq;		   //the element popped is the last according to this strict weak ordering
	}									   //in priority_queue
};										   //That is, the front of the queue contains the "last" element
/**/									   //according to the weak ordering imposed by Compare.

void printcodes(Node* head, string s) {
	if (head == NULL)
		return;

	if (head->value != '\0')
		cout << head->value << " : " << s << endl;

	printcodes(head->left, s + "0");
	printcodes(head->right, s + "1");
}

int main() {
	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	int freq[] = { 5, 9, 12, 13, 16, 45 };
	int n = sizeof(arr) / sizeof(arr[0]);
	priority_queue<Node*, vector<Node*>, comparator> q;
	for (int i = 0; i < n; ++i) {
		q.push(new Node(arr[i], freq[i]));
	}
	while (q.size() > 1) {
		Node* temp1 = q.top();
		q.pop();
		Node* temp2 = q.top();
		q.pop();
		Node* sum = new Node('\0', temp1->freq + temp2->freq);
		sum->left = temp1;
		sum->right = temp2;
		q.push(sum);
	}
	Node* head = q.top();
	printcodes(head, "");
	return 0;
}