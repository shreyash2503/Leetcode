// https://leetcode.com/problems/maximum-score-after-splitting-a-string

class Solution {
public:
    int maxScore(string s) {
        int ones {};
        int zeros {};
        int best = INT_MIN;
        for(int i{};i<s.size() - 1;i++){
            if(s[i] == '1'){
                ones++;
            } else {
                zeros ++;
            }
            best = max(best, zeros - ones);
        }
        if(s[s.size() - 1] == '1'){
            ones ++;

        }
        return best + ones;

        
    }
};