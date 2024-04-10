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
    void inorder(TreeNode* root,TreeNode* &prev,TreeNode*& first, TreeNode*& middle,
    TreeNode*& last){
        if(root==NULL) return ;
        inorder(root->left,prev,first,middle,last);

        if(prev!=NULL && root->val<prev->val){
            // agar first element hai
            if(first==NULL){
                first=prev;
                middle=root;
            }
            else{
                last=root;
            }
        }
        prev=root;

        inorder(root->right,prev,first,middle,last);
    }
    void recoverTree(TreeNode* root) {
        TreeNode* first=NULL;
        TreeNode* middle=NULL;
        TreeNode* last=NULL;
        TreeNode* prev=new TreeNode(INT_MIN);
        inorder(root,prev,first,middle,last);
        if(first && last){
            swap(first->val ,last->val);
        }
        else if(first && middle){
            swap(first->val,middle->val);
        }

    }
};