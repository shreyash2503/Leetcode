// https://leetcode.com/problems/length-of-last-word

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i, j;
        int n = s.size();
        for(i = n - 1;i>=0;i--){
            if(s[i] != ' '){
                break;
            }
        }
        for(j=i;j>=0;j--){
            if(s[j] == ' '){
                break;
            }
        }
        return (i - j);
        
    }
};