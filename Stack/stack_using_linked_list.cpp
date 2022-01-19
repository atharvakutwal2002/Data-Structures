#include <iostream>
using namespace std;

//all functions are O(1)
template <typename T>
class Node
{
    // T data;
    // Node<T> *next;
    // int size = 0;

public:
    T data;
    Node<T> *next;
    int size = 0;
    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class Stack
{
    Node<T> *head;
    int size;

public:
    Stack()
    {
        head = NULL;
        size = 0;
    }
    int getSize()
    {
        return size; ///   0(1)
    };
    bool isEmpty()
    {
        return size == 0;          ///   0(1)
    };
    void push(T ele)
    {
        Node<T> *n = new Node<T>(ele);
        n->next = head;                          ///   0(1)
        head = n;
        size++;
    };
    void pop()
    {
        if (head == NULL)
        {
            cout << " Stack Empty " << endl;
            return;
        }                                               
        Node<T> *temp = head;           ///   0(1)
        head = head->next;
        temp->next = NULL ;
         delete temp;
        size--;
    };
    T top()
    {
        if (isEmpty())
        {
            cout << "Stack Empty " << endl;           ///   0(1)
        }

        return head->data;
    };
};

int main()
{
    Stack<char> s;
    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);

    cout<<s.top()<<endl;
    s.pop();

    cout<<s.top()<<endl;
    s.pop();

    cout<<s.top()<<endl;
    s.pop();


    cout<<s.getSize()<<endl;
    
    cout<<s.isEmpty()<<endl;

    return 0;
}