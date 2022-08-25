#include<bits/stdc++.h>
using namespace std;

queue <int > modifyQueue(queue<int> q, int k){
    stack <int> s;
    for (int i = 0; i < k; i++)
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        q.pop();
    }
    int t=q.size()-k;
    while (t--)
    {
        int val=q.front();
        q.pop();
        q.push(val);
    }
    
    return q;
}