// https://leetcode.com/problems/count-number-of-homogenous-substrings

# pragma GCC optimize("03")
class Solution {
public:
    const long long mod = 1e+7;
    int countHomogenous(string s) {
        char prev = 'X';
        int count = 0;
        long long ans = 0;
        for(auto c : s){
            if(c != prev){
                ans = (ans + (long long)count * (count + 1) / 2 % mod);
                count = 1;
            } else {
                count ++;
            }
            prev = c;
        }

        ans = (ans + (long long) count * (count + 1) / 2 % mod);
        return ans;



        
    }
};