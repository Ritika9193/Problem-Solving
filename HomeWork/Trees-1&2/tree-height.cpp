int heightOfBinaryTree(TreeNode<int> *root)
{
	if(root==NULL){
        return 0;
    }
    int left=heightOfBinaryTree(root->left);
    int right=heightOfBinaryTree(root->right);
    return 1+max(left,right);
}