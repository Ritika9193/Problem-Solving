class Solution {
public:
    void solve(TreeNode*root,vector<vector<int>>&ans,vector<int>&temp,int target){
        if(root!=NULL){
            temp.push_back(root->val);
            if(root->left==NULL && root->right==NULL && root->val==target){
                ans.push_back(temp);
            }
            solve(root->left,ans,temp,target-root->val);
            solve(root->right,ans,temp,target-root->val);
            temp.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(root,ans,temp,targetSum);
        return ans;
    }
};
