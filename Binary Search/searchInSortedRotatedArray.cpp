#include <iostream>
using namespace std;

// find the element in sorted rotated array
// input [3, 8, 10, 17, 1]  k = 17
// output 3 (ie index of 17)

// Approch 1:
// step 1: seperate the array in two array [3, 8] [10, 17, 1] using pivot element
// step 2: since both arrays are sorted do Binary Search on each of them and find the element

// Approch 2:
// step 1: is similar as Approch 1
// step 2: find in which array 'k' element lies
// step 3: do Binary search only on the array where 'k' element lies

// Using Approch 2

int findPivot(int *arr, int size)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2; // this formula handles the case where mid goes beyond INT_MAX limit

    while (start < end)
    {
        if (arr[mid] >= arr[0])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
        mid = start + (end - start) / 2;
    }
    return start;
}

int binarySearch(int *arr, int start, int end, int key)
{
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}

int findPosition(int *arr, int size, int key)
{
    int pivot = findPivot(arr, size);

    if ((arr[pivot] <= key) && (key <= arr[size - 1]))
    {
        // key lies in second array
        return binarySearch(arr, pivot, size - 1, key);
    }
    else
    {
        // key lies in first array
        return binarySearch(arr, 0, pivot - 1, key);
    }
}

int main()
{
    int arr[] = {7, 9, 1, 2, 3};
    int key = -10;

    cout << findPosition(&arr[0], 5, key);

    return 1;
}
