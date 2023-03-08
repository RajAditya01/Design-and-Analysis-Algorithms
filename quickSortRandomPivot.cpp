#include <iostream>
#include <vector>
#include <cstdlib> // for rand() function
#include <ctime>   // for time() function


using namespace std;


// Function to perform quicksort
void quick_sort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivotIndex = left + rand() % (right - left + 1); // choose a random pivot element
    int pivot = arr[pivotIndex];
    int i = left, j = right;
    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    quick_sort(arr, left, j);
    quick_sort(arr, i, right);
}

// Function to print array elements
void print_array(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] <<" ";
	cout << endl;
}


int main() {

    vector<int> arr;
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        arr.push_back(element);
    }
    // Set seed for random number generator
    srand(time(NULL));

    // Sort the array
    quick_sort(arr, 0, n - 1);

    // Print the sorted array
    cout << "Sorted array: ";
    print_array(arr);
    
    return 0;
}
