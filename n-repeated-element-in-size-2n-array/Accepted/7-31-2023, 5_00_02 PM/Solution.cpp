// https://leetcode.com/problems/n-repeated-element-in-size-2n-array

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int z = nums.size();
        int n = z / 2;
        int flag = 0;
        unordered_map<int, int> map;
        for(int i=0;i<nums.size();i++){
            if(map.find(nums[i]) == map.end()){
                map[nums[i]] = 1;
            } else {
                map[nums[i]] ++;
            }
        }
        for(const auto& pair : map){
            if(pair.second == n){
                flag = pair.first;

            }
        }

        return flag;
    }
};