// https://leetcode.com/problems/powx-n

class Solution {
public:

    double helper(double x, long long n){
     if(n == 0){
         return 1;
     }
     if(n < 0){
         return 1.0 / helper(x, -n);
     }
     if(n % 2 == 1){
        return x * helper(x * x, (n - 1) / 2);
     } else {
        return helper(x * x, n / 2);
     }
    }
    double myPow(double x, int n) {
        return helper(x * x, static_cast<long>(n));
       
    }
};