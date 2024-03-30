class Solution {
public:
    bool getpath(TreeNode* root, int tar, string& path){

        if(root==NULL) 
            return false;
        if(root->val==tar)
            return true;
        bool left = getpath(root->left,tar,path);
        if(left){
            path += 'L';
            return true;
        }
        bool right = getpath(root->right,tar,path);
        if(right){
            path += 'R';
            return true;
        }
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string pathstart = "";
        getpath(root,startValue,pathstart);
        string pathdest = "";
        getpath(root,destValue,pathdest);
        int i=pathstart.size()-1;
        int j=pathdest.size()-1;
        while(i>=0 && j>=0 && pathstart[i]==pathdest[j]){
            pathstart.pop_back();
            pathdest.pop_back();
            i--;
            j--;
        }
        i = pathstart.size();
        for(int j=0; j<i; j++){
            pathstart[j] = 'U';
        }
        reverse(pathdest.begin(),pathdest.end());
        return pathstart + pathdest;
    }
};