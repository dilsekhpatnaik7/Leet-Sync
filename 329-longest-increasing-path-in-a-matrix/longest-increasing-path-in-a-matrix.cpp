class Solution {
public:
    bool isValid(int row, int col, int nrow, int ncol, int n, int m, vector<vector<int>>& matrix) {
        return nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && matrix[nrow][ncol] > matrix[row][col];
    }

    int dfs(int row, int col, int n, int m, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if(dp[row][col] != -1) return dp[row][col];

        int ans = 1;
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};

        for(int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if(isValid(row, col, nrow, ncol, n, m, matrix)) {
                ans = max(ans, 1 + dfs(nrow, ncol, n, m, matrix, dp));
            }
        }

        return dp[row][col] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int ans = 1;

        vector<vector<int>> dp(n, vector<int>(m, - 1));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans = max(ans, dfs(i, j, n, m, matrix, dp));
            }
        }
        return ans;
    }
};