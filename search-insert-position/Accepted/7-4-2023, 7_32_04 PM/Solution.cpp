// https://leetcode.com/problems/search-insert-position

class Solution {
public:
    int helper(vector<int>& nums, int target){
        int start = 0;
        int end = nums.size() - 1;
        int mid = -1;
        while(start <= end){
            mid = start + (end - start) / 2;
            if (nums[mid] < target){
                start = mid + 1;
            } else if(nums[mid] == target){
                return mid;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }
    int searchInsert(vector<int>& nums, int target) {
        int index = helper(nums, target);
        if(index != -1){
            return index;
        } 
        for(int i=0;i<nums.size();i++){
            if(nums[i] > target){
                return i;
            }
            if(i == nums.size() - 1){
                return i + 1;
            }
        }
        return -1;
    
        
        
    }
};