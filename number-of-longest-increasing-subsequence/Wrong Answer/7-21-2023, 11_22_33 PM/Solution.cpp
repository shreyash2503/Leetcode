// https://leetcode.com/problems/number-of-longest-increasing-subsequence

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> counts(n, 1);
        int maxLength = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j]){
                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        counts[i] = counts[j];
                    } else if(dp[j] + 1 == dp[i]){
                        counts[i] = counts[j] + 1;
                    }
                }
            }
            maxLength = max(maxLength, dp[i]);
        }

        int result = 0;
        for(int i=0;i<n;i++){
            if(dp[i] == maxLength){
                result += counts[i];
            }
        }
        
        return result;
    }
};