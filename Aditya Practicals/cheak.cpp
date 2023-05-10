#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <gnuplot/gnuplot.h>

using namespace std;
using namespace std::chrono;

// ...
      
void insertion_sort(vector<int>& numbers) {
    for (int i = 1; i < numbers.size(); ++i) {
        int key = numbers[i];
        int j = i - 1;
        while (j >= 0 && key < numbers[j]) {
            numbers[j + 1] = numbers[j];
            j--;
        }
        numbers[j + 1] = key;
    }
}

void bubble_sort(vector<int>& numbers) {
    int n = numbers.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (numbers[j] > numbers[j + 1]) {
                swap(numbers[j], numbers[j + 1]);
            }
        }
    }
}

void counting_sort(vector<int>& numbers) {
    int max_number = *max_element(numbers.begin(), numbers.end());
    vector<int> count(max_number + 1, 0);
    for (int number : numbers) {
        count[number]++;
    }
    vector<int> sorted_numbers;
    for (int i = 0; i < count.size(); ++i) {
        sorted_numbers.insert(sorted_numbers.end(), count[i], i);
    }
    numbers = sorted_numbers;
}

void merge(vector<int>& left_half, vector<int>& right_half, vector<int>& merged_list) {
    int i = 0, j = 0;
    while (i < left_half.size() && j < right_half.size()) {
        if (left_half[i] < right_half[j]) {
            merged_list.push_back(left_half[i]);
            i++;
        }
        else {
            merged_list.push_back(right_half[j]);
            j++;
        }
    }
    while (i < left_half.size()) {
        merged_list.push_back(left_half[i]);
        i++;
    }
    while (j < right_half.size()) {
        merged_list.push_back(right_half[j]);
        j++;
    }
}

void merge_sort(vector<int>& numbers) {
    if (numbers.size() <= 1) {
        return;
    }
    int mid = numbers.size() / 2;
    vector<int> left_half(numbers.begin(), numbers.begin() + mid);
    vector<int> right_half(numbers.begin() + mid, numbers.end());
    merge_sort(left_half);
    merge_sort(right_half);
    numbers.clear();
    merge(left_half, right_half, numbers);
}

int partition(vector<int>& numbers, int low, int high) {
    int pivot = numbers[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; ++j) {
        if (numbers[j] < pivot) {
            i++;
            swap(numbers[i], numbers[j]);
        }
    }
    swap(numbers[i + 1], numbers[high]);
    return i + 1;
}

void quick_sort(vector<int>& numbers, int low, int high) {
    if (low < high) {
        int pivot_index = partition(numbers, low, high);
        quick_sort(numbers, low, pivot_index - 1);
        quick_sort(numbers, pivot_index + 1, high);
    }
}

double measure_sorting_time(void (*sorting_function)(vector<int>&), vector<int>& numbers) {
    high_resolution_clock::time_point start_time = high_resolution_clock::now();
    sorting_function(numbers);
    high_resolution_clock::
    high_resolution_clock::time_point end_time = high_resolution_clock::now();
duration<double> sorting_time = duration_cast<duration<double>>(end_time - start_time);
return sorting_time.count();
}





// ...
void plot_time_vs_n(const vector<int>& n_list, const vector<double>& insertion_sort_time_list,
                    const vector<double>& bubble_sort_time_list, const vector<double>& counting_sort_time_list,
                    const vector<double>& merge_sort_time_list, const vector<double>& quick_sort_time_list) {
    Gnuplot gp;

    // Set the labels and title for the plot
    gp.set_xlabel("Number of elements");
    gp.set_ylabel("Time (s)");
    gp.set_title("Sorting time vs. number of elements");

    // Plot the data
    gp.plot(n_list, insertion_sort_time_list, "bo-", "InserƟon sort");
    gp.plot(n_list, bubble_sort_time_list, "ro-", "Bubble sort");
    gp.plot(n_list, counting_sort_time_list, "go-", "CounƟng sort");
    gp.plot(n_list, merge_sort_time_list, "yo-", "Merge sort");
    gp.plot(n_list, quick_sort_time_list, "co-", "Quick sort");

    // Show the plot
    gp.showonscreen();
}

int main() {
    // ...
    int main() {
vector<int> n_list;
vector<double> insertion_sort_time_list;
vector<double> bubble_sort_time_list;
vector<double> counting_sort_time_list;
vector<double> merge_sort_time_list;
vector<double> quick_sort_time_list;
for (int n = 1000; n <= 10000; n += 1000) {
    vector<int> numbers(n);
    srand(static_cast<unsigned>(time(0)));
    generate(numbers.begin(), numbers.end(), []() { return rand() % 1000000 + 1; });

    n_list.push_back(n);

    double insertion_sort_time = measure_sorting_time(insertion_sort, numbers);
    insertion_sort_time_list.push_back(insertion_sort_time);
    cout << "Insertion sort: Sorting " << n << " numbers took " << insertion_sort_time << " seconds." << endl;

    double bubble_sort_time = measure_sorting_time(bubble_sort, numbers);
    bubble_sort_time_list.push_back(bubble_sort_time);
    cout << "Bubble sort: Sorting " << n << " numbers took " << bubble_sort_time << " seconds." << endl;

    double counting_sort_time = measure_sorting_time(counting_sort, numbers);
    counting_sort_time_list.push_back(counting_sort_time);
    cout << "Counting sort: Sorting " << n << " numbers took " << counting_sort_time << " seconds." << endl;

    double merge_sort_time = measure_sorting_time(merge_sort, numbers);
    merge_sort_time_list.push_back(merge_sort_time);
    cout << "Merge sort: Sorting " << n << " numbers took " << merge_sort_time << " seconds." << endl;

    double quick_sort_time = measure_sorting_time([&](vector<int>& nums) { quick_sort(nums, 0, nums.size() - 1); }, numbers);
    quick_sort_time_list.push_back(quick_sort_time);
    cout << "Quick sort: Sorting " << n << " numbers took " << quick_sort_time << " seconds." << endl;
}

// Plotting the time vs. n
plot_time_vs_n(n_list, insertion_sort_time_list, bubble_sort_time_list,
               counting_sort_time_list, merge_sort_time_list, quick_sort_time_list);

return 0;


    // Plotting the time vs. n
    plot_time_vs_n(n_list, insertion_sort_time_list, bubble_sort_time_list,
                   counting_sort_time_list, merge_sort_time_list, quick_sort_time_list);

    // ...

    return 0;
}
}