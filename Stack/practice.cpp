#include <bits/stdc++.h>
using namespace std;

// stack using array

// class Stack
// {
// public:
//     int *arr;
//     int top;
//     int size;
//     Stack(int size)
//     {
//         this->size = size;
//         arr = new int[size];
//         top = -1;
//     }
//     void display()
//     {
//         for (int i = 0; i < size; i++)
//         {
//             cout << arr[i] << " ";
//         }
//         cout<<endl;
//     }
//     void push(int ele)
//     {
//         if (size - top > 1)
//         {
//             top++;
//             arr[top] = ele;
//         }
//         else
//         {
//             cout << "Stack overflow" << endl;
//         }
//     }
//     void pop()
//     {
//         if (top >= 0)
//         {
//             top--;
//         }
//         else
//         {
//             cout << "stack underflow " << endl;
//             return;
//         }
//     }
//     int peek()
//     {
//         if(top>=0 ){
//             return arr[top];
//         }
//         else{
//             cout<<"stack is empty "<<endl;
//             return -1;
//         }
//     }
//     bool isEmpty()
//     {
//         if (top == -1)
//         {
//             return true;
//         }
//         return false;
//     }
// };

// int main()
// {
//     Stack st(4);
//     cout<<st.isEmpty()<<endl;
//     st.push(3);
//     st.push(4);
//     st.push(5);
//     st.push(6);
//     st.push(7);
//     st.display();
//     st.pop();
//     cout<<st.peek();

//     return 0;
// }

// stack using LL;

class stackNode
{
public:
    int data;
    stackNode *next;

    stackNode(int data)
    {

        this->data = data;
        this->next = nullptr;
    }
};

void push(int data, stackNode *&head)
{

    stackNode *temp = new stackNode(data);
    temp->next = head;
    head = temp;
}
void pop(stackNode *&head)
{
    stackNode *temp = head->next;
    stackNode *del_node = head;
    head = temp;
    del_node->next = nullptr;
    delete del_node;
}
int top(stackNode *head)
{
    return head->data;
}

void display(stackNode *head)
{
    stackNode *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool isValidParenthesis(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (st.empty() || st.top() != '(')
            {
                return false;
            }

            st.pop();
        }
        else if (s[i] == ']')
        {
            if (st.empty() || st.top() != '[')
            {
                return false;
            }
            st.pop();
        }

        else if (s[i] == '}')
        {
            if (st.empty() || st.top() != '{')
            {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

void insertAtBottom(stack<int> &st, int x)
{
    if (st.empty())
    {
        st.push(x);
        return;
    }
    int temp = st.top();
    st.pop();
    insertAtBottom(st, x);
    st.push(temp);
}

void reverseStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int temp = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, temp);
}

void sortedInsert(stack<int> &s, int num)
{
    if (s.empty() || (!s.empty() && s.top() < num))
    {
        s.push(num);
        return;
    }

    int temp = s.top();
    s.pop();
    sortedInsert(s, num);
    s.push(temp);
}
void sortStack(stack<int> &s)
{

    if (s.empty())
    {
        return;
    }
    int temp = s.top();
    s.pop();
    sortStack(s);
    sortedInsert(s, temp);
}

bool redundantBrackets(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            bool isRedundant = true;
            while (st.top()!='(')
            {

                if (st.top() == '*' || st.top() == '/' || st.top() == '+' || st.top() == '-')
                {
                    
                    isRedundant = false;
                }
                st.pop();
            }
            if (isRedundant==true)
            {
                return true;
            }
            st.pop();
            
        }
    }
    return false;
}

int main()
{
    // stackNode *h = new stackNode(1);
    // push(2, h);
    // push(3, h);
    // display(h);
    // pop(h);
    // display(h);
    // pop(h);
    // display(h);
    // cout << top(h);

    // string s = "{{})){}";
    // cout << isValid(s);

    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    // insertAtBottom(st, 0);
    for (int i = 0; i < 5; i++)
    {
        cout << st.top() << " ";
        st.pop();
    }
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    reverseStack(st);
    for (int i = 0; i < 5; i++)
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}