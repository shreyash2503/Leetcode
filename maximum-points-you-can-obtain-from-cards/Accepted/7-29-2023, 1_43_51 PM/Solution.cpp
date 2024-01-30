// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int l = 0;
        int r = n - k;
        int total = 0;
        for(int i=r;i<n;i++){
            total += cardPoints[i];
        }
        int res = total;

        while(r < n){
            total += (cardPoints[l] - cardPoints[r]);
            res = max(res, total);
            l++;
            r++;
        }
        
        return res;
    }
};