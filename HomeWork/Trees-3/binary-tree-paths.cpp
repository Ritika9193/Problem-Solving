class Solution {
public:
    void solve(TreeNode* root, vector<string> &ans, string curr){
        if(root->left == NULL && root->right == NULL ){
            curr += to_string(root->val);
            ans.push_back(curr);
            curr.pop_back();
            return;
        }
        curr += to_string(root->val)+"->";
        if(root->left){
        solve(root->left,ans, curr);
        }
        if(root->right){
        solve(root->right,ans, curr);
        }
        curr.pop_back();
        curr.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string curr;
        solve(root, ans, curr);
        return ans;
    }
};