#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n){
    for(int i=0 ; i<=n-2; i++){
        int smallest = i;
        for(int j=i+1; j<=n-1; j++){
            if (arr[j]<arr[smallest])
            {
                smallest = j;
            }
            
        }
        swap(arr[i],arr[smallest]);
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    selectionSort(a,n);
    for (int i = 0; i < n; i++)
    {
        cout<<a[i];
    }
    

    return 0;
}