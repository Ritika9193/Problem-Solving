class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //q{{row,col},time}
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        int vis[n][m];
        int cntfresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else{
                    vis[i][j]=0;
                }
                if(grid[i][j]==1) cntfresh++;
            }
        }
        int time=0;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        int cnt=0;
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            time=max(time,t);
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if((nrow>=0 && nrow<n)&&(ncol>=0 && ncol<m)&& grid[nrow][ncol]==1 && vis[nrow][ncol]!=2){
                    q.push({{nrow,ncol},time+1});
                    vis[nrow][ncol]=2;
                    cnt++;
                }
            }
        }
        if(cnt!=cntfresh) return -1;
        return time;
    }
};