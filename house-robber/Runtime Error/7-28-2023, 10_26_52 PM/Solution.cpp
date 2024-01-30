// https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp[n  + 1];
        for(int i=0;i<=n;i++){
            dp[i] = 0;
        }

        dp[0] = nums[0];
        dp[1] = nums[1];
        for(int i=2;i<n;i++){
            for(int j=i-2;j>=0;j--){
                dp[i] = max(dp[i], nums[i] + dp[j]);
            }
        }

        int max = INT_MIN;
        for(int i=0;i<=n;i++){
            if(dp[i] > max){
                max = dp[i];
            }
        }
        
        return max;
    }
};