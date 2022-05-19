/*
int sum(TreeNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return root->val + sum(root->left) + sum(root->right);
}
bool isSumTree(TreeNode<int>*root)
{
    // base case
    if(root==NULL || ((root->left==NULL)&&(root->right==NULL)))
       {
           return true;
       }
       int leftSum = sum(root->left);
       int rightSum = sum(root->right);

       if((root->val==leftSum+ rightSum)&&(isSumTree(root->left))&&(isSumTree(root->right)))
       {
            return true;
       }
       return false;
}
*/