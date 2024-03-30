bool helper(TreeNode* root, int B, vector<int> &ans){
    if (root == NULL) {
        return false;
    }
    ans.push_back(root->val);

    if (root->val == B) {
        return true;
    }

    if (helper(root->left, B, ans) || helper(root->right, B, ans)) {
        return true;
    }

    ans.pop_back();
    return false;
     
 }
 
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    helper(A,B,ans);
    return ans;
}