#include <iostream>
#include <algorithm>

using namespace std;

void countingSort(int arr[], int n) {
    int maxVal = *max_element(arr, arr + n); // find the maximum value in the array
    int count[maxVal + 1] = {0}; // create a count array to store the count of each element

    for (int i = 0; i < n; i++) {
        count[arr[i]]++; // increment the count of the corresponding element in the count array
    }

    for (int i = 1; i <= maxVal; i++) {
        count[i] += count[i - 1]; // update the count array to store the actual position of each element
    }

    int sortedArr[n];
    for (int i = n - 1; i >= 0; i--) {
        sortedArr[count[arr[i]] - 1] = arr[i]; // place each element in the sorted order
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = sortedArr[i]; // copy the sorted array back to the original array
    }
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    countingSort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
