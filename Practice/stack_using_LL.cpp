#include <bits/stdc++.h>
using namespace std;

class stackNode
{
public:
    int data;
    stackNode *next;

    stackNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
stackNode* push(int data, stackNode *top)
{
    stackNode *temp = new stackNode(data);
    if (top == NULL)
    {
        top = temp;
    }
    else
    {
        temp->next = top;
        top = temp;
    }
    return top;
}

stackNode*  pop(stackNode *top)
{
    if (top)
    {
        stackNode *temp = top->next;
        top->next = NULL;
        top = temp;
    }
    return top;
}

bool isEmpty(stackNode *top)
{
    return top == NULL;
}

void printStack(stackNode * top){
    stackNode * temp = top;
    while (temp!= NULL)
    {
        if(temp==NULL){
            return ;
        }
        cout<<temp->data <<" ";
        temp= temp->next;
    }
    cout<<endl;
    
}

int main()
{

    stackNode* s= new stackNode(10);
    s=push(11, s);
    s=push(12, s);
    s=push(13, s);
    s=push(14, s);
    printStack(s);
    cout<<isEmpty(s)<<endl;
    s=pop(s);
    printStack(s);


    return 0;
}

//   2->1