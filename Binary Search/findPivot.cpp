#include <iostream>
using namespace std;

// find the pivot element in rotated array
// pivot element = minimum element
// input [3, 8, 10, 17, 1]
// output 4 (ie index of 1)

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

int main()
{
    int arr[5] = {3, 8, 10, 17, 1};

    cout << findPivot(&arr[0], 5);

    return 1;
}