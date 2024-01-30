// https://leetcode.com/problems/next-permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i - 1] < nums[i]){
                reverse(nums.begin() + i, nums.end());
                swap(nums[i - 1], nums[i]);
                return;
            }
        }
        sort(nums.begin(), nums.end());
        
    }
};