// https://leetcode.com/problems/minimize-maximum-pair-sum-in-array

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;

        int minMaxPairSum = INT_MIN;

        while(left < right){
            int sum = nums[left] + nums[right];

            minMaxPairSum = max(minMaxPairSum, sum);

            left++;
            right--;
        } 
        return minMaxPairSum;
    }
};