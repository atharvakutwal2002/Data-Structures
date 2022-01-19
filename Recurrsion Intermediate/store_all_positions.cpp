#include<iostream>
#include<vector>
using namespace std;
void store(int a[],int n ,int x, int i,vector<int> &v){
    if (n==i)
    {
        return;
    }
    if (a[i]==x)
    {
        v.push_back(i);
    }
    store(a,n,x,i+1,v);
}
int main(){
    vector<int> v;
    int a[]={1,2,3,1,2,3};
    store(a,6,2,0,v);
    for (int i = 0; i <v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    
    return 0;
}