#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void print(int *arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int partition(int *arr, int start, int end) {
	int pIndex = start;
	int pivot = arr[end];
	for (int i = start; i < end; i++) {
		if (arr[i] <= pivot) {
			int temp = arr[pIndex];
			arr[pIndex] = arr[i];
			arr[i] = temp;
			++pIndex;
		}
	}
	int temp = arr[pIndex];
	arr[pIndex] = arr[end];
	arr[end] = temp;
	return pIndex;
}

int random_partition(int *arr, int start, int end) {
	//random number generator
	srand(time(NULL));
	int pivot_index = start + rand() % (end - start);
	int temp = arr[pivot_index];
	arr[pivot_index] = arr[end];
	arr[end] = temp;
	return partition(arr, start, end);
}

void quick_sort(int *arr, int start, int end) {
	if (start >= end)
		return;
	int pIndex = random_partition(arr, start, end);
	quick_sort(arr, start, pIndex - 1);
	quick_sort(arr, pIndex + 1, end);
}

int main() {
	int arr[10] = {10, 9, 8, 5, 4, 3, 2, 1, 7, 6};
	print(arr, 10);
	quick_sort(arr, 0, 9);
	print(arr, 10);
	return 0;
}
