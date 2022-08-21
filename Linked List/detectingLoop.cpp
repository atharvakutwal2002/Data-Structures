#include <bits/stdc++.h>
using namespace std;

bool hasLoop(Node *head)
{
    Node *fast = head;
    Node *slow = head;

    do
    {
        slow = slow->next;
        slow = slow->next;
        slow = slow ? slow->next : slow;
    } while (fast && slow && fast != slow);
    if (fast == slow)
    {
        return true;
    }
    return false;
}