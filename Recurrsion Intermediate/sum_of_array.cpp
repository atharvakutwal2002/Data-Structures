#include<iostream>
using namespace std;

int sum_array(int a[], int n){
    //base case
    if (n==0)
    {
        return 0;
    }
    //recursive case
    int smallans=sum_array(a+1,n-1);

    return smallans+a[0];

    
}
int main(){
    int a[]={9,2,3};
    cout<<sum_array(a,3);
    return 0;
}