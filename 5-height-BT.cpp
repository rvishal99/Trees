#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
class solution
{
public:
    // function to find the height of a binary tree
    int height(node *root)
    {
        // base case
        if (root == NULL)
        {
            return 0;
        }
        int l = height(root->left);
        int r = height(root->right);

        int ans = max(l, r) + 1;
        return ans;
    }
};
int main()
{

    return 0;
}