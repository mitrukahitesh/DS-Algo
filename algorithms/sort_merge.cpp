#include <iostream>
using namespace std;

void merge(int* arr, int* lr, int n1, int* rr, int n2) {
    int l = 0;
    int r = 0;
    int a = 0;
    while (l < n1 && r < n2) {
        if (lr[l] < rr[r]) {
            arr[a] = lr[l];
            ++l;
        } else {
            arr[a] = rr[r];
            ++r;
        }
        ++a;
    }
    while (l < n1) {
        arr[a] = lr[l];
        ++l;
        ++a;
    }
    while (r < n2) {
        arr[a] = rr[r];
        ++r;
        ++a;
    }
}

void merge_sort(int* arr, int n) {
    if (n < 2) return;
    int mid = n / 2;
    int lr[mid];
    int rr[n - mid];
    for (int i = 0; i < mid; i++) {
        lr[i] = arr[i];
    }
    for (int i = 0; i < n - mid; i++) {
        rr[i] = arr[mid + i];
    }
    merge_sort(lr, mid);
    merge_sort(rr, n - mid);
    merge(arr, lr, mid, rr, n - mid);
}

int main() {
    int n = 9;
    int arr[n] = {9, 8, 7, 6, 4, 5, 3, 2, 1};
    merge_sort(arr, n);
    cout << "Sorted in ascending order:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}