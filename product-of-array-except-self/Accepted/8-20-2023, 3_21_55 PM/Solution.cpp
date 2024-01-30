// https://leetcode.com/problems/product-of-array-except-self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int>v1(nums.size(), 1);
        vector<int>v2(nums.size(), 1);

        for(int i=1;i<nums.size();i++){
           v1[i] = v1[i - 1] * nums[i - 1];
        }
        for(int i=nums.size() - 2;i>=0;i--){
            v2[i] = v2[i + 1] * nums[i + 1]; 
        }
        for(int i=0;i<nums.size();i++){
            nums[i] = v1[i] * v2[i];
        }
        return nums;



        
    }
};