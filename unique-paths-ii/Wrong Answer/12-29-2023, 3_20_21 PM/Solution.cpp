// https://leetcode.com/problems/unique-paths-ii

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        size_t m = obstacleGrid.size();
        size_t n = obstacleGrid[0].size();
        if(m == 1 && n == 1 && obstacleGrid[m - 1][n - 1] == 0){
            return 1;
        }
        if(m == 1 && n == 1 && obstacleGrid[m - 1][n - 1] == 1){
            return 0;
        }

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(size_t i{};i<m;i++){
            for(size_t j{};j<n;j++){
                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                    continue;
                }
                if(i == 0 && j > 0){
                    if(obstacleGrid[i][j] != 1){
                        dp[i][j] = 1;
                    }
                } else if(i > 0 && j >= 1 && obstacleGrid[i][j] != 1){
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                } else {
                    if(obstacleGrid[i][j] != 1){
                        dp[i][j] = dp[i - 1][j];
                    }
                }

            }
        }
        return dp[m - 1][n - 1];
        
    }
};