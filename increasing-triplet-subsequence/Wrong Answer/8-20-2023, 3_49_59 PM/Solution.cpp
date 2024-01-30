// https://leetcode.com/problems/increasing-triplet-subsequence

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int prev = INT_MIN;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] > prev){
                prev = nums[i];
                count ++;
                if(count == 3){
                cout << count;
                return true;
                }
            }
        }
        return false;
        
    }
};