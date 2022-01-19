#include<iostream>
using namespace std;

void printall(int a[],int n, int x,int i){
    //base case
    if (n==0)
    {
        return;
    }
    if (a[i]==x)
    {
        cout<<i<<endl; //condition
    }
    if (n==i)
    {
        return;
    }
    
    printall(a,n,x,i+1); //recursive case
}
int main(){
    int a[]={1,2,3,1,2,3};
    printall(a,6,1,0);
    return 0;
}