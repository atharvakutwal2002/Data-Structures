#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void insert_at_head(int data, Node * &head)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insert_at_tail(int data, Node *tail)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = tail->next;
}

void display(Node *head)
{
    Node * temp= head;
    while (temp != NULL)
    {
        cout << temp->data << "-->>";
        temp = temp->next;
        
    }
    cout<<endl;
}

void middle(Node * head){
    Node * first_temp=head; 
    Node * second_temp=head; 
    while ((second_temp->next)!=NULL)
    {
        second_temp=second_temp->next->next;
        first_temp=first_temp->next;

    }
    cout<< first_temp->data;
    
}

/* 

    1 9 5 2 10
    
    for  first iteration 
    st=5
    ft=9
     
    for second iteration  
    st=10
    ft=5


 */

int main()
{
    Node * n1= new Node(10);
    display(n1);
    insert_at_head(2,n1);
    insert_at_head(5,n1);
    insert_at_head(9,n1);
    insert_at_head(1,n1);
    display(n1);
    // insert_at_tail(4,n1);
    // display(n1);
    middle(n1);


    return 0;
}