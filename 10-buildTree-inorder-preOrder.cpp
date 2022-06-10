#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};
// class Solution{
//     public:
//     int findPosition(int in[],int element,int n)
//     {
//         for(int i=0;i<n;i++)
//         {
//             if(in[i]==element)
//             {
//                 return i;
//             }
//         }
//         return -1;
//     }
//     Node* solve(int in[],int pre[],int &index,int iS,int iE,int n)
//     {
//         // here iS and iE is inorder start and end respectively
//         // index is index of preOrder Array
//         if(index>=n || iS>iE)
//         {
//             return NULL;
//         }

//         int element = pre[index++];

//         Node* root = new Node(element);

//         int position = findPosition(in,element,n);

//         //recursive calls
//         root->left = solve(in,pre,index,iS,position-1,n);
//         root->right = solve(in,pre,index,position+1,iE,n);

//         return root;

//     }
//     Node* buildTree(int in[],int pre[], int n)
//     {
//         int preOrderIndex = 0;
//        Node*ans  =  solve(in,pre,preOrderIndex,0,n-1,n);

//     }
// };
int findPosition(int in[], int element, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (in[i] == element)
        {
            return i;
        }
    }
    return -1;
}
Node *solve(int in[], int pre[], int &index, int iS, int iE, int n)
{
    // here iS and iE is inorder start and end respectively
    // index is index of preOrder Array
    if (index >= n || iS > iE)
    {
        return NULL;
    }

    int element = pre[index++];

    Node *root = new Node(element);

    int position = findPosition(in, element, n);

    // recursive calls
    root->left = solve(in, pre, index, iS, position - 1, n);
    root->right = solve(in, pre, index, position + 1, iE, n);

    return root;
}
Node *buildTree(int in[], int pre[], int n)
{
    int preOrderIndex = 0;
    Node *ans = solve(in, pre, preOrderIndex, 0, n - 1, n);
    return ans;
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
}
int main()
{
    int in[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int pre[] = {1, 2, 4, 8, 5, 3, 6, 7};
    int n = sizeof(in) / sizeof(in[0]);

    Node *root = buildTree(in, pre, n);

    // cout<<"Preorder traversal of tree is: "<<endl;
    // preOrder(root);
    levelOrderTraversal(root);
    return 0;
}