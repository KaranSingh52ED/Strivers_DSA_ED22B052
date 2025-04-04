#include <bits/stdc++.h>
using namespace std;

/**
 * Function to perform Insertion Sort on a vector.
 * Insertion Sort is a simple sorting algorithm that works similarly to sorting playing cards.
 * It builds a sorted sequence one element at a time by inserting each element in its correct position.
 *
 * Algorithm:
 * - Start with the second element (index 1), assuming the first element is already sorted.
 * - Compare it with the elements in the sorted portion and shift them right if needed.
 * - Insert the current element in the correct position.
 * - Repeat until the entire array is sorted.
 *
 * Time Complexity:
 * - Best case (already sorted): O(n) → Only one comparison per element.
 * - Worst case (reverse sorted): O(n²) → Each element must be compared and moved for every preceding element.
 * - Average case: O(n²)
 *
 * Space Complexity: O(1) (in-place sorting)
 *
 * Stable Sorting Algorithm: Yes (it maintains the relative order of equal elements)
 */
void InsertionSort(vector<int> &arr)
{
    int n = arr.size(); // Get the number of elements in the array

    // Outer loop starts from index 1, as the first element is already sorted
    for (int i = 1; i < n; i++)
    {
        int j = i; // Set j to the current index

        // Move elements in the sorted portion that are greater than arr[j] one position to the right
        while (j > 0 && arr[j - 1] > arr[j])
        {

            swap(arr[j - 1], arr[j]); // Swap current element with the previous one
            j--;                      // Move leftwards to continue shifting if needed
        }
    }
}

int main()
{
    vector<int> arr = {5, 13, 46, 24, 52, 20, 9};
    InsertionSort(arr);

    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
