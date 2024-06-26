class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n=grid.size();
	    int m=grid[0].size();
	    vector<vector<int>>vis(n,vector<int>(m,0));
	    vector<vector<int>>dist(n,vector<int>(m,0));
	    queue<pair<pair<int,int>,int>>q;
	    //q({{row,col},dis})
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1){
	                q.push({{i,j},0});
	                vis[i][j]=1;
	            }
	            else{
	                vis[i][j]=0;
	            }
	        }
	    }
	    int delr[4]={-1,0,1,0};
	    int delc[4]={0,1,0,-1};
	    while(!q.empty()){
	        int row=q.front().first.first;
	        int col=q.front().first.second;
	        int dis=q.front().second;
	        q.pop();
	        dist[row][col]=dis;
	        vis[row][col]=1;
	        for(int i=0;i<4;i++){
	            int nrow=row+delr[i];
	            int ncol=col+delc[i];
	            if((nrow>=0 && nrow<n) && (ncol>=0 && ncol<m) && vis[nrow][ncol]==0 ){
	                q.push({{nrow,ncol},dis+1});
	                vis[nrow][ncol]=1;
	            }
	        }
	    }
	    return dist;
	}
};
