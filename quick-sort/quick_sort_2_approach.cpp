#include <iostream>
using namespace std;
int partition(int a[], int s, int e)
{
    int pivot =a[e];
    int i = s;
    // int j = s;
    for(int j=s;j<=e-1;j++)
    {
        if (a[j] < pivot)
        {
            swap(a[i], a[j]);
            i++;
        }
        // j++;
    }
    swap(a[i],a[e]);
    return i;
}
void quicksort(int a[], int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int p=partition(a,s,e);
    quicksort(a,s,p-1);
    quicksort(a,p+1,e);
}

int main(){
    int a[]={1,8,4,-2,66,99};
    quicksort(a,0,5);
    for (int i = 0; i < 6; i++)
    {
        cout<<a[i]<<" ";
    }
    
    return 0;
}