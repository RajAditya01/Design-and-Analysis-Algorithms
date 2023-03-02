#include <iostream>
#include <algorithm>

using namespace std;

void countingSort(int arr[], int n) {

   void couuntSort(int arr[], int n){
    int k=arr[0];
    for(int i=0;i<n;i++){
        k=max(k,arr[i]);
    }

    int count[10]={0};
    for(int i=0; i<n; i++){
        count[arr[i]]++;
    }

    for(int i=1; i<=k; i++){
        count[i]+=count[i-1];
    }

    int output[n];
    for(int i=n-1; i>=0; i--){
        output[--count[arr[i]]]=arr[i];
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
