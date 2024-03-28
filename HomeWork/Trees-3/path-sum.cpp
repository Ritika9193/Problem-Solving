class Solution {
public:
    bool solve(TreeNode* root,int targetSum, int sum){
        if(root==NULL){
            return false;
        }
        if(root->left==NULL && root->right==NULL){
            if(targetSum==sum+root->val){
                return true;
            }
            return false;
        }
        bool left=solve(root->left,targetSum,sum+root->val);
        bool right=solve(root->right,targetSum,sum+root->val);
        return right||left;
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        return solve(root,targetSum,sum);
    }
};