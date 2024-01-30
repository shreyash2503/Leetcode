// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {

        int num = x;
        string ans = "";
        int flag = 0;
        if(num < 0){
            num = num * -1;
            flag = 1;
        }

        while(num > 0){
            int remainder = num % 10;
            ans += to_string(remainder);
            num = num / 10;
        }
        int temp = stoi(ans);
        if(flag == 1){
            temp = temp * -1;
        }
        if(temp > numeric_limits<int>::min() && temp < numeric_limits<int>::max()){
            return temp;
        } 
        return 0;
        
    }
};