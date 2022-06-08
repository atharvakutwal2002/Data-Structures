#include <bits/stdc++.h>
using namespace std;

void floyd_cycle(Node *head)
{

    Node *slow = head;
    Node *fast = head;
    while (slow != NULL && fast != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow->next == fast->next)
        {
            cout << "Cycle present " << endl;
        }
    }
    cout << "cycle not present " << endl;
}