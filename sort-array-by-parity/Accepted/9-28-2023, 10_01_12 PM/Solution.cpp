// https://leetcode.com/problems/sort-array-by-parity

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {

        int size = nums.size();
        int i = 0;
        int j = size - 1;

        while(i <= j){
            if(nums[i] % 2 != 0 && nums[j] % 2 == 0){
                swap(nums[i], nums[j]);
                continue;
            }
            if(nums[i] % 2 != 0 && nums[j] % 2 != 0){
                j--;
                continue;
            }
            if(nums[i] % 2 == 0 && nums[j] % 2 == 0){
                i++;
                continue;
            }
            if(nums[i] % 2 == 0 && nums[j] % 2 != 0){
                i++;
                j--;
            }

        }
        return nums;



        
    }
};