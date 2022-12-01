#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int st, int en)
{
    int s = st;
    int e = en;
    int pivot = st;
    int cnt = 0;
    for (int i = pivot + 1; i <= en; i++)
    {
        if (arr[pivot] >= arr[i])
        {
            cnt++;
        }
    }
    int newPivotIndex = s + cnt;
    swap(arr[s], arr[newPivotIndex]);
    int first = st;
    int last = en;
    while (first < newPivotIndex && last > newPivotIndex)
    {
        if (arr[first] > arr[newPivotIndex] && arr[last] < arr[newPivotIndex])
        {
            swap(arr[first], arr[last]);
            first++;
            last--;
        }
        else if (arr[first] < arr[newPivotIndex])
        {
            first++;
        }
        else if (arr[last] > arr[newPivotIndex])
        {
            last--;
        }
    }

    return newPivotIndex;
}

void quickSort(int arr[], int st, int en)
{

    int pivot = 0;
    int s = st;
    int e = en;
    if (s >= e)
    {
        return;
    }
    int p = partition(arr, s, e);
    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

int main()
{
    int arr[5] = {6, 1, 4, 8, 2};
    quickSort(arr, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}