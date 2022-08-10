#include <bits/stdc++.h>
using namespace std;

// class QueueNode
// {
// public:
//     int data;
//     QueueNode *next;
//     QueueNode(int data)
//     {
//         this->data = data;
//         this->next = NULL;
//     }
// };

// void insertAtHead(QueueNode * head,QueueNode * tail , int data){
//     QueueNode * temp= new QueueNode(data);
//     if(head ==NULL){
//         head= temp;
//         tail=temp;
//     }else{
//         tail->next= temp;
//         tail=temp;
//     }
// }

int main()
{
    int x = 9;
    int *y = &x;
    int **z = &y;

    cout << &y << endl;
    cout << &x << endl;
    cout << y << endl;
    cout << z << endl;
    cout << &y << endl;
    cout << *y << endl;
    cout << *z << endl;

    return 0;
}