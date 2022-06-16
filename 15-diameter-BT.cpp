#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node *left,*right;

    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};
int getWidth(node *root,int level)
{
     if (root == NULL)
        return 0;
 
    if (level == 1)
        return 1;
 
    else if (level > 1)
    return getWidth(root->left, level - 1)+ getWidth(root->right, level - 1);
}
int height(node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int l = height(root->left);
    int r = height(root->right);

    return 1+max(l,r);
}
int getMaxWidth(node *root)
{
    int max = 0, width, h = height(root);

    for (int i = 1; i <=h; i++)
    {
        width = getWidth(root,i);
        if(width>max)
        {
            max = width;
        }
    }
    return max;
}
int main()
{

    return 0;
}