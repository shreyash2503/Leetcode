// https://leetcode.com/problems/plus-one

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits[digits.size() - 1] != 9){
            digits[digits.size() - 1] += 1;
        
        } else {
            int i = digits.size() - 1;
            int carry = 1;
            vector<int> v;
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
            if(carry == 1){
               
                v.push_back(1);
                for(int i=0;i<digits.size();i++){
                    v.push_back(digits[i]);
                }
                return v;
            }
            
        }
        return digits;
        
        
        
    }
};