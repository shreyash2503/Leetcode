// https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;

        for(auto i : left){
            ans = max(ans, abs(0 - i));
        }

        for(auto i : right){
            ans = max(ans, abs(n - i));
        }

        return ans;
        
    }
};