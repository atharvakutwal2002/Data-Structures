#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerRight(vector<int> arr)
{

    stack<int> s;
    vector<int> ans;
    for (int i = arr.size(); i >= 0; i--)
    {
        if (s.empty())
        {
            ans.push_back(-1);
        }
        else if (s.size() > 0 && s.top() < arr[i])
        {
            ans.push_back(s.top());
        }
        else if (s.size() > 0 && s.top() >= arr[i])
        {
            while (s.size() > 0 && s.top() >= arr[i])
            {
                s.pop();
            }
            if (s.empty())
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}