#include <bits/stdc++.h>
using namespace std;

void mergeArray(int *arr, int st, int en)
{
    int s = st;
    int e = en;
    int mid = (s + e) / 2;
    int n1 = mid - s + 1;
    int n2 = e - mid;
    int *arr1 = new int[n1];
    int *arr2 = new int[n2];
    int mainArrayIndex = s;
    for (int i = 0; i < n1; i++)
    {
        arr1[i] = arr[mainArrayIndex++];
        
    }
    for (int i = 0; i < n2; i++)
    {
        arr2[i] = arr[mainArrayIndex++];
       
    }
    int i = 0, j = 0;
    mainArrayIndex = s;

    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            arr[mainArrayIndex++] = arr1[i++];
            
        }
        else
        {
            arr[mainArrayIndex++] = arr2[j++];
            
        }
    }

    while (i < n1)
    {
        arr[mainArrayIndex++] = arr1[i++];
        
    }
    while (j < n2)
    {
        arr[mainArrayIndex++] = arr2[j++];
        
    }
}
void sort(int arr[], int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int mid = (s + e) / 2;

    sort(arr, s, mid);
    sort(arr, mid + 1, e);

    mergeArray(arr, s, e);
}

int main()
{
    int arr[6]={3,1,6,7,2,8};
    int n= 6;
    cout<<"before sorting "<<endl;
    for (int i = 0; i < 6; i++)
    {
       cout<<arr[i]<<" ";
    }
    
    cout<<"\n after sorting "<<endl;
    sort(arr,0, n-1);
    for (int i = 0; i < 6; i++)
    {
       cout<<arr[i]<<" ";
    }
    
    return 0;
}