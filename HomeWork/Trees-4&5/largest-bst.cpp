class Solution{
    public:
    
     int size(Node *root) {
        if(!root) return 0;
        return size(root->left) + size(root->right) + 1;
    }
    
    bool isBST(Node *root, int mini, int maxi) {
        if(!root) return true;
        if(root->data <= mini or root->data >= maxi) return false;
        return isBST(root->left, mini, root->data) and isBST(root->right, root->data, maxi);
    }
    
    int largestBst(Node *root){
        if(isBST(root, INT_MIN, INT_MAX) == true) {
            return size(root);
        }
        return max(largestBst(root->left), largestBst(root->right));
    }
};