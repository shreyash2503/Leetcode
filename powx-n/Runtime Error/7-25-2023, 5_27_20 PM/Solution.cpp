// https://leetcode.com/problems/powx-n

class Solution {
public:

    double helper(double x, int n){
        int count = 0;
        double ans = 1;
        while(count < n){
            ans *= x;
            count ++;
        }
        return ans;
    }
    double myPow(double x, int n) {
        double ans = 0;
        if(x == 1){
            return 1;
        }
        if(n > 0){
            ans = helper(x, n);
        } else {
            long long l = -1 * n;
            ans = helper(1 / x, l);
        }
        return ans;
    }
};