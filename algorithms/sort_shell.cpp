#include <iostream>

using namespace std;

void print(int*, int);
void shell_sort(int*, int);

int main() {
    int arr[9] = {170, 75, 802, 90, 66, 2, 24, 45, 7};
    int n = 9;
    print(arr, n);
    shell_sort(arr, n);
    print(arr, n);
    return 0;
}

void print(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void shell_sort(int* arr, int n) {
    for (int i = n / 2; i > 0; i = i / 2) {
        for (int j = i; j < n; j++) {
            int temp = arr[j];
            int k = 0;
            for (k = j; k - i >= 0; k = k - i) {
                if (arr[k - i] > arr[k])
                    arr[k] = arr[k - i];
                else {
                    break;
                }
            }
            arr[k] = temp;
        }
    }
}
