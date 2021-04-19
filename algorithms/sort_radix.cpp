#include <iostream>

using namespace std;

void radix_sort(int*, int);
int getmax(int*, int);
void counting_sort(int*, int, int);
void print(int*, int);

int main() {
    int arr[12] = {2, 4, 6, 7, 123, 6, 67, 78, 11, 90, 66, 101};
    print(arr, 12);
    cout << "Process:" << endl;
    radix_sort(arr, 12);
    cout << "Sorted array:" << endl;
    print(arr, 12);
    return 0;
}

void print(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void radix_sort(int* arr, int n) {
    int max = getmax(arr, n);
    for (int i = 1; max / i > 0; i *= 10) {
        counting_sort(arr, n, i);
        print(arr, n);
    }
}

int getmax(int* arr, int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

void counting_sort(int* arr, int n, int div) {
    int output[n];
    int count[10] = {0};
    for (int i = 0; i < n; i++) {
        ++count[(arr[i] / div) % 10];
    }
    for (int i = 1; i < 10; i++) {
        count[i] = count[i] + count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {  // to preserve stability
        output[--count[(arr[i] / div) % 10]] = arr[i];
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}
