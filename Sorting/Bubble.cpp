#include <bits/stdc++.h>
using namespace std;

/**
 * Function to perform Bubble Sort on a vector.
 * Bubble Sort is a simple sorting algorithm that repeatedly steps through the list,
 * compares adjacent elements, and swaps them if they are in the wrong order.
 * The process is repeated until the list is sorted.
 *
 * Time Complexity:
 * - Best case (already sorted): O(n)
 * - Worst case (reverse sorted): O(n^2)
 * - Average case: O(n^2)
 *
 * Space Complexity: O(1) (in-place sorting)
 *
 * Stable Sorting Algorithm: Yes (it maintains the relative order of equal elements)
 */

void bubbleSort(vector<int> &arr)
{
    // Get the number of elements in the array
    int n = arr.size();

    // Outer loop to control the number of passes
    // The last element is already sorted in each pass, so we reduce the range
    for (int i = n - 1; i >= 1; i--)
    {
        // Flag to check if a swap has been made in the current pass
        bool swapped = false;

        // Inner loop to compare and swap adjacent elements
        for (int j = 0; j <= i - 1; j++)
        {
            // If the current element is greater than the next element, swap them
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]); // Swap the two elements
                swapped = true;           // Mark swapped as true since a swap occurred
            }
        }

        // If no swaps were made in this pass, the array is already sorted
        if (!swapped)
            break; // Exit the loop early for efficiency
    }
}

int main()
{
    vector<int> arr = {5, 13, 46, 24, 52, 20, 9};
    bubbleSort(arr);
    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}