class Solution {
public:
    pair<int,int> diameter(TreeNode* root){
        if(root==NULL){
            pair<int,int>p=make_pair(0,0);
            return p;
        }
        pair<int,int>l=diameter(root->left);
        pair<int,int>r=diameter(root->right);
        int op1=l.first;
        int op2=r.first;
        int op3=l.second+r.second;
        pair<int,int>ans;
        ans.first=max(op1,max(op2,op3));
        ans.second=max(l.second,r.second)+1;
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root).first;
        
    }
};