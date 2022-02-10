#include<bits/stdc++.h>
using namespace std;

void ksortedarray(int *input,int n,int k){
    priority_queue <int> pq;
    for (int i = 0; i <k; i++)
    {
        pq.push(input[i]);
    }
    int s=0;
    for (int i = k; i < n; i++)
    {
        input[s]=pq.top();
        pq.pop();
        s++;
        pq.push(input[i]);
    }
    while (!pq.empty())
    {
        input[s]=pq.top();
        pq.pop();
        s++;
    }
    
    
}

int main(){
    int input[]={10,12,6,7,9};
    int k=3;
    ksortedarray(input,5,k);
    for (int i = 0; i < 5; i++)
    {
        cout<<input[i]<<" ";
    }
    
    return 0;
}