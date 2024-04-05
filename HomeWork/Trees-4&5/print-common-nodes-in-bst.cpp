#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=right=NULL;
    }
}
class Solution
{
    public:
    
    void inorder1(Node* root, unordered_set<int>& m) {
        if (root == nullptr) {
            return;
        }
        inorder1(root->left, m);
        m.insert(root->data);
        inorder1(root->right, m);
    }
    
    void inorder2(Node* root, unordered_set<int>& m, vector<int>& arr) {
        if (root == nullptr) {
            return;
        }
        inorder2(root->left, m, arr);
        if (m.find(root->data) != m.end()) {
            arr.push_back(root->data);
        }
        inorder2(root->right, m, arr);
    }
 
    vector <int> findCommon(Node *root1, Node *root2)
    {
        unordered_set<int> m;
        vector<int> arr;
        inorder1(root1, m);
        inorder2(root2, m, arr);
        return arr;
    }
};