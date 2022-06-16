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
void convertIntoMirror(node* root)
{
    if(root==NULL)
    {
        return ;
    }
    node *temp = NULL;

    convertIntoMirror(root->left);
    convertIntoMirror(root->right);

    temp->left = root->right;
    temp->right = root->left;
}
int main()
{

    return 0;
}