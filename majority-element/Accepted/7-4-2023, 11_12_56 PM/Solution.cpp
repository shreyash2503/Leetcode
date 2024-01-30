// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int value = 0;
        unordered_map<int, int> map;
        for(int i=0;i<nums.size();i++){
            if(map.find(nums[i]) == map.end()){
                map[nums[i]] = 1;
            } else {
                map[nums[i]] ++;
            }

        }
        for(const auto& key : map){
            if(key.second > nums.size() / 2){
                value = key.first;
                break;

            }
        }
        return value;
        
        
    }
};