class Solution{
public:
    int maxSum(int N, vector<vector<int>> mat)
    {
         vector<int> v1;
          vector<int> v2;
          
          for(int i=0;i<N;i++){
              v1.push_back(mat[0][i]);
              
          }
          for(int i=0;i<N;i++){
              v2.push_back(mat[1][i]);
          }
          vector<int> dp(N);
          dp[0]=max({v1[0],v2[0]});
          dp[1]=max({v1[1],v2[1],v1[0],v2[0]});
          for(int i=2;i<N;i++){
              dp[i]=max( { ( max({v1[i],v2[i]})+dp[i-2]  ), dp[i-1] });
          }
          return dp[N-1];
    }
};