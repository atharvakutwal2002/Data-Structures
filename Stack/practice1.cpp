#include <bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            if (st.empty())
            {
                st.push(s[i]);
            }
        }
        if (s[i] == ')')
        {
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
            }
        }
        if (s[i] == '}')
        {
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
        }
        if (s[i] == ']')
        {
            if (!st.empty() && st.top() == '[')
            {
                st.pop();
            }
        }
    }

    return st.empty();
}

int main()
{

    string s = "({[]}";
    cout << isValidParenthesis(s);

    return 0;
}