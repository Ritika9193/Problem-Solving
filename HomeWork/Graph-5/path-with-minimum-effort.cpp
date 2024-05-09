class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> > pq;
        pq.push({0,{0,0}});
        //{dis,{row,col}}
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));

        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        while(!pq.empty()){
            int dis=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(row==n-1 && col==m-1) return dis;
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int newdis=max(dis,abs(grid[nrow][ncol]-grid[row][col]));
                    if(newdis<dist[nrow][ncol]){
                        dist[nrow][ncol]=newdis;
                        pq.push({newdis,{nrow,ncol}});
                    }
                }
            }
        }
        return 0;
    }
};