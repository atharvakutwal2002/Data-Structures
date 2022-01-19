#include<iostream>
#include<stack>
using namespace std;

//  inbuilt stack also uses templates for its implementation 

int main(){

    stack <int> s;
    s.push(10);
    s.push(11);
    s.push(12);
    s.push(13);
    s.push(14);
    s.push(15);
    s.push(16);

    s.pop();
    cout<<s.empty();




    return 0;
}