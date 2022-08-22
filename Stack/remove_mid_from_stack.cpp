#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> s, int size, int count)
{
    if (size == count)
    {
        s.pop();
        return;
    }
    int num = s.top();
    s.pop();
    solve(s, size, count + 1);
    s.push(num);
}

void remove(stack<int> s, int size)
{
    int count = 0;

    solve(s, size, count);
}