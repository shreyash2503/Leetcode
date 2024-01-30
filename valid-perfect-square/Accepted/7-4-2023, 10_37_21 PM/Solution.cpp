// https://leetcode.com/problems/valid-perfect-square

class Solution {
public:
    bool isPerfectSquare(int num) {
        bool value = false;
        if(num == 1 || num == 0) return true;
        for(long long int i=2;i<num;i++){
            if(i * i == num){
                value = true;
                break;
            }
        }
        
        return value;
    }
};