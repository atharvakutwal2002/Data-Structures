#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int size;
    int *arr;
    int top;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void add(int data)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = data;
        }
        else
        {
            cout << "stack overflow " << endl;
        }
    }

    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << " stack underflow " << endl;
        }
    }
    int peek()
    {
        if (top > 0)
        {
            return arr[top];
        }
        cout << "empty stack " << endl;
        return -1;
    }

    bool isempty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }
    void print_stack()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

vector<int> nextGreater(vector<int> arr)
{
    stack<int> s;
    vector<int> ans;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (s.empty())
        {
            ans.push_back(-1);
        }
        else if (s.size() > 0 && s.top() > arr[i])
        {
            ans.push_back(s.top());
        }
        else if (s.size() > 0 && s.top() <= arr[i])
        {
            while (s.size() > 0 && s.top() <= arr[i])
            {
                s.pop();
            }
            if (s.size() == 0)
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

int main()
{
    // Stack s(5);
    // s.add(1);
    // s.add(2);
    // s.add(3);
    // s.add(4);
    // s.add(5);
    // s.print_stack();
    // s.add(6);
    // s.pop();
    // s.add(6);
    // s.print_stack();
    // s.pop();
    // s.pop();
    // s.pop();
    // s.pop();
    // s.pop();
    // s.pop();
    // s.pop();

    vector<int> test;
    test.push_back(1);
    test.push_back(3);
    test.push_back(2);
    test.push_back(4);

    vector<int> ans = nextGreater(test);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}