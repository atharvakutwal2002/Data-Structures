#include<iostream>
using namespace std;

void occurence(int a[], int n,int x,int i,int &ans){
    int counter=0;
    if (n==i)
    {
        return ;
    }
    if (a[i]==x)
    {
        ans++;
    }
    occurence(a,n,x,i+1,ans);
     
}
int main(){
    int ans=0;
    int a[]={1,2,1,2,1};
    occurence(a,5,2,0,ans);
    cout<<ans;
    return 0;
}