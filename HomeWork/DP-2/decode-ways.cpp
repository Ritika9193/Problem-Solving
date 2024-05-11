class Solution {
public:
int getWays(int idx, int n, string& s, vector<int>& dp) {
    if(idx >= n) return 1;
    if(s[idx] == '0') return 0;

    if(dp[idx] != -1) {
        return dp[idx];
    }
        
    int oneDigit = getWays(idx + 1, n, s, dp);
    int twoDigit = 0;
    if(idx + 1 < n) {
        int first = s[idx] - '0';
        int second = s[idx + 1] - '0';
        int combo = first * 10 + second;
        if(combo <= 26) {
            twoDigit = getWays(idx + 2, n, s, dp);
        }
    }
    return dp[idx] = oneDigit + twoDigit;
}

int numDecodings(string s) {
    int n = s.size();
    vector<int> dp(n, -1);
    return getWays(0, n, s, dp);
    }
};