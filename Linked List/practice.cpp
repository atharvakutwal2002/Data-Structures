#include <bits/stdc++.h>
using namespace std;

ListNode *reverse(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    ListNode *prev = NULL;
    ListNode *curr = head;

    while (curr && nxt)
    {
        ListNode *nxt = curr->next;
        curr->next = prev;
        prev=curr;
        curr = nxt;
    }

    return curr;
}

//   1 -> 2 -> 3-> 4 -> 5 -> 6