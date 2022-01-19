#include<iostream>
using namespace std;
int lastindex(int a[],int n,int x, int i){
    if (i==-1)
    {
        return -1;
    }
    if (a[i]==x)
    {
        return i;
    }
    
    return lastindex(a,n,x,i-1);
}
int main(){
    int a[]={1,2,3,4,2,4,3,2};
    cout<<lastindex(a,8,2,7);
    return 0;
}