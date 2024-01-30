// https://leetcode.com/problems/coin-change

class Solution {
public:
   
    int coinChange(vector<int>& coins, int amount) {
      
      vector<int> dp(amount + 1, INT_MAX - 1);
      dp[0] = 0;
      for(int coin : coins){
          for(int i=1;i<dp.size();i++){
              if(i >= coin){
                dp[i] = min(dp[i], dp[i - coin] + 1);
              }
          }
      }

      return dp[amount] == INT_MAX - 1 ? -1 : dp[amount];
       
        
        
    }
};