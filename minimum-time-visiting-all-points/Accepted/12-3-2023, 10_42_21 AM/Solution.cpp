// https://leetcode.com/problems/minimum-time-visiting-all-points

class Solution {
public:
    int maxNorm(vector<int>& first, vector<int>& second){
        return max(abs(first[0] - second[0]), abs(first[1] - second[1]));
    }
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {

        int ans = 0;
        vector<int> prev = points[0];
        for(auto &P : points){
            ans += maxNorm(P, prev);
            prev = P;
        }

        return ans;
        
    }
};