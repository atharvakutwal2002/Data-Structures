#include <iostream>
using namespace std;
int length(char a[]){
    if (a[0]=='\0')
    {
        return 0;
    }
    int smalllength=length(a+1);
    
    return 1+smalllength;
}
int main(){
    char a[100];
    cin>>a;
    int l=length(a);
    cout<<l;
    
    return 0;
}