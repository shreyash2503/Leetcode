// https://leetcode.com/problems/coin-change

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        size_t size = coins.size();
        dp[0] = 0;

        for(size_t i{1};i<=amount;i++){
            for(size_t j{0};j<size;j++){
                int amount = i - coins[j];
                int ans = INT_MAX;
                if(amount >= 0 && dp[amount] != INT_MAX){
                    ans = dp[amount] + 1;
                } 
                dp[i] = min(dp[i], ans); 

            }
        }
        if(dp[amount] == INT_MAX) return -1;
        
        return dp[amount];
        
    }
};