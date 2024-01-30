// https://leetcode.com/problems/ugly-number

class Solution {
public:
    bool isPrime(int n){
        for(int i=2;i<n;i++){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }
    bool isUgly(int n) {
        if(n <= 0){
            return false;
        }
        
        for(int i=2;i<n;i++){
            if(n % i == 0 && i > 5 && isPrime(i)){
                return false;
            }
        }
        
        return true;
    }
};