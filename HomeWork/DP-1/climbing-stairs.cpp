// memoization  
// shows memory limit exceed error
class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        if(n<=1) return 1;       
        if(dp[n]!=-1) return dp[n];
        return dp[n] = climbStairs(n-1)+climbStairs(n-2);
    }
};

//tabulation
class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1){
            return 1;
        }
        vector<int>dp(n+1);
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};