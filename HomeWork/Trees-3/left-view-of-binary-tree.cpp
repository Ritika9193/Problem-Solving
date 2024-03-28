void solve(BinaryTreeNode<int>* root,vector<int> &ans, int lvl){
    if(root == NULL) return;
    if(ans.size() < lvl){
        ans.push_back(root->data);
    }
    solve(root->left, ans, lvl+1);
    solve(root->right, ans, lvl+1);
}

vector<int> printLeftView(BinaryTreeNode<int>* root) {
    vector<int> ans;
    solve(root, ans, 1);
    return ans;
}