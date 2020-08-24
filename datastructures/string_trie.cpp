#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
	bool is_end_of_string;
	Node** alphabet;
	Node();
};

Node::Node() {
	is_end_of_string = false;
	alphabet = new Node*[26];
}

class Trie
{
	Node* root;
public:
	Trie();
	void insert(string);
	bool search(string);
	void delete_string(string);
};

Trie::Trie() {
	root = NULL;
}

void Trie::insert(string s) {
	Node* crawl = root;
	if (s.length() == 0)
		return;
	if (root == NULL) {
		crawl = new Node;
		root = crawl;
	}
	for (int i = 0; i < s.length(); ++i) {
		int index = s[i] - 'a';
		if (crawl->alphabet[index] == NULL)
			crawl->alphabet[index] = new Node;
		crawl = crawl->alphabet[index];
	}
	crawl->is_end_of_string = true;
}

bool Trie::search(string s) {
	if (root == NULL)
		return false;
	Node* crawl = root;
	int i;
	for (i = 0; i < s.length() && crawl->alphabet[s[i] - 'a'] != NULL; ++i) {
		crawl = crawl->alphabet[s[i] - 'a'];
	}
	return (i == s.length() && crawl->is_end_of_string);
}

void Trie::delete_string(string s) {
	stack<Node*> st;
	if (search(s)) {
		Node* crawl = root;
		for (int i = 0; i < s.length() && crawl->alphabet[s[i] - 'a'] != NULL; ++i) {
			st.push(crawl);
			crawl = crawl->alphabet[s[i] - 'a'];
		}
		crawl->is_end_of_string = false;
		int i = 1;
		while (!st.empty() && !crawl->is_end_of_string) {
			bool isPrefix = false;
			for (int i = 0; i < 26; ++i) {
				if (crawl->alphabet[i] != NULL) {
					isPrefix = true;
					break;
				}
			}
			if (isPrefix)
				break;
			Node* temp = crawl;
			crawl = st.top();
			st.pop();
			crawl->alphabet[s[s.length() - i] - 'a'] = NULL;
			++i;
			delete temp;
		}
	}
}

int main() {
	Trie trie;
	//insert some strings
	trie.insert("the");
	trie.insert("a");
	trie.insert("there");
	trie.insert("answer");
	trie.insert("any");
	trie.insert("by");
	trie.insert("bye");
	trie.insert("there");
	//delete string
	trie.delete_string("the");
	//search some strings
	trie.search("the") ? cout << "Present\n" : cout << "Not Present\n";
	trie.search("a") ? cout << "Present\n" : cout << "Not Present\n";
	trie.search("there") ? cout << "Present\n" : cout << "Not Present\n";
	trie.search("answer") ? cout << "Present\n" : cout << "Not Present\n";
	trie.search("any") ? cout << "Present\n" : cout << "Not Present\n";
	trie.search("by") ? cout << "Present\n" : cout << "Not Present\n";
	trie.search("bye") ? cout << "Present\n" : cout << "Not Present\n";
	trie.insert("there");
	trie.search("there") ? cout << "Present\n" : cout << "Not Present\n";
	trie.search("these") ? cout << "Present\n" : cout << "Not Present\n";
	trie.search("thaw") ? cout << "Present\n" : cout << "Not Present\n";
	trie.search("ans") ? cout << "Present\n" : cout << "Not Present\n";
	return 0;
}