// https://leetcode.com/problems/search-in-rotated-sorted-array-ii

class Solution {
public:
    bool helper(vector<int>& nums, int target){
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] == target){
                return true;
            }
            if(nums[l] == nums[mid] && nums[r] == nums[mid]){
                // && and not || as if we use or we are missing the condition that l and r itself can be mid
                l++;
                r--;
            } else if(nums[mid] >= nums[l]){
                if(target >= nums[l] && target <= nums[mid]){
                    r = mid - 1;
                } else {
                    l = mid + l;
                } 
            } else {
                if(target >= nums[mid] && target <= nums[r]){
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }

        return false;
    }
    bool search(vector<int>& nums, int target) {
        return helper(nums, target);
        
    }
};