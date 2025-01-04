#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Method to merge two sorted halves of the array
    void merge(vector<int> &arr, int low, int mid, int high)
    {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        // Merge the two halves
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

        // Copy remaining elements of left half, if any
        while (left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }

        // Copy remaining elements of right half, if any
        while (right <= high)
        {
            temp.push_back(arr[right]);
            right++;
        }

        // Copy the sorted subarray back into the original array
        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }
    }

    // Method to perform merge sort
    void mergeSort(vector<int> &arr, int low, int high)
    {
        if (low >= high)
            return;

        int mid = (low + high) / 2;

        // Recursively sort the first and second halves
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        // Merge the sorted halves
        merge(arr, low, mid, high);
    }
};

int main()
{
    vector<int> arr = {9, 4, 7, 6, 3, 1, 5};
    int n = arr.size();

    cout << "Before Sorting Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Create an instance of the Solution class
    Solution solution;
    // Function call to sort the array
    solution.mergeSort(arr, 0, n - 1);

    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
