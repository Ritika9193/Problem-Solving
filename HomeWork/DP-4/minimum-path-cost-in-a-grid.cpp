class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, vector<vector<int>>&grid, int m, int n, vector<vector<int>>& moveCost) {
        if (i == m - 1) return grid[i][j];

        if (i >= m || j >= n) return 1e9;

        if (dp[i][j] != -1) return dp[i][j];

        int res = 1e9;

        for (int k = 0; k < n; k++) {
            res = min(res, grid[i][j] + moveCost[grid[i][j]][k] + solve(i + 1, k, grid, m, n, moveCost));
        }

        return dp[i][j] = res;
    }


    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n = grid[0].size();

        dp = vector<vector<int>>(m, vector<int>(n, -1));
        int res = 1e9;

        for (int j = 0; j < n; j++) {
            res = min(res, solve(0, j, grid, m, n, moveCost));
        }

        return res;
    }
};