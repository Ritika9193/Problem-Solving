class Solution {
public:
    long solve(string& s,int i,int n,vector<long>& dp){
        long mod=1e9+7;
        if(dp[i]!=-1)return dp[i];
        if(i==n || s[i]=='0')return dp[i]=0;
        if(i==n-1){
            if(s[i]=='*')
                return dp[i]=9;
            return dp[i]=1;
        }
        long ans=0;
        if(s[i]=='*')
            ans+=solve(s,i+1,n,dp)*9;
        else
            ans+=solve(s,i+1,n,dp);

        ans%=mod;
        string num=s.substr(i,2);
        if(num=="1*"){
            if(i==n-2)return dp[i]=(ans+9)%mod;
            ans+=solve(s,i+2,n,dp)*9;
        }
        else if(num=="2*"){
            if(i==n-2)return dp[i]=(ans+6)%mod;
            ans+=solve(s,i+2,n,dp)*6;
        }
        else if(num=="**"){
            if(i==n-2)return dp[i]=(ans+15)%mod;
            ans+=solve(s,i+2,n,dp)*15;
        }
        else if(num[1]=='*'){
        }
        else if(num[0]=='*'){
            if(num[1]<='6'){
                if(i==n-2)return dp[i]=(ans+2)%mod;
                ans+=solve(s,i+2,n,dp)*2;
            }
            else{
                if(i==n-2)return dp[i]=(ans+1)%mod;
                ans+=solve(s,i+2,n,dp);
            }
        }
        else if(num<="26"){
            if(i==n-2)return dp[i]=(ans+1)%mod;
            ans+=solve(s,i+2,n,dp);
        }
        ans%=mod;
        return dp[i]=ans;
    }
    int numDecodings(string s) {
        vector<long> dp(s.length()+1,-1);
        dp[s.length()]=0;
        return solve(s,0,s.length(),dp);
        
    }
};
