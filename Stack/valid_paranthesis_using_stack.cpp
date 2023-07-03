#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

// bool isvalid(string str, stack<char> st)
// {
//     for (int i = 0; i < str.size(); i++)
//     {
//         if (str[i] == '{' || str[i] == '(' || str[i] == '[')
//         // {
        //     st.push(str[i]);
        //     return true;
        // }
        // else if (st.empty())
        // {
        //     return false;
        // }

        // else if (str[i] == '}' && st.top() == '{')
//         {
//             st.pop();
//             return true;
//         }
//         else if (str[i] == ']' && st.top() == '[')
//         {
//             st.pop();
//             return true;
//         }
//         else if (str[i] == ')' && st.top() == '(')
//         {
//             st.pop();
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }
// }

/// https://leetcode.com/problems/valid-parentheses/

bool isValid(string A)
{
    stack<char> s;

    for (int i = 0; i < A.size(); i++)
    {

        if (A[i] == '(' || A[i] == '{' || A[i] == '[')
        {
            s.push(A[i]);
        }
        else
        {

            if (s.empty())
                return false; /// imp otherwise run time error
            else if (A[i] == ')')
            {
                if (s.top() == '(')
                    s.pop();
                else
                    return false;
            }
            else if (A[i] == '}')
            {
                if (s.top() == '{')
                    s.pop();
                else
                    return false;
            }
            else if (A[i] == ']')
            {
                if (!s.empty() && s.top() == '[')
                    s.pop();
                else
                    return false;
            }
        }
    }

    if (s.empty())
        return true;

    return false;
}

int main()
{
    stack<char> st;
    string str;
    cin >> str;
    // for (int i = 0; i <str.size(); i++)
    // {
    //     if (str[i]=='{' || str[i]=='(' || str[i]=='[')
    //     {
    //         st.push(str[i]);
    //     }else if (str[i]=='}' && st.top()=='{')
    //     {
    //         st.pop();
    //     }
    //     else if (str[i]==']' && st.top()=='[')
    //     {
    //         st.pop();
    //     }
    //     else if (str[i]==')' && st.top()=='(')
    //     {
    //         st.pop();
    //     }else{cout<<"false"<<endl;}

    // }
    cout << isValid(str);
    return 0;
}