class Solution {
public:
    int solve(vector<int>&arr,int ind,vector<int>&dp){
        if(ind>=arr.size()-1)return 0;
        if(dp[ind]!=10001)return dp[ind];
        for(int i=1;i<=arr[ind];i++){
            dp[ind]=min(dp[ind],1+solve(arr,i+ind,dp));
        }
        return dp[ind];
    }
    int jump(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n+1,10001);
        return solve(arr,0,dp);
    }
};