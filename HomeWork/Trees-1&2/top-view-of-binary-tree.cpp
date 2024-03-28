class Solution
{
    public:
    vector<int> topView(Node *root)
    {
        map<int, int> mp;
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        queue<pair<Node*, int> > q;
        q.push(make_pair(root, 0));
        
        while(!q.empty()){
            pair<Node*, int> node = q.front();
            Node* frontNode = node.first;
            int hd = node.second;
            
            q.pop();
            
            if(mp.find(hd) == mp.end()){
                mp[hd] = frontNode->data;
            }
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left, hd-1));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right, hd+1));
            }
        }
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }

};