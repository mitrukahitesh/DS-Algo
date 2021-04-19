#include <iostream>

using namespace std;

int main() {
    int bit = 0, index;
    int *arr;
    int n;
    cout << "Enter n:\n";
    cin >> n;
    arr = new int[n];
    int first = 0, last = n - 1;
    cout << "Enter sorted array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int key;
    cout << "Enter element to be searched:\n";
    cin >> key;
    while (first <= last) {
        int mid = (first + last) / 2;
        if (arr[mid] == key) {
            bit = 1;
            index = mid;
            break;
        } else if (key > arr[mid]) {
            first = mid + 1;
        } else if (key < arr[mid]) {
            last = mid - 1;
        }
    }
    if (bit == 1)
        cout << "Found at index " << index << endl;
    else
        cout << "Element not found\n";
    return 0;
}