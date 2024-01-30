// https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
       int width = abs(sx - sy); 
       int height = abs(sy - fy);

       if(width == 0 && height == 0 && t == 1){
           return false;
       }
       return t >= max(width, height);
    }
};