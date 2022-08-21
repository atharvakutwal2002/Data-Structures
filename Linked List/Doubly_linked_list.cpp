#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};

void insertAtHead(int data, Node *&head)
{
    Node *temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(int data, Node *&tail)
{
    Node *temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPosition(int n, int data, Node *&head)
{
    Node *temp = new Node(data);

    Node *prev_pos = head;
    Node *mid_pos = head->next;

    for (int i = 0; i < (n - 1); i++)
    {
        prev_pos = prev_pos->next;
        mid_pos = mid_pos->next;
    }
    prev_pos->next = temp;
    temp->prev = prev_pos;
    temp->next = mid_pos;
    mid_pos->prev = temp;
}

void Print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {

        cout << temp->data << " <<=>> ";
        temp = temp->next;
    }
}

void Delete(int data, Node *&head)
{
    Node *prev = head;
    Node *temp = head->next;
    while (temp->data != data)
    {
        prev = prev->next;
        temp = temp->next;
    }
    prev->next = temp->next;
    temp->next->prev = prev;
    delete temp;
}

void reverse(Node *head)
{

    Node *p = head;
    Node *temp;
    while (p)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev; //as we are reversing the conditions are reversed 
        if (p->next == NULL)
        {
            head = p;
        }
    }
}

int main()
{
    Node *n1 = new Node(9);
    cout << n1->data << endl;
    insertAtHead(8, n1);
    insertAtHead(5, n1);
    insertAtHead(7, n1);
    // Print(n1);
    insertAtPosition(3, 90, n1);
    Delete(90, n1);
    Print(n1);
    return 0;
}