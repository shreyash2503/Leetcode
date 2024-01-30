// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    
    int helper(vector<int> nums, int key){
        int size = nums.size();
        int s = 0;
        int e = size - 1;
        while(s <= e){
            int mid = (s + e) / 2;
            if(nums[mid] == key){
                return mid;
            }
            if(nums[s] <= nums[mid]){
                if(nums[s] <= key && key < nums[mid]){
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            } else {
                if(nums[s] < key && key <= nums[e]){
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return helper(nums, target);
        
    }
};