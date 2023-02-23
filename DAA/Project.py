import random
import time
import matplotlib.pyplot as plt

# Generate a list of 1000 random numbers
numbers = [random.randint(1, 1000) for i in range(1000)]
print('Random Numbers:', numbers)

# Define the sorting algorithms
def insertion_sort(arr):
    for i in range(1, len(arr)):
        j = i
        while j > 0 and arr[j-1] > arr[j]:
            arr[j-1], arr[j] = arr[j], arr[j-1]
            j -= 1
    return arr

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr

def selection_sort(arr):
    for i in range(len(arr)):
        min_idx = i
        for j in range(i+1, len(arr)):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
    return arr

# Time the sorting algorithms
insertion_start = time.time()
insertion_sorted = insertion_sort(numbers.copy())
insertion_end = time.time()

bubble_start = time.time()
bubble_sorted = bubble_sort(numbers.copy())
bubble_end = time.time()

selection_start = time.time()
selection_sorted = selection_sort(numbers.copy())
selection_end = time.time()

# Print the sorted lists
print('Insertion Sort:', insertion_sorted)
print('Bubble Sort:', bubble_sorted)
print('Selection Sort:', selection_sorted)

# Plot the results
x = ['Insertion Sort', 'Bubble Sort', 'Selection Sort']
y = [insertion_end - insertion_start, bubble_end - bubble_start, selection_end - selection_start]
plt.bar(x, y)
plt.ylabel('Time (s)')
plt.title('Sorting Algorithms Running Time for Random Numbers: {}'.format(numbers))
plt.show()
