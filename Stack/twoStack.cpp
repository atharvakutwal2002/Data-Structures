#include <bits/stdc++.h>
using namespace std;

class twoStack
{
public:
    int *arr;

    int top1;
    int top2;
    int size;
    twoStack(int size)
    {
        this->size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }
    void push1(int data)
    {
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = data;
        }
        else
        {
            cout << "Stack 1 overflow " << endl;
        }
    }
    void push2(int data)
    {
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = data;
        }
        else
        {
            cout << "Stack 2 overflow " << endl;
        }
    }
    void pop1()
    {
        if (top1 == -1)
        {
            cout << "Stack 1 underdlow" << endl;
        }
        else
        {
            arr[top1]=0;
            top1--;
        }
    }
    void pop2()
    {
        if (top2 == size)
        {
            cout << "Stack 2 underdlow" << endl;
        }
        else
        {
            arr[top2]=0;
            top2++;
        }
    }
    int peek1(){
        if (top1!=-1)
        {
            return arr[top1];
        }
        return -1;
        
    }
    int peek2(){
        if (top2!=size)
        {
            return arr[top2];
        }
        return -1;
        
    }
    void display(){
        for (int i = 0; i < size; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    twoStack st(5);
    st.push1(1);
    st.push1(2);
    st.display();
    st.push2(5);
    st.push2(4);
    st.pop1();
    st.pop2();
    st.display();
    return 0;

}