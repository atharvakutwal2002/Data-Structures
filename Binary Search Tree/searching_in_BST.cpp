#include <bits/stdc++.h>
using namespace std;

class Treenode
{
public:
    int data;
    Treenode *left;
    Treenode *right;
};

// problem on leetcode for searching in binary search tree

//final sol
// recurrsive approach
Treenode *search(Treenode *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == val)
    {
        return root;
    }
    if (val > root->data)
    {
        return search(root->right, val);
    }
    else if (val < root->data)
    {
        return search(root->left, val);
    }
    return NULL;
}



// iterative appraoch
Treenode *search2(Treenode *root, int val)
{
    while (root != NULL)
    {
        if (root->data == val)
        {
            return root;
        }
        else if (val > root->data)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return NULL;
}

// finding min in BST
// Iterative solution
int findmin(Treenode *root)
{
    if (root == NULL)
    {
        return -1;
    }

    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}

// finding max in BST
// Iterative solution
int findmax(Treenode *root)
{
    if (root == NULL)
    {
        return -1;
    }

    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}

// leetcode problem for finding range sum
/*int rangeSumBST(Treenode *root, int L, int R)
{
    if (root == NULL)
    {
        return 0;
    }
    int sum = 0;
    if (root->data >= L && root->data <= R)
    {
        sum += root->data;
    }
    if (root->data > R)
    {
        sum += rangeSumBST(root->data, L, R);
    }
    else if (root->data < L)
    {
        sum += rangeSumBST(root->right, L, R);
    }
    else
    {
        sum += rangeSumBST(root->data, L, R) + rangeSumBST(root->right, L, R);
    }
    return sum;
}*/

// validate if the given tree is BST or not ( leetcode )
// Inorder traversal of BST is sorted

bool helper(Treenode *root, long long minV = -10000000000, long long maxV = 10000000000)
{
    if (root == NULL)
    {
        return true;
    }
    bool left = helper(root->left, minV, root->data);
    bool right = helper(root->right, root->data, maxV);
    if (left && right && root->data > minV && root->data < maxV)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isValidBST(Treenode *root)
{
    return helper(root);
}

// Convert a sorted array to a BST ( leetcode )

/*Treenode *helper(vector<int> &arr, int s, int e)
{
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + e) / 2;
    int rootData = arr[mid];
    Treenode *root = new Treenode(rootData);
    root->left = helper(arr, s, mid - 1);
    root->right = helper(arr, mid + 1, e);

    return root;
}
Treenode *sortedarrayToBST(vector<int> &nums)
{
    int n = nums.size();
    return helper(nums, 0, n - 1);
}*/