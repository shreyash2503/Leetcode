// https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
       sort(points.begin(), points.end()); 
       int diff {};

       for(size_t i=1;i<points.size();i++){
           diff = max(diff, points[i][0] - points[i - 1][0]);
       }

       return diff;
    }
};