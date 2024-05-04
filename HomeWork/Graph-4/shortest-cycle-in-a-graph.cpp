class Solution {
public:
    int ans=INT_MAX;
    void bfs(int i,vector<int>adj[],vector<int>&vis,vector<int>&dis){
        queue<pair<int,int>>q;
        q.push({i,-1});
        vis[i]=1;
        dis[i]=0;
        //node,parent
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto it:adj[node]){
                if(vis[it]==0){
                    dis[it]=dis[node]+1;
                    q.push({it,node});
                    vis[it]=1;
                }
                else if(it !=parent){
                    ans=min(ans,dis[it]+dis[node]+1);
                }
            }
        }
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<int>adj[n+1];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++){
            vector<int>vis(n+1,0);
            vector<int>dis(n+1,INT_MAX);
            bfs(i,adj,vis,dis);
        }
        if(ans==INT_MAX){
            return -1;
        }
        else {
            return ans;
        }
    }
};