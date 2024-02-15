class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        size_t size = nums.size();
        long long sum {};
        long long ans {-1};
        sort(nums.begin(), nums.end)
        for(auto& num : nums){
            if(sum > num){
                ans = num + sum;
            }
            sum += num;
        } 

        return ans;
    }
};
