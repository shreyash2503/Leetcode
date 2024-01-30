// https://leetcode.com/problems/predict-the-winner

class Solution {
public:
    bool helper(vector<vector<int>> &v, int left, int right, vector<int> &nums) {
    if (left > right) {
        return 0;
    }
    if (v[left][right] != -1) {
        return v[left][right];
    }

    int _left = nums[left] - helper(v, left + 1, right, nums);
    int _right = nums[right] - helper(v, left, right - 1, nums);
    v[left][right] = max(_left, _right);
    return v[left][right];
    }



    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> v(n, vector<int>(n, -1));

        return helper(v, 0, n - 1, nums) >= 0;
        
    }
};