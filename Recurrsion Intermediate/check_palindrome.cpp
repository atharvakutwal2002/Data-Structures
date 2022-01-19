#include<iostream>
using namespace std;

bool ispalindrome(int a[],int s,int e){
    if (s>e)
    {
        return true;
    }
    
    if (a[s]==a[e])
    {
        return ispalindrome(a,s+1,e-1);
    }
    else{
        return false;
    }
    
    
}
int main(){
    int a[]={1,2,3,1,2,1};
    if(ispalindrome(a,0,5)){
        cout<<"is palindrome ";
    }
    else{
        cout<<"not a palindrome ";
    }
    return 0;
}