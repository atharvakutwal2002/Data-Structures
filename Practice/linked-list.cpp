#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node(){
        int value= this->data;
        if (this->next!=NULL)
        {
            delete next;
            this->next=NULL;
        }
        

    }
};

void insert_at_head(int data, Node *&head)
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
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "-->>";
        temp = temp->next;
    }
    cout << endl;
}

void middle(Node *head)
{
    Node *first_temp = head;
    Node *second_temp = head;
    while ((second_temp->next) != NULL)
    {
        second_temp = second_temp->next->next;
        first_temp = first_temp->next;
    }
    cout << first_temp->data;
}
void deleteNode(int x, Node *head)
{
    if (head->data==x)
    {
        Node * temp=head;
        head=head->next;
        delete temp;
    }
    
    
    Node *prev = head;
    Node *temp = prev->next;
    Node *after = temp->next;

    if (temp->data == x)
    {
        prev->next = after;
        temp->next = NULL;
    }
    if (temp->data == x && temp->next==NULL)
    {
        prev->next = NULL;
        temp->next = NULL;
    }
}

int countNodes(Node* head){
    int x=0;
    Node *temp= head;
    while (temp!=NULL)
    {
        x++;
        temp=temp->next;

    }
    return x;
    
}


void isSorted(Node* head){
    Node * temp=head;
    Node *nextnode=head->next;
    while(nextnode!=NULL){
        temp=temp->next;
        nextnode=nextnode->next;
        if (temp->data > nextnode->data)
        {
            cout<<"Not sorted"<<endl;
            return;
        }
        cout<<"Sorted"<<endl;
        return;
        
        
        
    }
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
    Node *n1 = new Node(100);
    
    insert_at_head(90, n1);
    insert_at_head(80, n1);
    insert_at_head(70, n1);
    insert_at_head(60, n1);
    cout<<countNodes(n1)<<endl;
    isSorted(n1);
    display(n1);
    deleteNode(1,n1);
    display(n1);
    
    

    return 0;
}