#include<bits/stdc++.h>
using namespace std;

double e(int x , int n){
    double s=1;
    int i;
    double num=1;
    double den =1;
    for ( i = 0; i < n; i++)
    {
        num * =x;
        den *= i;
        s+= num/den;
    }
    return s;
    
}

int main(){

    return 0;
}