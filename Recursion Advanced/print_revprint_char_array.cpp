#include<iostream>
using namespace std;

void print(char a[],int n,int i){
    if (n==i)
    {
        return;
    }
    else{
        cout<<a[i]<<" ";
    }
    print(a,n,i+1);
    
}

void rev_print(char a[],int n,int i){
    if (i<0)
    {
        return;
    }
    else{
        cout<<a[i]<<" ";
    }
    rev_print(a,n,i-1);
    
}

int main(){
    char a[]={'a','b','c','d'};
    //print(a,4,0);
    rev_print(a,4,3);
    return 0;
}