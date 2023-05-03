#include <bits/stdc++.h>
using namespace std;

void mergeArrays(vector<int>& v, int low, int mid, int high)
{
    vector<int > temp ;
    int first = low ;
    int second= mid+1 ;
    while (first <= mid  && second <= high )
    {
        if(v[first] <= v[second]){
            temp.push_back(v[first]);
            first++;
        }else{
            temp.push_back(v[second]);
            second++;
        }
    }

    while (first <= mid  )
    {
        temp.push_back(v[first]);
        first++ ;
    }
    while (second <= high)
    {
        temp.push_back(v[second]);
        second++;
    }
     for (int i = low; i <= high; i++) {
        v[i] = temp[i - low];
    }
    
    
}

void mergeSort(vector<int> &v, int i, int j)
{
    if (i >= j)
    {
        return;
    }
    int mid = (i + j) / 2;
    mergeSort(v, i, mid);
    mergeSort(v, mid + 1, j);
    mergeArrays(v, i, mid, j);
}

int main()
{

    vector<int> v = {4, 5, 1, 2, 3};
    mergeSort(v, 0, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}