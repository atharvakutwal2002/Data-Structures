#include<bits/stdc++.h>
using namespace std;

int e(int x,int n){
    static double s;
    if (n==0)
    {
        return s;
    }
    s=1+ x*s/n;
    return e(x, n-1);
    
}

int main(){
    cout<<e(2,10)<<endl;

    return 0;
}