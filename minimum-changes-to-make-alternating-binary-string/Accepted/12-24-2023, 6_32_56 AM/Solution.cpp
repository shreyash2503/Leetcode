// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string

class Solution {
public:
    int minOperations(string s) {
        int count0 {};
        int count1 {};

        for(int i{};i<s.length();i++){
            if(i % 2 == 0){
                if(s[i] != '0'){
                    count0++;
                } else {
                    count1++;
                }
            } else {
                if(s[i] != '1'){
                    count0 ++;
                } else {
                    count1 ++;
                }
            }
        }
        return min(count1, count0);

        
    }
};