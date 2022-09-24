#include <iostream>
#include <vector>
using namespace std;

// Book allocation Problem

bool isPossible(vector<int> arr, int books, int students, int mid)
{
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < books; i++)
    {
        if (pageSum + arr[i] <= mid)
        {
            pageSum += arr[i];
        }
        else
        {
            studentCount++;
            if (studentCount > students || arr[i] > mid)
            {
                return false;
            }
            pageSum = 0;
            pageSum += arr[i];
        }
    }
    return true;
}

int allocateBooks(vector<int> arr, int books, int students)
{
    int start = 0;
    int sum_of_pages = 0;
    for (int i = 0; i < books; i++)
        sum_of_pages += arr[i];

    int end = sum_of_pages;
    int ans = -1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (isPossible(arr, books, students, mid))
        {
            cout << mid << " is a possible solution" << endl;
            ans = mid;
            end = mid - 1;
        }
        else
        {
            cout << mid << " is not a possible solution" << endl;
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }

    return ans;
}

int main()
{
    vector<int> arr = {10, 20, 30, 40};
    int books = arr.size();
    int students = 2;

    cout << allocateBooks(arr, books, students);
}