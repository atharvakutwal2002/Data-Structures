#include <bits/stdc++.h>
using namespace std;


//1st approach using stack
queue<int> rev(queue<int> q)
{
    stack<int> s;
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    return q;
}


//2nd approach using recursion
void rev2(queue<int> q){
    if (q.empty())
    {
        return q;
    }
    
    int ele= q.front();
    
    rev2(q);

    q.push(ele);

    
}