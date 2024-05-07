class Solution{
    public:
        int minimumEdgeReversal(vector<vector<int>> &edges,int n,int src,int dst)
        {
            vector<pair<int,int>>adj[n+1];
            for(int i=0;i<edges.size();i++){
                adj[edges[i][0]].push_back({edges[i][1],0});
                adj[edges[i][1]].push_back({edges[i][0],1});
            }
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
            vector<int>dist(n+1,1e9);
            dist[src]=0;
            pq.push({0,src});
            while(!pq.empty()){
                int dis=pq.top().first;
                int node=pq.top().second;
                pq.pop();
                for(auto it:adj[node]){
                    int edgewt=it.second;
                    int adjnode=it.first;
                    if(dis+edgewt<dist[adjnode]){
                        dist[adjnode]=dis+edgewt;
                        pq.push({dist[adjnode],adjnode});
                    }
                }
            }
            if(dist[dst]==1e9){
                return -1;
            }
            else{
                return dist[dst];
            }
        }
};