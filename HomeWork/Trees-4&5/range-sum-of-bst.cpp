/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root,vector<int>& in){
        if(root==NULL){
            return;
        }
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> ans;
        inorder(root,ans);
        int sum=0;
        for(int i=0;i<ans.size();i++){
            if(ans[i]>=low && ans[i]<=high){
                sum+=ans[i];
            }
        }
        return sum;
    }
};