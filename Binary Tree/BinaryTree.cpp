// #include <iostream>
#include <bits/stdc++.h>
// #include <queue>
// #include <vector>
using namespace std;

template <typename T>
class BTNode
{
public:
    T data;
    BTNode *left;
    BTNode *right;
    BTNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BTNode()
    { // recursive destructor
        delete left;
        delete right;
    }
};

void printTree(BTNode<int> *root)
{
    if (root == NULL)
    { // base case
        return;
    }

    cout << root->data << " : ";
    if (root->left != NULL)
    {
        cout << " L" << root->left->data;
    }
    if (root->right != NULL)
    {
        cout << " R" << root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}
BTNode<int> *takeInput()
{
    int rootData;
    cout << "Enter Data " << endl;
    cin >> rootData;

    if (rootData == -1)
    { // bad way of giving input as we have to keep a track of recurrsion
        return NULL;
    }
    BTNode<int> *root = new BTNode<int>(rootData);
    root->left = takeInput();
    root->right = takeInput();

    return root;
}

BTNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    BTNode<int> *root = new BTNode<int>(rootData);
    queue<BTNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BTNode<int> *f = q.front();
        q.pop();
        cout << "Enter the left child " << f->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BTNode<int> *Child = new BTNode<int>(leftChildData);
            q.push(Child);
            f->left = Child;
        }
        cout << "Enter the right child " << f->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BTNode<int> *Child = new BTNode<int>(rightChildData);
            q.push(Child);
            f->right = Child;
        }
    }
    return root;
}

// leetcode problem for printing levelwise
//  void printlevelwise(BTNode<int> *root)
//  {
//      vector<vector<int>> v;
//      if (root == NULL)
//      {
//          return v;
//      }

//     vector<int> temp; //storing the result of current level
//     queue<BTNode<int> *> q;
//     q.push(root);
//     q.push(NULL);
//     while (!q.empty())
//     {
//         BTNode<int> *f = q.front();
//         q.pop();
//         if (f == NULL)
//         {
//             // cout<<endl;
//             v.push_back(temp);
//             temp.clear();
//             if (!q.empty())
//             {
//                 q.push(NULL);
//             }
//         }
//         else
//         {
//             temp.push_back(f->data);
//             if (f->left)
//             {
//                 q.push(f->left);
//             }
//             if (f->right)
//             {
//                 q.push(f->right);
//             }
//         }
//     }
// }
// leetcode problem
int countNodes(BTNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
}

void inorder(BTNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// leetcode problem inorder traversal (modified version of above code)
void inorder(BTNode<int> *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}
vector<int> inorderTraversal(BTNode<int> *root)
{
    vector<int> ans;
    inorder(root, ans);
    return ans;
}

// print root then left subtree and then right sub tree
void preorder(BTNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// leetcode problem for preorder traversal ;
void preorder(BTNode<int> *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    ans.push_back(root->data);
    preorder(root->left, ans);
    preorder(root->right, ans);
}
vector<int> preorderTraversal(BTNode<int> *root)
{
    vector<int> ans;
    preorder(root, ans);
    return ans;
}

// postorder traversal ==>> print left subtree right subtree and then root
void postorder(BTNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// leetcode problem for postorder traversal
void postorder(BTNode<int> *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    ans.push_back(root->data);
}
vector<int> postorderTraversal(BTNode<int> *root)
{
    vector<int> ans;
    postorder(root, ans);
    return ans;
}

// leetcode problem for finding max depth
int height(BTNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    // int final;
    // if (left > right)
    // {
    //     final = left;
    // }
    // else
    // {
    //     final = right;
    // }
    // return final + 1;
    return max(left, right) + 1;
}

// problem for findng whether the binary tree is symmetric or not using a helper function
bool helper(BTNode<int> *left, BTNode<int> *right)
{
    if (left == NULL && right != NULL)
    {
        return false;
    }
    if (left != NULL && right == NULL)
    {
        return false;
    }

    if (right == NULL && left == NULL)
    {
        return true;
    }
    if (left->data != right->data)
    {
        return false;
    }
    return helper(left->left, right->right) && helper(left->right, right->left);
}
bool issymmetric(BTNode<int> *root)
{
    if (root == NULL)
    {
        return true;
    }
    helper(root->left, root->right);
}

bool search(BTNode<int> *root, int key)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == key)
    {
        return true;
    }

    // search(root->left,key);
    // search(root->right,key);
    return search(root->left, key) || search(root->right, key);
}

// finding minimum value in tree
int findmin(BTNode<int> *root)
{
    if (root == NULL)
    {
        return INT_MAX;
    }

    int left = findmin(root->left);
    int right = findmin(root->right);
    return min(root->data, min(left, right));
}
void find_min_otherway(BTNode<int> *root, int &ans)
{
    if (root == NULL)
    {
        return;
    }
    ans = min(ans, root->data);
    find_min_otherway(root->left, ans);
    find_min_otherway(root->right, ans);
}

// finding max value
int findmax(BTNode<int> *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    int left = findmax(root->left);
    int right = findmax(root->right);
    return max(root->data, max(left, right));
}
void find_max_otherway(BTNode<int> *root, int &ans)
{
    if (root == NULL)
    {
        return;
    }
    ans = max(root->data, ans);
    find_max_otherway(root->left, ans);
    find_max_otherway(root->right, ans);
}

// counting leaf nodes
int count_leaf(BTNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    {
        /* code */
    }

    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    int leftsubtree = count_leaf(root->left);
    int rightsubtree = count_leaf(root->right);
    return leftsubtree + rightsubtree;
}
void countleafnode_other_way(BTNode<int> *root, int &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        ans++;
        return; // writing this return is optional
    }
    countleafnode_other_way(root->left, ans);
    countleafnode_other_way(root->right, ans);
}

//  Construct Tree from PreOrder and Inorder Traversal Solution (leetcode)
BTNode<int> *tree_build_helper(vector<int> inorder, vector<int> preorder, int inS, int inE, int preS, int preE)
{
    if (inS > inE)
    {
        return NULL;
    }

    int rootData = preorder[preS];
    int rootIndex = -1;
    for (int i = inS; i < inE; i++)
    {
        if (inorder[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }

    int leftInS = inS;
    int leftInE = rootIndex - 1;
    int leftPreS = preS + 1;
    int leftPreE = leftPreS + leftInE - leftInS;

    int rightInS = rootIndex + 1;
    int rightInE = inE;
    int rightPreS = leftPreE + 1;
    int rightPreE = preE;

    BTNode<int> *root = new BTNode<int>(rootData);
    root->left = tree_build_helper(inorder, preorder, leftInS, leftInE, leftPreS, leftPreE);
    root->right = tree_build_helper(inorder, preorder, rightInS, rightInE, rightPreS, rightPreE);
    return root;
}
BTNode<int> *build_tree(vector<int> &preorder, vector<int> &inorder)
{
    int n = inorder.size();
    return tree_build_helper(inorder, preorder, 0, n - 1, 0, n - 1);
}

// Construct Tree from PostOrder and Inorder Traversal Solution ( leetcode )
BTNode<int> *build_tree_helper(vector<int> inorder, vector<int> postorder, int inS, int inE, int postS, int postE)
{
    if (inS > inE)
    {
        return NULL;
    }
    int rootData = postorder[postE];
    int rootIndex = -1;
    for (int i = inS; i < inE; i++)
    {
        if (inorder[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }

    int leftInS = inS;
    int leftInE = rootIndex - 1;
    int leftpostS = postS;
    int leftpostE = leftpostS + leftInE - leftInS;

    int rightInS = rootIndex + 1;
    int rightInE = inE;
    int rightpostS = leftpostE + 1;
    int rightpostE = postE - 1;

    BTNode<int> *root = new BTNode<int>(rootData);
    root->left = build_tree_helper(inorder, postorder, leftInS, leftInE, leftpostS, leftpostE);
    root->right = build_tree_helper(inorder, postorder, rightInS, rightInE, rightpostS, rightpostE);
    return root;
}
BTNode<int> *build_tree(vector<int> &inorder, vector<int> &postorder)
{
    int n = inorder.size();
    return build_tree_helper(inorder, postorder, 0, n - 1, 0, n - 1);
}

// diameter of tree ( Leetcode )
int height_for_diameter(BTNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(height_for_diameter(root->left), height_for_diameter(root->right));
}
int diameter_of_tree(BTNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int opt1 = height_for_diameter(root->left) + height_for_diameter(root->right);
    int opt2 = diameter_of_tree(root->left);
    int opt3 = diameter_of_tree(root->right);

    return max(opt1, max(opt2, opt3));
}
// diameter of tree by another method ( better approach )
// class pair is inbuilt class (template) which contains first and second
pair<int, int> heightdiameter(BTNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> leftans = heightdiameter(root->left);
    pair<int, int> rightans = heightdiameter(root->right);

    int lh = leftans.first;
    int ld = leftans.second;

    int rh = rightans.first;
    int rd = rightans.second;

    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));

    pair<int, int> p;
    p.first = height;
    p.second = diameter;
    return p;
}
int diameter_of_tree_2(BTNode<int> *root)
{
    pair<int, int> p = heightdiameter(root);
    return p.second;
}

bool getPath(BTNode<int> *root, int val, vector<int> &ans)
{
    if (root == NULL)
    {
        return false;
    }
    ans.push_back(root->data);
    if (root->data == val)
    {
        return true;
    }
    bool left = getPath(root->left, val, ans);
    bool right = getPath(root->right, val, ans);

    if (left || right)
    {
        return true;
    } // return right || left ;

    ans.pop_back();
    return false;
}

int main()
{
    // BTNode<int> *root = new BTNode<int>(1);   // creating nodes dynamically
    // BTNode<int> *n1 = new BTNode<int>(2);
    // BTNode<int> *n2 = new BTNode<int>(3);
    // root->left = n1;
    // root->right = n2;
    // printTree(root);
    // delete root;
    // BTNode<int> *root = takeInput();
    BTNode<int> *root = takeInputLevelWise();
    // cout<<"height "<<height(root);
    // if (issymmetric(root))
    // {
    //     cout << "Symmetric binary tree" << endl;
    // }
    // else
    // {
    //     cout << "Not symmetric " << endl;
    // }
    // if (search(root,3))
    // {
    //     cout<<"Found";
    // }else{
    //     cout<<"Missing";
    // }
    // cout << findmin(root);

    // int mnVal=INT_MAX;
    // find_min_otherway(root,mnVal);
    // cout<<"min value other way "<< mnVal<<endl;

    cout << "leaf nodes : " << count_leaf(root) << endl;

    // cout<<countNodes<<endl;
    // inorder(root);
    // postorder(root);
    // printTree(root);
    // delete root;


    // finding path from root to given node 
    vector<int> v;
    if (getPath(root, 9, v))
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v.[i] << " ";
        }
    }
    else
    {
        cout << "No path found bcoz value 9 not present " << endl;
    }

    return 0;
}