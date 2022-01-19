#include <iostream>
using namespace std;
void replace(char a[] )
{
    if (a[0] == '\0')
    {
        return;
    }
    if (a[0] == 'a')
    {
        a[0] = 'y';
    }
    replace(a+1);
    
}
int main(){
    char a[100];
    cin>>a;
    cout<<a<<endl;
    replace(a);
    cout<<a;
    
    return 0;
}