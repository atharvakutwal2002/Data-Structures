#include <bits/stdc++.h>
using namespace std;

int partitionIndex(vector<int> v, int low, int high)
{
    int i = low;
    int j = high;
    int pivot = v[low];
    while (i < j)
    {
        if (v[i] <= pivot && i <= high+1)
        {
            i++;
        }
        if (v[j] >= pivot && j >= low-1)
        {
            j--;
        }
        if(i < j){
            swap(v[i], v[j]);
        }
            swap(pivot, v[j]);
        

    }

    return j ;
}

void quickSort(vector<int> v, int low, int high)
{
    if (low < high)
    {
        int partition = partitionIndex(v, low, high);
        quickSort(v, low, partition - 1);
        quickSort(v, partition + 1, high);
    }
}

int main()
{

    return 0;
}