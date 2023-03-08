#include <iostream>
#include <vector>
#include <cstdlib> // for rand() function

using namespace std;

// Function to partition the array and return the index of the pivot element
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low + rand() % (high - low + 1)]; // choose a random pivot element
    int i = low - 1;
    int j = high + 1;
    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);
        do {
            j--;
        } while (arr[j] > pivot);
        if (i >= j) {
            return j;
        }
        swap(arr[i], arr[j]);
    }
}

// Function to perform quick sort
void quick_sort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);
        quick_sort(arr, low, pivot_index);
        quick_sort(arr, pivot_index + 1, high);
    }
}

int main() {
    //vector<int> arr = {5, 2, 9, 3, 7, 6, 1, 8, 4};
    vector<int>arr[n];
    quick_sort(arr, 0, arr.size() - 1);
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
