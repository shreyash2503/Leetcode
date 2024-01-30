// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 1;
        size_t size = nums.size();
        vector<int> dp(size, 1);
        for(size_t i=0;i<size;i++){
            for(size_t j=0;j<i;j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1), ans = max(ans, dp[i]);
                }
            }
        }

        return ans;
        
    }
};