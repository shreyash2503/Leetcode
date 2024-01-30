// https://leetcode.com/problems/minimum-path-sum

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        size_t m = grid.size();
        size_t n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(size_t i{};i<m;i++){
            for(size_t j{};j<n;j++){
                if(i == 0 && j == 0){
                    dp[i][j] = grid[i][j];
                    continue;
                }
                if(i == 0 && j > 0){
                    dp[i][j] = grid[i][j] + dp[i][j - 1];
                    continue;
                }
                if(j >= 1){
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                } else {
                    dp[i][j] = dp[i - 1][j] + grid[i][j];
                }
            }

        }
        return dp[m - 1][n - 1];

        
    }
};