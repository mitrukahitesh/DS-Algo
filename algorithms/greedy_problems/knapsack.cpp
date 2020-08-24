//Fractional Knapsack
#include <iostream>
#include <algorithm>
using namespace std;

class Object {
public:
	int w, p;
	float r;  //p:w
	Object() {}
	Object(int, int);
	bool operator<(Object);
};

Object::Object(int w, int p) {
	this->w = w;
	this->p = p;
	r = (float)p / (float)w;
}

bool Object::operator< (Object o) {
	return o.r < this->r;
}

int main() {
	int p[] = {10, 5, 15, 7, 6, 18, 3};
	int w[] = {2, 3, 5, 7, 1, 4, 1};
	int n = sizeof(p) / sizeof(p[0]);
	int capacity = 15;
	Object obj[n];
	for (int i = 0; i <  n; ++i) {
		Object temp(w[i], p[i]);
		obj[i] = temp;
	}
	sort(obj, obj + n);
	int weight = 0;
	float profit = 0;
	int i = 0;
	while (weight < capacity) {
		if (weight + obj[i].w <= capacity) {
			weight += obj[i].w;
			profit += obj[i].p;
		}
		else {
			int x = capacity - weight;
			weight += x;
			profit += (float(x) / float(obj[i].w)) * float(obj[i].p);
		}
		++i;
	}
	cout << "Weight: " << weight << endl << "Profit: " << profit << endl << "Object variety: " << i << endl;
	return 0;
}