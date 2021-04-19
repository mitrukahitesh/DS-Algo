#include <iostream>

using namespace std;

void print(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void counting_sort(int *arr, int n) {
    // Considering range 0-9
    int count[10] = {0};  // size of range (no of unique elements)
    int output[n];        // size of input array
    for (int i = 0; i < n; i++) {
        ++count[arr[i]];
    }
    for (int i = 1; i < 10; i++) {
        count[i] =
            count[i] + count[i - 1];  // added number gives position, not index
    }
    for (int i = 0; i < n; i++) {
        output[--count[arr[i]]] = arr[i];
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int arr[12] = {3, 6, 9, 7, 1, 4, 5, 7, 1, 0, 8, 3};
    print(arr, 12);
    counting_sort(arr, 12);
    print(arr, 12);
    return 0;
}
