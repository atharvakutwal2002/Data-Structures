#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *BuildTree(Node *root)
{
    int data;
    cout << "Enter the  data ";
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }

    root = new Node(data);

    cout << "Enter the data to insert at left of " << data << endl;
    root->left = BuildTree(root->left);
    cout << "Enter the data to insert at right of " << data << endl;
    root->right = BuildTree(root->right);

    return root;
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {

            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    cout << endl;
}

void inorderPrint(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

void preorderPrint(Node *root)
{
    if (!root)
    {
        return;
    }

    cout << root->data << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

void postOrderPrint(Node *root)
{
    if (!root)
    {
        return;
    }
    postOrderPrint(root->left);
    postOrderPrint(root->right);
    cout << root->data << " ";
}

int main()
{
    Node *root = NULL;
    root = BuildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // levelOrderTraversal(root);
    inorderPrint(root);

    return 0;
}