// finding leaf nodes
/*
void inOrder(BinaryTreeNode<int> * root,int &count)
{
    // base case 
    if(root==NULL)
    {
        return ;
    }
    // L N R
//     inOrder(root->left);
//     cout<<root->data<<" ";
//     inOrder(root->right);
	
	//for leaf node 
	if(root->left==NULL && root->right==NULL)
	{
		count++;
	}
	inOrder(root->right,count);
	
}
int noOfLeafNodes(BinaryTreeNode<int> *root){
	int cnt = 0;
	inOrder(root,cnt);
	return cnt;
}
*/