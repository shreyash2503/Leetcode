// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum

class Solution {
public:
    int mod = 1e9+7;
    int helper(int n, int k, int target, vector<vector<int>> &dp){
        if(n == 0 && target == 0) return 1;
        if(n <= 0) return 0;
        if(dp[n][target] != -1) return dp[n][target];
        int ans {};
        for(int i{1};i<=min(k, target);i++){
            ans = (ans + helper(n - 1, k, target - i, dp)) % mod;

        }
        return dp[n][target] = ans;
    }
    int numRollsToTarget(int n, int k, int target) {
       vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1)); 
       return helper(n, k, target, dp);
    }
};