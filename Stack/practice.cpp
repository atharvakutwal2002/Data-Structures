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

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class Stack
{
public:
    int data;
    int top;
    Stack(int data, char c)
    {
        
        this->data=data;
        Node n(data);
    }
    void push(int data , Node * head ){
        top++;
        Node * temp=new Node(data);
        temp->next=head;
        head= temp;
    }
    void pop(Node * head){
        top--;

    }
};