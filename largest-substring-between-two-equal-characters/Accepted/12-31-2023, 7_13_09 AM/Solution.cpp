// https://leetcode.com/problems/largest-substring-between-two-equal-characters

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> a(26, -1);
        int max = -1;
        for(int i{};i<s.size();i++){
            if(a[s[i] - 'a'] != -1){
                if(abs(a[s[i] - 'a'] - i + 1) > max){
                    max = abs(a[s[i] - 'a'] - i + 1);
                }
                continue;
            }
            a[s[i] - 'a'] = i;
        }
        return max;
        
    }
};