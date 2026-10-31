class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int mod = 1e9 + 7;

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(2, 0)));

        // Start by moving right or down
        if(n > 1) dp[0][1][0] = 1;
        if(m > 1) dp[1][0][1] = 1;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0)
                    continue;

                int left = dp[i][j][0];
                int up = dp[i][j][1];

                if(grid[i][j] == 0) {
                    int total = (left + up) % mod;

                    if(j + 1 < n) {
                        dp[i][j+1][0] = (dp[i][j+1][0] + total) % mod;
                    }

                    if(i + 1 < m) {
                        dp[i+1][j][1] = (dp[i+1][j][1] + total) % mod;
                    }
                }
                else {
                    // Entering mirror from left -> move down
                    if(i + 1 < m) {
                        dp[i+1][j][1] = (dp[i+1][j][1] + left) % mod;
                    }

                    // Entering mirror from above -> move right
                    if(j + 1 < n) {
                        dp[i][j+1][0] = (dp[i][j+1][0] + up) % mod;
                    }
                }
            }
        }

        return (dp[m-1][n-1][0] + dp[m-1][n-1][1]) % mod;
    }
};