// https://leetcode.com/problems/largest-3-same-digit-number-in-string

class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        string largestString = "";
        for (int i=0;i<num.size();i++){
            int j = i + 1;
            int k = j + 1;

            if (k < num.size() && num[i] == num[j] && num[j] == num[k]){
                ans += num[i];
                ans += num[j];
                ans += num[k];
                largestString = max(ans, largestString);
                ans = "";
            }
        }

        return largestString;
       
    }
};