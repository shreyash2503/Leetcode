// https://leetcode.com/problems/move-zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int mid = 0;
        int start = 0;
        int end = nums.size() - 1;
        while(mid <= end){
            if(nums[mid] != 0){
                swap(nums[mid], nums[start]);
                start++;
            }
            mid++;
        }
        
    }
};