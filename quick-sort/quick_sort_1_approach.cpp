#include<iostream>
using namespace std;

int partition(int a[],int s ,int e){
    int pivot=a[e];
    int count=0;
    for (int i = 0; i < e-1; i++)
    {
        if (a[i]<a[pivot])
        {
            count++;
            continue;
        }
        
    }
    swap(a[pivot],a[s+count]);
    int p=s+count;
    return p;
}

void quick_sort(int a[],int s, int e){
    if (s>=e)
    {
        return;
    }
    int p=partition(a,s,e);
    quick_sort(a,s,p-1);
    quick_sort(a,p+1,e);
}

int main(){
    int a[]={2,99,77,4,111,-4};
    quick_sort(a,0,5);

    for (int i = 0; i < 6; i++)
    {
        cout<<a[i]<<" ";
    }
    

    return 0;
}