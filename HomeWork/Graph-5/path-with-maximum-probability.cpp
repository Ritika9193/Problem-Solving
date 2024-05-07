class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<double,int>>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({succProb[i],edges[i][1]});
            adj[edges[i][1]].push_back({succProb[i],edges[i][0]});
        }
        vector<double>dist(n,DBL_MIN);
        vector<bool>vis(n,false);
        dist[start_node]=1.0;
        priority_queue<pair<double,int>>pq;
        pq.push({1.0,start_node});
        while(!pq.empty()){
            int node=pq.top().second;
            pq.pop();
            if(!vis[node]){
                vis[node]=true;
                for(auto it:adj[node]){
                    int adjnode=it.second;
                    double adjwt=it.first;
                    if(dist[adjnode]<dist[node]*adjwt){
                        dist[adjnode]=dist[node]*adjwt;
                        pq.push({dist[adjnode],adjnode});
                    }
                }
            }
        }
        return dist[end_node];
    }
};