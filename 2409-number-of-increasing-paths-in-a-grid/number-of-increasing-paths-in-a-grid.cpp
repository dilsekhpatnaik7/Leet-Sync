class Solution {
public:
    int mod = 1e9 + 7;
    bool isValid(int row, int col, int nrow, int ncol, int n, int m, vector<vector<int>>& grid) {
        return nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] > grid[row][col];
    }

    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp, int& n, int& m) {
        if(dp[row][col] != -1) return dp[row][col];

        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        long long ans = 1;
        for(int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if(isValid(row, col, nrow, ncol, n, m, grid)) ans += dfs(nrow, ncol, grid, dp, n, m);
        }

        return dp[row][col] = ans % mod;
    }

    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        long long ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans += dfs(i, j, grid, dp, n, m);
            }
        }
        return ans % mod;
    }
};