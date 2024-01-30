// https://leetcode.com/problems/squares-of-a-sorted-array

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int a = nums.size() - 1;
        int start = 0;
        int end = a;

        while(start <= end){
            if(pow(nums[start], 2) > pow(nums[end], 2) ){
                int flag = nums[start];
                int temp = nums[end];
                nums[end] = nums[start] * nums[start];
                nums[start] = temp * temp;
                end = end - 1;
                nums[start] = flag;

            } else {
                nums[end] = nums[end] * nums[end];
                end = end - 1;
            }
        }
        
        return nums;

        
    }
};