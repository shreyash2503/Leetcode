// https://leetcode.com/problems/sqrtx

class Solution {
public:
    int mySqrt(int x) {
        if(x == 1){
            return 1;
        }
        if(x == 0){
            return 0;
        }
        int start = 1;
        int end = x;
        int mid =-1;
        while(start <= end){
            mid = start + (end - start) / 2;
            long long square = static_cast<long long>(mid) * mid;
            if (square > x){
                end = mid - 1;
            } else if(square < x){
                start = mid + 1;
            } else if(square == x){
                return mid;
            }
        }
        return static_cast<int>(std::round(end));

        
    }
};