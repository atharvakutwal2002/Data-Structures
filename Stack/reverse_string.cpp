#include <bits/stdc++.h>
using namespace std;

string rev(string s)
{
    stack<char> st;
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        st.push(s[i]);
    }
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main(){
    string a= "pool";
    cout<<rev(a);
    return 0;
}