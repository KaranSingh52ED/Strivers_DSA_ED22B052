#include <bits/stdc++.h>
using namespace std;

/**
 * Function to merge two sorted halves of the array.
 * This function takes a subarray defined by low, mid, and high.
 * It merges two sorted halves into a single sorted sequence.
 *
 * @param arr The array to be sorted.
 * @param low The starting index of the subarray.
 * @param mid The middle index where the array is divided.
 * @param high The ending index of the subarray.
 */
void merge(vector<int> &arr, int low, int high, int mid)
{
    vector<int> temp;    // Temporary array to store sorted elements.
    int left = low;      // Starting index of the left half.
    int right = mid + 1; // Starting index of the right half.

    // Merge elements from both halves in sorted order.
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Copy remaining elements from the left half.
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    // Copy remaining elements from the right half.
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy sorted elements back to the original array.
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

/**
 * Recursive function to perform Merge Sort.
 * Merge Sort follows the "Divide and Conquer" approach:
 * - It divides the array into two halves,
 * - Recursively sorts both halves,
 * - Merges the sorted halves together.
 *
 * Time Complexity:
 * - Best Case: O(n log n)
 * - Worst Case: O(n log n)
 * - Average Case: O(n log n)
 *
 * Space Complexity: O(n) (extra space for merging)
 *
 * Stable Sorting Algorithm: Yes
 *
 * @param arr The array to be sorted.
 * @param low The starting index.
 * @param high The ending index.
 */
void mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high) // Base condition: single element is already sorted.
        return;

    int mid = (low + high) / 2;    // Calculate the middle index.
    mergeSort(arr, low, mid);      // Recursively sort the left half.
    mergeSort(arr, mid + 1, high); // Recursively sort the right half.
    merge(arr, low, high, mid);    // Merge both sorted halves.
}

/**
 * Driver function to test Merge Sort.
 * This function initializes an array, sorts it using Merge Sort,
 * and prints the sorted array.
 */
int main()
{
    vector<int> arr = {55, 13, 46, 24, 52, 20, 9}; // Input array.
    int n = arr.size();                            // Get the number of elements.

    int low = 0, high = n - 1; // Define sorting boundaries.

    mergeSort(arr, low, high); // Call Merge Sort.

    // Print the sorted array.
    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
