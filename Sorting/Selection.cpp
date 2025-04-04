#include <bits/stdc++.h>
using namespace std;

/**
 * Selection Sort Algorithm
 * ------------------------
 * Selection Sort is a simple comparison-based sorting algorithm.
 * It divides the array into two sections:
 *   1. **Sorted portion** (initially empty, grows from left to right)
 *   2. **Unsorted portion** (shrinks as elements are sorted)
 *
 * In each iteration:
 * - The smallest element from the **unsorted portion** is selected.
 * - It is swapped with the **first element** of the unsorted portion.
 * - This process continues until the array is fully sorted.
 *
 * Characteristics:
 * - **Time Complexity**:
 *   - Best case: O(n²)  (Even if the array is already sorted)
 *   - Worst case: O(n²) (If the array is sorted in reverse order)
 *   - Average case: O(n²)
 *
 * - **Space Complexity**: O(1) (In-place sorting, no extra memory used)
 * - **Stable Sorting Algorithm?** ❌ No (Swapping may change the order of duplicate elements)
 * - **Adaptive?** ❌ No (Does not optimize for already sorted data)
 */

void selectionSort(vector<int> &arr)
{
    int n = arr.size(); // Get the size of the array

    // Outer loop: Controls the sorted and unsorted portions
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i; // Assume the first element of unsorted portion is the smallest

        // Inner loop: Find the index of the smallest element in the remaining array
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx]) // If a smaller element is found, update minIdx
            {
                minIdx = j;
            }
        }

        // Swap the found minimum element with the first unsorted element
        swap(arr[i], arr[minIdx]);
    }
}

int main()
{
    vector<int> arr = {5, 13, 46, 24, 52, 20, 9}; // Sample input array

    selectionSort(arr); // Sort the array using Selection Sort

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
