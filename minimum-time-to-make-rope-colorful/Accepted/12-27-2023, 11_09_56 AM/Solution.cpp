// https://leetcode.com/problems/minimum-time-to-make-rope-colorful

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int prev {};
        int sum {};
        for(size_t i {1};i<colors.size();i++){
            if(colors[prev] != colors[i]){
                prev = i;
            } else {
                if(neededTime[prev] < neededTime[i]){
                    sum += neededTime[prev];
                    prev = i;
                } else {
                    sum += neededTime[i];
                }
            }
        }        
        return sum;
    }
};