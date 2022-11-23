#include <bits/stdc++.h>
using namespace std;

int isPresent(int arr[], int size, int key)
{
    int s = 0;
    int l = size - 1;
    int mid = s+ (l-s)/2;

    while (s <= l)
    {
      

        if (arr[mid] == key)
        {
            return mid;
        }
        if (key > arr[mid])
        {
            s = mid + 1;
        }
        else
        {
            l = l - 1;
        }
        mid = s+ (l-s)/2;
    }
    return -1;
}