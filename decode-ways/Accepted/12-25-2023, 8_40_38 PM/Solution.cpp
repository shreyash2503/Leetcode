// https://leetcode.com/problems/decode-ways

class Solution {
public:
    int numDecodings(string s) {
        if(s.length() == 0 || s == "0"){
            return 0;
        }
        size_t size = s.length(); 
        vector<int> dp(size + 1, 0);
        dp[0] = 1;
        if(s[0] != '0'){
            dp[1] = 1;
        } else {
            return 0;
        }
        for(size_t i{2};i<=size;i++){
            if(s[i - 1] != '0'){
                dp[i] += dp[i - 1];
            }
            if(s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')){
                dp[i] += dp[i - 2];

            }

        }
        return dp[size];
    }
};