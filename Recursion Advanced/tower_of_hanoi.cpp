#include<iostream>
using namespace std;

int hanoi( int n){
    if (n==0)
    {
        return 0;
    }
     return hanoi(n-1)+1+hanoi(n-1);
    
}

int main(){
    int n;
    cin>>n;
    cout << hanoi(n);
    return 0;
}