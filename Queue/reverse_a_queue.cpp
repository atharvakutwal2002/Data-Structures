#include <iostream>
#include <stack>
#include <queue>
using namespace std;

//              storing queue elements in stack temporarily and again restoring it in queue back
//              making it reversed queue

void reverse(queue<int> &q)
{ //need to pass queue by reference
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
}

int main()
{
    queue<int> q;
    for (int i = 0; i < 5; i++)
    {
        q.push(i);
    }
    reverse(q);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}
