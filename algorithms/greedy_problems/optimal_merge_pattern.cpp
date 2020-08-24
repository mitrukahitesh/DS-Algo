#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	priority_queue<int, vector<int>, greater<int>> q;
	int arr[] = {2, 3, 4, 5, 6, 7};
	int n = sizeof(arr) / sizeof(arr[0]);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		q.push(arr[i]);
	}
	while (q.size() > 1) {
		int a = q.top();
		q.pop();
		int b = q.top();
		q.pop();
		q.push(a + b);
		ans += (a + b);
	}
	cout << ans << endl;
	return 0;
}