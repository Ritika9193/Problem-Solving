class Solution {
public:
    void solve(TreeNode* root, int targetSum,vector<int> ans,int & cnt){
        if(root == NULL)
        return;

        ans.push_back(root->val);

        solve(root->left,targetSum,ans,cnt);
        solve(root->right,targetSum,ans,cnt);

        int size = ans.size();
        long long sum = 0;
        for(int i = size-1;i>=0;i--){
            sum += ans[i];
            if(sum == targetSum)
            cnt++;
        }

        ans.pop_back();

    }
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> ans;
        int cnt = 0;
        solve(root,targetSum,ans,cnt);
        return cnt;
    }
};