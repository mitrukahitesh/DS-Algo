#include <iostream>
using namespace std;

int main() {
    int n = 10;
    int arr[n] = {10, 9, 8, 7, 6, 4, 5, 3, 2, 1};
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[i]) min = j;
        }
        if (min != i) {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
    cout << "Sorted in ascending order:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}