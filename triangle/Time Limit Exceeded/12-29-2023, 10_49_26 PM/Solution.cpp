// https://leetcode.com/problems/triangle

class Solution {
public:
    int helper(int index, vector<vector<int>> triangle, int row){
        if(row >= triangle.size()){
            return 0;
        }
        int ans1 = helper(index, triangle, row + 1) + triangle[row][index];
        int ans2 = helper(index + 1, triangle, row + 1) + triangle[row][index];
        return min(ans1, ans2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        size_t size = triangle.size();
        int ans = helper(0, triangle, 0);
        return ans;
        
    }
};