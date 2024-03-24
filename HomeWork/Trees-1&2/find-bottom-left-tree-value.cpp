class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int leftmostValue=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int len=q.size();
            leftmostValue=q.front()->val;
            vector<int>res;
            while(len--){
                TreeNode* front=q.front();
                q.pop();
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
        }
        return leftmostValue;
    }
};