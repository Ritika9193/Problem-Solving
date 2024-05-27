class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
       int m=grid.size();
       int n=grid[0].size();

       vector<vector<int>> output(m, vector<int>(n,grid[m-1][n-1]));
       

       for(int i=n-2 ;i>=0;i--){
           output[m-1][i]=output[m-1][i+1]+grid[m-1][i];
       }
       for(int i=m-2; i>=0;i--){
           output[i][n-1]=output[i+1][n-1]+grid[i][n-1];
       }

       for(int i=m-2 ;i>=0;i--){
           for(int j=n-2 ;j>=0;j--){
               output[i][j]=min(output[i+1][j], output[i][j+1]) +grid[i][j];
           }
       }
       return output[0][0];
    }
};