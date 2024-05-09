class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
            //stops,node,price
        }
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});

        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        while(!q.empty()){
            int stops=q.front().first;
            int node=q.front().second.first;
            int price=q.front().second.second;
            q.pop();
            if(stops>k) continue;

            for(auto it:adj[node]){
                int wt=it.second;
                int adjnode=it.first;
                if(dist[adjnode]>price+wt){
                    dist[adjnode]=price+wt;
                    q.push({stops+1,{adjnode,dist[adjnode]}});
                }
            }
        }
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};