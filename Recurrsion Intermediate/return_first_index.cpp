#include<iostream>
using namespace std;

int findindex(int a[],int n, int x, int i){
    if (n==i)
    {
        return -1;
    }
    if (a[i]==x)
    {
        return i;
    }

    return findindex(a,n,x,i+1);
    
    
}
int main(){
    int a[]={1,3,3,4,3,4};
    cout<<findindex(a,6,9,0);
    return 0;
}
