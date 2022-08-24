#include <bits/stdc++.h>
using namespace std;

class queue
{
public:
    int *arr;
    int rear;
    int qfront;
    int size;

    queue()
    {
        size = 100001;
        arr = new int[size];
        rear = 0;
        qfront = 0;
    }

    bool isEmpty()
    {
        if (rear == qfront)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(int x)
    {
        if (rear == size)
        {
            cout << "The queue is full" << endl;
            return;
        }

        arr[rear] = x;
        rear++;
    }
    int pop()
    {
        if (qfront == rear)
        {
            return -1;
        }
        else
        {
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if (qfront == rear)
            {
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }
    int front(){
        if (qfront==rear)
        {
            return -1;
        }
        return arr[qfront];
        
    }
    
}