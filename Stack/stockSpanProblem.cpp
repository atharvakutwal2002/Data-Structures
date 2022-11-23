#include <bits/stdc++.h>
using namespace std;

vector<int> stock(vector<int> arr)
{
    stack<pair<int, int>> s;
    vector<int> index;
    for (int i = 0; i < arr.size(); i++)
    {
        if (s.empty())
        {
            index.push_back(-1);
        }
        else if (s.size() > 0 && s.top().first > index[i])
        {
            index.push_back(s.top().second);
        }
        else if (s.size() > 0 && s.top().first <= arr[i])
        {
            while (s.size() > 0 && s.top().first <= arr[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                index.push_back(-1);
            }
            else
            {
                index.push_back(s.top().second);
            }
        }
        s.push({arr[i], i});
    }
    for (int i = 0; i < index.size(); i++)
    {
        index[i]= i-index[i];
    }
    return index;
}