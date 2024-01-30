// https://leetcode.com/problems/next-permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i - 1] < nums[i]){
                // if(i == nums.size() - 1){
                //     swap(nums[i - 1], nums[i]);
                //     continue;
                // }
                swap(nums[i - 1], nums[i]);
                break;
                
            }
        }
        
    }
};