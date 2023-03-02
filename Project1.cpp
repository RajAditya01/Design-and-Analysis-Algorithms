#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

//insertion sort

void insertionSort(int arr[], int n) {
    auto start = chrono::high_resolution_clock::now();
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Insertion sort took " << duration << " microseconds" << endl;
}

//selection sort

void selectionSort(int arr[], int n) {
    auto start = chrono::high_resolution_clock::now();
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(arr[min_idx], arr[i]);
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Selection sort took " << duration << " microseconds" << endl;
}

//bubble sort
void bubbleSort(int arr[], int n) {
    auto start = chrono::high_resolution_clock::now();
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Bubble sort took " << duration << " microseconds" << endl;
}


//counting sort


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

    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    selectionSort(arr, n);
    bubbleSort(arr, n);
    countingSort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
