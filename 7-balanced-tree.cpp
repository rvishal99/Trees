// 1st approach with more time complexity(O(n2))
/*
int height(BinaryTreeNode<int>*root)
{
    if(root==NULL) return 0;

    return (max(height(root->left),height(root->right)) + 1);
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    if(root==NULL) return true;

    int lh = height(root->left);
    int rh = height(root->right);

    if(abs(lh-rh)<=1 && isBalancedBT(root->left) && isBalancedBT(root->right))return true;


    return false;
}
*/

// 2nd apprach using pairs with less time complexity of O(n)

/*
//Best Approach

//Follow me in insta  ID 123krrish2001;



pair<int,bool> helper(BinaryTreeNode<int>* root)

{

if(root==NULL)

{

   pair<int,bool>p;

   p.first = 0;

   p.second = true;

   return p;

}
pair<int,bool>leftans = helper(root->left);

   pair<int,bool>rightans = helper(root->right);

   int hl = leftans.first;

   int hr = rightans.first;

   bool lb = leftans.second;

   bool rb = rightans.second;

   int heightdiff = abs(hl-hr);

   int height = 1 + max(hl,hr);

   bool balanced = (lb && rb && heightdiff<=1);

   pair<int,bool>ans;

   ans.first = height;

   ans.second = balanced;

   return ans;

}
bool isBalancedBT(BinaryTreeNode<int>* root) {

    if(root==NULL)
   {
     return true;
   }
   return helper(root).second;

}
*/