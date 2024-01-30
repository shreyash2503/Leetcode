// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> array;
        int temp;
        for(int i=0; i<nums.size(); i++){

            if (nums[i] == temp){
                array.push_back(i);
                break;
            }
            else if (temp < nums[i]) {
                continue;
            } else {
                temp = target - nums[i];
                array.clear();
                array.push_back(i);
            }

        }
        return array;
        
    }
};