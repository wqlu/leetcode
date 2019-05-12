class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1) return 0;
        vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));
        dp[1][1] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dp[i][j] == 1)
                    continue;
                else 
                    dp[i][j] = obstacleGrid[i-1][j-1] == 1 ? 0 : (dp[i][j - 1] + dp[i - 1][j]); 
                
            }
        }
        return dp[m][n];
    }
};