// https://leetcode.com/problems/next-permutation

class Solution {
public:
    static bool comparator(int a, int b){
        return a > b;
    }
    void nextPermutation(vector<int>& nums) {
        vector<int> temp;
        for(int i=0;i<nums.size();i++){
            temp.push_back(nums[i]);
        }
        sort(temp.begin(), temp.end(), comparator);
        if(equal(nums.begin(), nums.end(), temp.begin())){
            sort(nums.begin(), nums.end());
            return;
        }

        for(int i=nums.size()-1;i>0;i--){
            if(nums[i - 1] < nums[i]){
                // if(i == nums.size() - 1){
                //     swap(nums[i - 1], nums[i]);
                //     continue;
                // }
                swap(nums[i - 1], nums[i]);
                break;
                
            }
        }
        
    }
};