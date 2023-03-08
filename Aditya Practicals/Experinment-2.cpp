// Implementation of Non-Comparison Sort (Counting Sort).

#include <iostream>
#include <algorithm>
using namespace std;

void countingSort(int arr[], int n, int maxVal)
{
    int count[maxVal + 1] = {0}; // initialize count array with all zeros
    int output[n];

    // count the frequency of each element
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // modify count array to store actual position of each element
    for (int i = 1; i <= maxVal; i++)
        count[i] += count[i - 1];

    // build the output array
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // copy the output array to the original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

int main()
{
    int n, maxVal;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    maxVal = *max_element(arr, arr + n); // find the maximum value in the array
    countingSort(arr, n, maxVal);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}