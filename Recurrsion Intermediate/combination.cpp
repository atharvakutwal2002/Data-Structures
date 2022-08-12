#include<bits/stdc++.h>
using namespace std;

int NCR(int n, int r){
    if(n==r || n==0){
        return 1;
    }
    return NCR(n-1, r-1)+NCR(n-1, r);
}

int main(){

    return 0;
}