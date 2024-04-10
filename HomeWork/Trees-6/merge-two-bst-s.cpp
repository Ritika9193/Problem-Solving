struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    void inorder(Node* root,vector<int>& ans){
        if(root==NULL){
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
    vector<int>merger(vector<int>ans1,vector<int>ans2,vector<int>&res){
        int i=0;
        int j=0;
        int n=ans1.size();
        int m=ans2.size();
        while(i<n && j<m){
            if(ans1[i]<ans2[i]){
                res.push_back(ans1[i]);
                i++;
            }
            else{
                res.push_back(ans2[j]);
                j++;
            }
        }
        while(i<n){
            res.push_back(ans1[i]);
            i++;
        }
        while(j<m){
            res.push_back(ans2[j]);
            j++;
        }
        return res;
    }
    vector<int> merge(Node *root1, Node *root2)
    {
       vector<int>ans1;
       inorder(root1,ans1);
       vector<int>ans2;
       inorder(root2,ans2);
       vector<int>res;
       merger(ans1,ans2,res);
       sort(res.begin(),res.end());
       return res;
    }
};