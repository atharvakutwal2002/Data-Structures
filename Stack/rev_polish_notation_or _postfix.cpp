// #include <iostream>           Leetcode
#include<bits/stdc++.h>
// #include <stack>
// #include <string.h>
// #include <vector>
using namespace std;

int main()
{
    stack<int> st;
    vector<string> str;
    string s;
    str.push_back(s);
    
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == "+" || str[i] == "-" || str[i] == "*" || str[i] == "/")
        {
            int v1 = st.top();
            st.pop();
            int v2 = st.top();
            st.pop();
            if (str[i] == "+")
            {
                st.push(v1 + v2);
            }
            if (str[i] == "-")
            {
                st.push(v1 - v2);
            }
            if (str[i] == "*")
            {
                st.push(v1 * v2);
            }
            if (str[i] == "/")
            {
                st.push(v1 / v2);
                ;
            }
        }
        else
        {
            st.push(atoi(str[i].c_str()));
        }
    }
    cout<<st.top();

    return 0;
}