class Solution {
public:
    int helper(vector<int>& nums, int goal){
        int start {};
        size_t size = nums.size();
        int sum {};
        int count {};

        for(int i{};i<size;i++){
            sum += nums[i];
            while(start <= i && sum > goal){
                sum -= nums[start];
                start ++;
            }
            count += (i - start + 1);
        }
        return count;

    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums, goal) - helper(nums, goal - 1);
        
    }

};
