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
            cout << arr[i] <<" ";
        }
        cout<<endl;
    }
};

int main()
{
    Stack s(5);
   s.add(1);
   s.add(2);
   s.add(3);
   s.add(4);
   s.add(5);
   s.print_stack();
   s.add(6);
   s.pop();
   s.add(6);
   s.print_stack();
   s.pop();
   s.pop();
   s.pop();
   s.pop();
   s.pop();
   s.pop();
   s.pop();

    return 0;
}