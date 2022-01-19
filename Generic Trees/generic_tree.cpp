#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;
    TreeNode(T data)
    {
        this->data = data;
    }
    ~TreeNode()
    {                                                        ///  destructor
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};

// void printtree(TreeNode<int> *root)
// {
//     if (root->data == NULL)
//     {
//         return; // <<<<<<<<<--------edge case (Not a base case)
//     }

//     cout << root->data << " : ";
//     for (int i = 0; i < root->children.size(); i++)
//     {
//         cout << root->children[i]->data << " , ";
//     }
//     cout << endl;

//     for (int i = 0; i < root->children.size(); i++)
//     {
//         printtree(root->children[i]);
//     }
// }

TreeNode<int> *takeinput() //complex way as it is recurssive
{
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    int n;
    cout << "enter the no. of childrens " << rootData << endl;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        TreeNode<int> *child = takeinput(); //storing child parent for building connection with root as it has return type of Treenode
        root->children.push_back(child);    //storing child (address of parent of child tree) in the vector of root .
    }
    return root;

    // here no base case as leaf node acts as base case and returns their root
}

TreeNode<int> *takeinputlevelwise() // 1. create node          2. push node         3.connect the node with its parent
{
    queue<TreeNode<int> *> q;
    int rootData;
    cout << "Enter Root Data " << endl; //creating rootnode
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    q.push(root);
    while (!q.empty()) //loop will take input level wise
    {
        TreeNode<int> *f = q.front(); //storing in f variable (of type TreeNode) for taking input for next level and making connections
        q.pop();                      //this will remove the node of which childrens have been taken
        cout << "Enter no .of children of " << f->data << endl;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int childData;
            cout << "Enter " << i << " th child of " << f->data << endl;
            cin >> childData;                                    //taking data
            TreeNode<int> *child = new TreeNode<int>(childData); //making node of taken data
            q.push(child);                                       //pushing that node into queue
            f->children.push_back(child);                        //connecting the child to root(parent by pushing it in vector("children"))
        }
    }
    return root;
}

void printtreelevelwise(TreeNode<int> *root)
{
    queue<TreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode<int> *f = q.front();
        q.pop();
        cout << f->data << " : ";
        for (int i = 0; i < f->children.size(); i++)
        {
            cout << root->children[i]->data << " , ";
        }
        cout << endl;
        for (int i = 0; i < f->children.size(); i++)
        {
            q.push(f->children[i]);
        }
    }

    /*  This function works similarly to takeinputlevelwise 
    i.e first it creates temp node f which holds root and then prints 
    that root and then its child and simultaneously push into que all 
    child and removes f (temp node) and same process is followed for 
    child nodes  */
}

int countNode(TreeNode<int> *root)
{
    //there is no base case , if children is empty it will return and that acts as a base case
    if (root == NULL)
    {
        return 0; //edge case
    }

    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += countNode(root->children[i]);
    }
    return ans;
}

int height(TreeNode<int> *root)
{
    //there is no base case , if children is empty it will return and that acts as a base case
    if (root == NULL)
    {
        return 0; //edge case
    }
    int maxheight = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        /* int childheight=height(root->children[i]);
        if (childheight> maxheight)
        {
            maxheight=childheight;
        }*/
        maxheight = max(maxheight, height(root->children[i])); //by using inbuilt max function which returns max of the two values given
    }
    return maxheight + 1; //we are adding 1 here due to root node .
}
/*
void printAtLevelK(TreeNode<int> *root, int k)
{
    //there is no base case , if children is empty it will return and that acts as a base case
    if (root == NULL)
    {
        return; //edge case
    }
    if (k == 0)
    {
        cout << root->data << endl;
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printAtLevelK(root->children[i], k - 1);
    }
}*/
void printAtLevelK_2nd_method(TreeNode<int> *root, int k, int c = 0)
{
    //there is no base case , if children is empty it will return and that acts as a base case
    if (root == NULL)
    {
        return; //edge case
    }
    if (k == 0)
    {
        cout << root->data << endl;
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printAtLevelK_2nd_method(root->children[i], k - 1, c + 1);
    }
}
/*
int countLeafNode(TreeNode<int>*root){
    if (root->children.size()==0)
    {
        return 1;
    }
    int ans=0;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans+=countLeafNode(root->children[i]);
    }
    return ans;
    
}*/

void countLeafNode_another_method(TreeNode<int> *root, int &ans)
{

    if (root->children.size() == 0)
    {
        ans++;
        return;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        countLeafNode_another_method(root->children[i], ans);
    }
}

void preOrder(TreeNode<int> *root)
{
    if (root == NULL)
    { /// edge case
        return;
    }
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preOrder(root->children[i]);
    }
}

void postOrder(TreeNode<int> *root)
{
    if (root == NULL)
    { /// edge case
        return;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        postOrder(root->children[i]);
    }

    cout << root->data << " ";
}

// void deleteTree(TreeNode<int>*root){
//     if(root==NULL){  /// edge case
//         return ;
//     }

//     for (int i = 0; i < root->children.size(); i++)
//     {
//         deleteTree(root->children[i]);
//     }
//     delete root;

// }

void deleteTree(TreeNode<int> *root)
{
    if (root == NULL)
    { /// edge case
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        deleteTree(root->children[i]);
    }
    delete root;
}

/// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
int main()
{
    // TreeNode<int> *root = new TreeNode<int>(1);
    // TreeNode<int> *n1 = new TreeNode<int>(2);
    // TreeNode<int> *n2 = new TreeNode<int>(3);
    // root->children.push_back(n1);
    // root->children.push_back(n2);
    TreeNode<int> *root = takeinputlevelwise();

    printtreelevelwise(root);
    // printtree(root);
    cout << "Total Nodes : " << countNode(root) << endl;
    cout << "height : " << height(root) << endl;
    cout << "Nodes at level 2 :" << endl;
    // printAtLevelK(root, 2);
    printAtLevelK_2nd_method(root, 2);

    int leafnodes = 0;
    countLeafNode_another_method(root, leafnodes);
    cout << "Leaf Nodes : " << leafnodes << endl;
    cout << " preorder traversal is " << endl;
    preOrder(root);
    cout << endl;
    cout << " postorder traversal is " << endl;
    postOrder(root);
    cout << endl;
    cout << "deleting the tree ...." << endl;
    delete (root);
    cout << endl;
    cout << "printing tree again for checking whether it is deleted or not " << endl;
    printtreelevelwise(root);
    return 0;
}