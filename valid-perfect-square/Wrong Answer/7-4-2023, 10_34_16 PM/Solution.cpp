// https://leetcode.com/problems/valid-perfect-square

class Solution {
public:
    bool isPerfectSquare(int num) {
        bool value = false;
        for(int i=2;i<num;i++){
            if(i * i == num){
                value = true;
            }
        }
        
        return value;
    }
};