class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        int inorder[V]={0};
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                inorder[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(inorder[i]==0){
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            cnt++;
            for(auto it:adj[front]){
                inorder[it]--;
                if(inorder[it]==0){
                    q.push(it);
                }
            }
        }
        if(cnt==V) return false;
        return true;
    }
};