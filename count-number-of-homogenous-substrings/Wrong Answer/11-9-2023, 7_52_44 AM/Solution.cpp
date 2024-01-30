// https://leetcode.com/problems/count-number-of-homogenous-substrings

class Solution {
public:
    const long long mod = 1e+7;
    int countHomogenous(string s) {
        long long count = 1;
        long long  ans = 0;
        ans += 1;

        for(int i=1;i<s.length();i++){
            if(s[i] != s[i - 1]){
                count = 1;
                ans += count;
            } else {
                count ++;
                ans += count;
            }
        }
        
        return ans % mod;
        


        
    }
};