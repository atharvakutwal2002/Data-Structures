#include <bits/stdc++.h>
using namespace std;

class cQueue
{
public:
    int *arr;
    int size;
    int front;
    int rear;
    cQueue(int m)
    {
        size = m;
        arr = new int[size];
        front = rear = -1;
    }
    bool enqueue(int m)
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            return false;
        }
        else if (front == -1)
        {
            front = rear = 0;
        }
        else if (rear = size - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = m;
        return true;
    }
    int dequeue()
    {
        if (front == -1)
        {
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
        return ans;
    }
};