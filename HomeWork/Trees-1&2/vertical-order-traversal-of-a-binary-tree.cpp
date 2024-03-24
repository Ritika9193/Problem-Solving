class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>>mp;
        //mp<hd,map<level,node>>>
        queue<pair<TreeNode*,pair<int,int>>>q;
        vector<vector<int>>newans;
        if(root==NULL){
            return newans;
        }
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty()){
            pair<TreeNode*,pair<int,int>> temp=q.front();
            q.pop();
            TreeNode* frontNode=temp.first;
            int hd=temp.second.first;
            int lvl=temp.second.second;
            mp[hd][lvl].push_back(frontNode->val);
            if(frontNode->left){
                q.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1)));
            }
        }
        for(auto i:mp){
            vector<int>ans;
            for(auto j : i.second){
                sort(j.second.begin(),j.second.end());
                for(auto k: j.second){
                    ans.push_back(k);
                }
            }
            newans.push_back(ans);
        }
        return newans;
    }
};