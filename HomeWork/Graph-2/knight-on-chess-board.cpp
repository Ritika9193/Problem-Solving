int Solution::knight(int A, int B, int C, int D, int E, int F) {
    vector<vector<int>>vis(A+1,vector<int>(B+1,0));
    queue<pair<pair<int,int>,int>>q;
    q.push({{C,D},0});
    vis[C][D]=1;
    int delr[8]={-2,-1,1,2,2,1,-1,-2};
    int delc[8]={1,2,2,1,-1,-2,-2,-1};
    while(!q.empty()){
        int row=q.front().first.first;
        int col=q.front().first.second;
        int dis=q.front().second;
        q.pop();
        if(row==E && col==F){
            return dis;
        }
        for(int i=0;i<8;i++){
            int nrow=row+delr[i];
            int ncol=col+delc[i];
            if((nrow>=1 && nrow<=A) && (ncol>=1 && ncol<=B) && vis[nrow][ncol]==0){
                q.push({{nrow,ncol},dis+1});
                vis[nrow][ncol]=1;
            }
        } 
    }
    
    
    return -1;
}
