class Solution {
public:
    int majorityElement(vector<int>& nums) {
        size_t size = nums.size();

        unordered_map<int, int> map;
        for(auto i : nums){
            map[i]++;
        }
        for(auto &[first, second] : map) {
            if(second > (size / 2)){
                return first;
            }
        }
        return -1;
    }
};
