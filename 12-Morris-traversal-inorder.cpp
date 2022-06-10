#include <iostream>
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
void morrisT(node *root)
{
    node *pre, *curr;
    if (root == NULL)
    {
        return;
    }
    curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            cout << curr->data<<" ";
            curr = curr->right;
        }
        else
        {
            // intialising pre
            pre = curr->left;
            while (pre->right != NULL && pre->right != curr)
            {
                pre = pre->right;
            }
            if (pre->right == NULL)
            {
                pre->right = curr;
                curr = curr->left;
            }
            else // pre->right==curr
            {
                pre->right = NULL;
                cout << curr->data<<" ";
                curr = curr->right;
            }
        }
    }
}
node *buildTree(node *root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;

    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}
int main()
{
    node * root = NULL;
    root = buildTree(root);

    morrisT(root);
    return 0;
}