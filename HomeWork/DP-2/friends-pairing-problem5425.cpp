class Solution
{
    public:
    
    int mod=1000000007;
    
    long long solve(int i,vector<long long>& dp)
    {
        if(i==1 or i==2)
        return i;
        if(dp[i]!=-1)
        return dp[i];
        long long a=solve(i-1,dp)%mod;
        long long b=((i-1)*(solve(i-2,dp)%mod))%mod;
        
        return dp[i]=(a+b)%mod;
    }
    int countFriendsPairings(int n) 
    { 
        vector<long long> dp(n+1,-1); 
        return solve(n,dp);
    }
};      