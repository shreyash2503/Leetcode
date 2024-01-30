// https://leetcode.com/problems/plus-one

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.size() == 1 && digits[digits.size() - 1] == 9){
            vector<int> v = {1, 0};
            return v;
        }
        if(digits[digits.size() - 1] != 9){
            digits[digits.size() - 1] += 1;
        
        } else {
            int i = digits.size() - 1;
            int carry = 1;
            while(i >= 0){
                if(digits[i] == 9 && carry == 1){
                    digits[i] = 0;
                    carry = 1;
                } else {
                    digits[i] += carry;
                    carry = 0;
                }
                i--;
                
            }
        }
        return digits;
        
    }
};