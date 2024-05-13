class Solution {
public:
    int solve(int i,int amt,vector<int>& coins,vector<vector<int>>& dp){
        if(i==0){
             return (amt%coins[0]==0);
        }
        if(amt==0)return 1;
        if(dp[i][amt]!=-1)return dp[i][amt];
        int nott=solve(i-1,amt,coins,dp);
        int take=0;
        if(coins[i]<=amt){
            take=solve(i,amt-coins[i],coins,dp);
        
        }
        return dp[i][amt]=nott+take;
    }
    int change(int amount, vector<int>& coins) {
        int n= coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans= solve(n-1,amount,coins,dp);   
         return ans;
    }
};