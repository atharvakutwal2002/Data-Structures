#include <bits/stdc++.h>
using namespace std;

vector<int> stock(vector<int> arr)
{
    stack<pair<int, int>> s;
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        if(s.empty()){
            ans.push_back(-1);
        }
        else if (s.size()> 0 && s.top())
        {
            /* code */
        }
        
    }
    
}