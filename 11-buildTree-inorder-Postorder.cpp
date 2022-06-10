#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left, *right;
    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};
int search(int arr[], int s, int e, int val)
{
    for (int i = s; i <= e; i++)
    {
        if (arr[i] == val)
        {
            return i;
        }
    }
    return -1;
}
node *buildUtil(int in[], int po[], int iS, int iE, int *pIndex)
{
    // base case
    if (iS > iE)
    {
        return NULL;
    }
    node *temp = new node(po[*pIndex]);
    (*pIndex)--;

    /* If this node has no children then return */
    if (iS == iE)
    {
        return temp;
    }
    /* Else find the index of this node in Inorder
       traversal */

    int iIndex = search(in, iS, iE, temp->data);

    temp->right = buildUtil(in, po, iIndex + 1, iE, pIndex);
    temp->left = buildUtil(in, po, iS, iIndex - 1, pIndex);
    return temp;
}
node * buildTree(int in[],int po[],int n)
{
    int pIndex = n-1;
    return buildUtil(in,po,0,n-1,&pIndex);
}
void preOrder(node* root)
{
    if (root == NULL)
    {return ;}
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
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
}
int main()
{
    int in[] = { 4, 8, 2, 5, 1, 6, 3, 7 };
    int po[] = {8,4,5,2,6,7,3,1};
    int n = sizeof(in) / sizeof(in[0]);
 
    node* root = buildTree(in,po,n);

    // cout<<"Preorder traversal of tree is: "<<endl;
    // preOrder(root);
    levelOrderTraversal(root);
    return 0;
}