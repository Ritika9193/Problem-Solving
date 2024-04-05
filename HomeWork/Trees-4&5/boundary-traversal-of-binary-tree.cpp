class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };
vector<int> res;

void traverseLeft(TreeNode<int>* root){
  if(!root)   return;
  if(!root->left && !root->right)     return;
  
  res.push_back(root->data);

  if(root->left)  traverseLeft(root->left);
  else    traverseLeft(root->right);
}

void traverseRight(TreeNode<int>* root){
  if(!root)   return;
  if(!root->left && !root->right)     return;
  
  if(root->right)   traverseRight(root->right);
  else    traverseRight(root->left);
  
  res.push_back(root->data);
}

void traverseLeaf(TreeNode<int>* root){
  if(!root)   return;
  if(!root->left && !root->right)   {res.push_back(root->data); return;}
  
  traverseLeaf(root->left);
  traverseLeaf(root->right);
}
vector<int> traverseBoundary(TreeNode<int> *root)
{
	if(root->left || root->right)     res.push_back(root->data);
    if(root->left)    traverseLeft(root->left);
    traverseLeaf(root);
	  if(root)  traverseRight(root->right);

	  return res;
}