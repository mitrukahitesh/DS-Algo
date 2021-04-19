#include <iostream>
using namespace std;

int main() {
    int n = 10;
    int arr[n] = {10, 9, 8, 7, 6, 4, 5, 3, 2, 1};
    for (int i = 1; i < n; i++) {
        int min = arr[i];
        int j;
        for (j = i - 1; j >= 0 && min < arr[j]; j--) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = min;
    }
    cout << "Sorted in ascending order:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}