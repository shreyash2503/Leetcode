// https://leetcode.com/problems/single-number

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        int value = 0;
        for(int i=0;i<nums.size();i++){
            if(map.find(nums[i]) == map.end()){
                map[nums[i]] = 1;
            } else {
                map[nums[i]] ++;
            }
        }
        
        for(const auto& pair : map){
            if(pair.second == 1){
                value = pair.first;
                break;
            }
        }
        return value;
    }
};