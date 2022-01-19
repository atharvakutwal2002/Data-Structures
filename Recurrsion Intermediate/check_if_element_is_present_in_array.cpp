#include<iostream>
using namespace std;

bool check_element(int a[],int n,int m){
    //base condition
    if (n==0)
    {
        return false;
    }
    if (a[0]==m)
    {
        return true;
    }
    
    //recurssive case
     return check_element(a+1,n-1,m);

    //  if (a[0]==m)
    //  {
    //      return true;
    //  }else{
    //      return false;
    //  }
     
    
}

int main(){
    int a[]={1,2,3,4};
    if (check_element(a,4,9))
    {
        cout<<"Present";
    }
    else{
        cout<<"Not present";
    }
    
    return 0;
}