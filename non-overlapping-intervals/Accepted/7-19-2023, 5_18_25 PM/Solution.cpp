// https://leetcode.com/problems/non-overlapping-intervals

class Solution {
public:
    static bool customFunc(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), customFunc);

        int prev = 0;
        int count = 1;
        for(int i=1;i<intervals.size();i++){
            if(intervals[prev][1] <= intervals[i][0]){
                prev = i;
                count++;
            }
        }
        return intervals.size() - count;
        
    }
};