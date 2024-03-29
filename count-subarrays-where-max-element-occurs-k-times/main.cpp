class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans {};
        size_t size = nums.size();

        int max = *max_element(nums.begin(), nums.end());
        unordered_map<int, int> map;
        int j {};
        for(int i{};i<size;i++){
            map[nums[i]]++;
            while(map[max] >= k){
               ans = ans + size - i; 
               map[nums[j]]--;
               j++;
            }
        }

        return ans;
        
    }
};``
