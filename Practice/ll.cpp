#include<bits/stdc++.h>
using namespace std;


class listNode{
    public:
    int data;
    listNode* next;
    listNode(int x){
        this->data= x;
        this->next=nullptr;
    }

    void add(int x, listNode * head){
        listNode * temp = new listNode(x);
        head ->next = temp;
        head = temp;
    }

    int size(listNode * head){
        int x=0;
        listNode * temp= head ;
        while (temp)
        {
            x++;
            temp=temp->next;
        }
        return x;

    }
    bool isEmpty(listNode * head){
        if(head==NULL){
            return true;
        }
        return false;
    }
};


int main(){


    return 0;
}